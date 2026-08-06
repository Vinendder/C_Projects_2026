#include <stdio.h>
#include <math.h>

int main(){
    
    // Variables for Temperature
    char choice = '\0';
    float Fahrenheit = 0.0f;
    float Celsius = 0.0f;

    // User input
    printf("Choose one conversion between the following: \n");
    printf("C. Fahrenheit to Celsius.\n");
    printf("F. Celsius to Fahrenheit.\n");
    printf("Type 'C' or 'F' \n");
    scanf(" %c", &choice);

    // Conversion Based on Choice
    if(choice == 'C'){
        printf("Type the temperature in Fahrenheit: \n");
        scanf("%f", &Fahrenheit);
        Celsius = (Fahrenheit - 32) * (5.0f/9);
        printf("The temperature in Celsius is %.1f °C\n", Celsius);
    }
    else if(choice == 'F'){
        printf("Type the temperature in Celsius: \n");
        scanf("%f", &Celsius);
        Fahrenheit = (Celsius * (9.0f/5) + 32);
        printf("The temperature in Fahrenheit is %.1f °F\n", Fahrenheit);
    }
    else{
        printf("Type Valid Choice (C or F)\n"); // Guard code
    }

}