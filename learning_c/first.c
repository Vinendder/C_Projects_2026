#include <stdio.h>
#include <stdbool.h>

int main(){
    
    // Variables
    int age = 0;
    int college_year = 0;
    float price_item = 0.0f;
    bool IsStudent = false;
    bool IsSenior = false;

    // Inputs to check conditions
    printf("Please enter your age: \n");
    scanf("%d", &age);
    printf("Please enter your college year: \n");
    scanf("%d", &college_year);
    printf("Please enter price of item: \n");
    scanf("%f", &price_item);

    // Checking and assigning conditions
    if(age >= 18 && 4 > college_year && college_year >= 3){
        IsStudent = true;
        IsSenior = true;
    }   
    else if(age >= 18 && college_year < 3){
        IsStudent = true;
        IsSenior = false;
    }
    else if(age < 18 && 4 > college_year && college_year >= 3){
        IsStudent = false;
        IsSenior = true;
    }
    else{
        IsStudent = false;
        IsSenior = false;
    }


    // Checking conditions
    if(IsStudent){
        if(IsSenior){
            printf("You get a Student and Senior discount of 30%%\n");
            price_item *= 0.7;
            printf("Your item cost is %.2f\n", price_item) ;
        }
        else{
            printf("You get a Student discount of 10%%\n");
            price_item *= 0.9;
            printf("Your item cost is %.2f\n", price_item);
        }
    }
    else{
        if(IsSenior){
            printf("You get a Senior discount of 20%%\n");
            price_item *= 0.8;
            printf("Your item cost is %.2f\n", price_item);
        }
        else{
            printf("You get not discount\n");
            printf("You item cost is %.2f\n", price_item);
        }
    }

}