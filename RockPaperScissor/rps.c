#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Functions
int GetUserInput();
int GetComputerChoice();
void CheckWinner(int UserInput, int ComputerChoice);

int main(){
    srand(time(NULL)); // Random number of computer

    int PlayAgain; // Check if User wants to play again

    do{
        int UserInput = GetUserInput();
        int ComputerChoice = GetComputerChoice();

        switch(UserInput){
        case 1:
        printf("You Choose Rock!\n");
        break;
        case 2:
        printf("You Choose Paper!\n");
        break;
            case 3:
        printf("You Choose Scissors!\n");
        break;
         }

        switch(ComputerChoice){
        case 1:
        printf("Computer Choose Rock!\n");
        break;
        case 2:
        printf("Computer Choose Paper!\n");
        break;
        case 3:
        printf("Computer Choose Scissors!\n");
        break;
        }

        CheckWinner(UserInput, ComputerChoice);

        printf("Play again? 1 -> Yes, 0 -> No\n");
        scanf("%d", &PlayAgain);

    }while(PlayAgain == 1);

    printf("Thanks for playing!\n");
    return 0;
}

int GetUserInput(){ // Taking User choice

    int choice = 0;

    do{
    printf("Type your Choice:\n");
    printf("1 -> Rock\n");
    printf("2 -> Paper\n");
    printf("3 -> Scissors\n");
    printf("0 -> Exit Program\n");
    scanf("%d", &choice);

        }while(choice < 0 || choice > 3);

    if(choice == 0){
    printf("Left the game successfully!\n");
    exit(0);
    }

    return choice;
}

int GetComputerChoice(){ // Computer choice between 0 and 4 (integer values)
    return (rand() % 3 + 1);
}

void CheckWinner(int UserInput, int ComputerChoice){ // Checking result

    if(UserInput == ComputerChoice){
    printf("It's a Tie\n");
    }
    else if(UserInput == 1 && ComputerChoice == 3){
    printf("You Win!\n");
    }
    else if(UserInput == 2 && ComputerChoice == 1){
    printf("You Win!\n");
    }
    else if(UserInput == 3 && ComputerChoice == 2){
    printf("You Win!\n");
    }
    else{
    printf("You Lose!\n");
    }
}