#include <stdio.h>
#include <stdlib.h> // Files
#include <time.h>
#include <unistd.h>

int main(void){


    srand(time(NULL)); // Main seed

    // User info
    int guess = 0;
    int tries = 0;

    // Range of number
    int min = 1;
    int max = 100;

    int answer = (rand() % max - min + 1) + 1; // Formula

    // Loop for game
    do{
        printf("Guess a number between %d - %d: ", min, max);
        scanf("%d", &guess);

        if (guess < answer){
            usleep(500 * 1000); // Delay to make more clean
            printf("Guess higher\n");
            tries++;
        }

        else if (guess > answer){
            usleep(500 * 1000);
            printf("Guess lower\n");
            tries++;
        }

        else{
            usleep(500 * 1000);
            printf("You guessed the correct number!\n");
            tries++;
        }
    }while(guess != answer);

    printf("You took %d tries!\n", tries);


}