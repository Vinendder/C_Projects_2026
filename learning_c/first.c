#include <stdio.h>
#include <math.h>

int main(){
    
    // Input variables
    float number_1 = 0.0f;
    float number_2 = 0.02f;
    char operation = '\0';

    // User input
    printf("Please enter the first number: \n");
    scanf("%f", &number_1);

    printf("Enter the operation: \n");
    printf("+ -> Addition \n - -> subtraction \n * -> multiply \n / -> divide\n" );
    scanf(" %c", &operation);

    printf("Enter the second number: \n");
    scanf("%f", &number_2);

    // Calculation
    switch(operation){
        case '+': 
            printf("%.2f + %.2f = %.2f\n", number_1, number_2, number_1 + number_2);
            break;

        case '-':
            printf("%.2f - %.2f = %.2f\n", number_1, number_2, number_1 - number_2);
            break;

        case '*':
            printf("%.2f x %.2f = %.2f\n", number_1, number_2, number_1 * number_2);
            break;

        case '/':
            printf("%.2f / %.2f = %.2f\n", number_1, number_2, number_1 / number_2);
            break;
        
        default:
            printf("Type valid operation"); // Guard code
            break;

    }

    return 0;

}