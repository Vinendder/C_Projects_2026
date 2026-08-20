#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define Paddle_Height 4
#define Frame_Delay_US 20000 // 25 frames per second
#define Winning_Score 11

typedef struct {
    int y;  // Top of paddle
    int x;  // Fixed column
    int score;
} Paddle;

typedef struct {
    float y, x;   // Position of ball
    float dy, dx; // Velocity
} Ball;

static int height, width;

void init_screen(void) {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    nodelay(stdscr, TRUE);
    timeout(0);
    getmaxyx(stdscr, height, width);

    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_WHITE, COLOR_BLACK);
        init_pair(2, COLOR_YELLOW, COLOR_BLACK);
        init_pair(3, COLOR_CYAN, COLOR_BLACK);
    }
}

void reset_ball(Ball *ball, int direction){
    ball -> y = height / 2.0f;
    ball -> x = width / 2.0f;
    ball -> dy = (rand() % 5 - 2) * 0.5f;
    if (ball -> dy ==0) ball ->dy = 0.5f;
    ball -> dx = 0.7f * direction;
}

void draw_border(void){
    attron(COLOR_PAIR(1));
    for (int x = 0; x < width; x++){
        mvaddch(0, x, '-');
        mvaddch(height - 1, x, '-');
    }
    for (int y =0; y < height; y ++){
        mvaddch(y,0, '|');
        mvaddch(y, width - 1, '|');
    }

    for (int y = 1; y < height -1; y +=2){
        mvaddch(y, width / 2, ':');
    }
    attroff(COLOR_PAIR(1));
}

void draw_paddle(Paddle *p, int color){
    attron(COLOR_PAIR(color));
    for (int i = 0; i < Paddle_Height; i++){
        int y = p -> y + i;
        if(y > 0 && y < height -1){
            mvaddch(y, p->x, ACS_CKBOARD);
        }
    }
    attroff(COLOR_PAIR(color));
}

void draw_score(Paddle *player, Paddle *cpu){
    mvprintw(0, width / 2-8, "%d", player -> score);
    mvprintw(0, width / 2+5, "%d", cpu -> score);
}

void clamp_paddle(Paddle *p){
    if (p->y < 1) p ->y = 1;
    if (p ->y + Paddle_Height > height -1) p->y = height - 1 - Paddle_Height;
}

int main(void){
    srand((unsigned int) getpid());
    init_screen();
    if (height < 12 || width < 30){
        endwin();
        fprintf(stderr, "Terminal window is too small. Please resize to atleast 30x12 and try again\n");
        return 1;
    }

    Paddle player = {height / 2 - Paddle_Height / 2, 2, 0};
    Paddle cpu = {height / 2 - Paddle_Height / 2, width - 3, 0};
    Ball ball;
    reset_ball(&ball, (rand() % 2 ==0) ? 1 : -1);

    int running = 1;
    char message[64] = "";

    while (running) {
        // Input
        int ch;
        while ((ch = getch()) != ERR){
            if (ch == 'q' || ch == 'Q'){
                running = 0;
            }
            else if (ch == KEY_UP){
                player.y -= 4;
            }
            else if (ch == KEY_DOWN){
                player.y += 4;
            }
        }
        clamp_paddle(&player);

        // Cpu tracks the ball with very little delay
        float cpu_center = cpu.y + Paddle_Height / 2.0f;
        float target = ball.y;
        if (cpu_center < target - 0.5f) cpu.y += 1;
        else if (cpu_center > target + 0.5f) cpu.y -=1;
        clamp_paddle(&cpu);

        // Move ball
        ball.y += ball.dy;
        ball.x += ball.dx;

        // Bounce off top/bottom walls
         if (ball.y <= 1) {
            ball.y = 1;
            ball.dy = -ball.dy;
            ball.dy = ball.dy * 1.05f;
        } 
        else if (ball.y >= height -2){
            ball.y = height - 2;
            ball.dy = -ball.dy;
            ball.dy = ball.dy * 1.05f;
        }

        // Bounce off players' paddle
        float prev_x_player = ball.x - ball.dx;
        if(ball.dx < 0 &&
            prev_x_player >= player.x + 1 &&
            (int)ball.x <= player.x + 1 &&
            ball.y >= player.y && 
            ball.y < player.y + Paddle_Height){
            ball.x = player.x + 1;
            ball.dx = -ball.dx * 1.25f; // Speed up on hit
            float hit_pos = (ball.y - player.y) / (float)Paddle_Height;
            ball.dy = (hit_pos - 0.5f) * 1.5f;
        }

        // Bounce off cpu paddle
        float prev_x_cpu = ball.x - ball.dx;
        if(ball.dx > 0 &&
            prev_x_cpu <= cpu.x - 1 &&
            (int)ball.x >= cpu.x - 1 &&
            ball.y >= cpu.y && 
            ball.y < cpu.y + Paddle_Height){
            ball.x = cpu.x - 1;
            ball.dx = -ball.dx * 1.25f; // Speed up on hit
            float hit_pos = (ball.y - cpu.y) / (float)Paddle_Height;
            ball.dy = (hit_pos - 0.5f) * 1.5f;
        }

        // Scoring
        if (ball.x < 1){
            cpu.score++;
            reset_ball(&ball, 1);
        }
        else if (ball.x > width -2){
            player.score++;
            reset_ball(&ball,-1);
        }

        if (player.score >= Winning_Score){
            strcpy(message, "You win! press q to quit.");
            running = 0;
        }
        else if (cpu.score >= Winning_Score){
            strcpy(message, "You Lose! press q to quit.");
            running = 0;
        }

        // Draw;
        erase();
        draw_border();
        draw_score(&player, &cpu);
        draw_paddle(&player, 2);
        draw_paddle(&cpu, 3);

        attron(COLOR_PAIR(1));
        mvaddch((int)ball.y, (int)ball.x, 'O');
        attroff(COLOR_PAIR(1));

        mvprintw(height - 1, 2, "Up/Down = move | q = quit ");
        refresh();

        usleep(Frame_Delay_US);
    }

    // Show final message briefly if game ended by winning
    if(strlen(message) > 0){
        nodelay(stdscr, FALSE);
        mvprintw(height / 2, (width - (int)strlen(message)) / 2, "%s", message);
        refresh();
        while(getch() != 'q'){
            // wait for quit
        }
    }
    
    endwin();
    return 0;
}