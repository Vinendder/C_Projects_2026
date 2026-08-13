#include <stdio.h>
#include <stdlib.h>

// Functions used
void CheckBalance(float AccBalance);
float Withdraw(float AccBalance);
float Deposit(float AccBalance);

int main(){

    int OnOff = 1;
    float AccBalance = 0.0f;

    do{ // Main loop
        int choice = 0;

        do{ // Secondary loop to check user input
            printf("What do you want to do?:\n");
            printf("1. Check Balance\n");
            printf("2. Deposit Money\n");
            printf("3. Withdraw Money\n");
            printf("0. Exit Program\n");
    
            if (scanf("%d", &choice) != 1){ // guard for abc
                while(getchar() != '\n');
                choice = 0;
            }
    
        }while(choice < 0 || choice > 3);

        switch(choice){ // Matching user input with functions
            case 1: 
                CheckBalance(AccBalance);
                break;
            case 2:
                AccBalance = Deposit(AccBalance);
                break;
            case 3:
                AccBalance = Withdraw(AccBalance);
                break;
            case 0:
                OnOff = 0;
                break;
        }

    
    }while(OnOff == 1);

    printf("Thanks for using!\n");
    return 0;

}
void CheckBalance(float AccBalance){  // Check balance 
    float Balance = AccBalance;
    printf("Your Balance is: %.2f\n", Balance);
}

float Deposit(float AccBalance){ // Deposit Money
    float money;

    printf("Enter the amount which you want to deposit: ");
    if(scanf("%f", &money) != 1){ 
        while(getchar() != '\n');
        printf("Invalid Input\n");
        return AccBalance;
    }

    if(money <= 0){ // Guard code
        printf("Invalid Amount\n");
    }
    else{
        AccBalance += money;
    }
    return AccBalance;
}

float Withdraw(float AccBalance){ // Withdraw money
    float money = 0;

    printf("Enter the amount which you want to withdraw: ");
    if(scanf("%f", &money) != 1){
        while(getchar() != '\n');
        printf("Invalid Input\n");
        return AccBalance;
    }

    if(money > AccBalance){ // Guard code
        printf("Insufficent Funds!\n");
    }
    else if(money <= 0){
        printf("Invalid Amount\n");
    }
    else{
        AccBalance -= money;
    }
    return AccBalance;

}