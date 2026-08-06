#include <stdio.h>
#include <math.h>

int main(){

    // Variables used
    int option = 0;
    float pounds = 0.0f;
    float kilograms = 0.0f;

    // Choices
    printf("Choose between the following conversions: \n");
    printf("1. Kilograms to pounds\n");
    printf("2. Pounds to kilograms\n");
    printf("Type 1 or 2.\n");
    scanf("%d", &option);

    // Calculation on choice
    if(option == 1){
        printf("Type weight in kilograms: \n");
        scanf("%f", &kilograms);
        pounds = kilograms * 2.20462;
        printf("The weight in pounds is: %.2f lbs\n", pounds);
    }
    else if(option ==2){
        printf("Type weight in pounds: \n");
        scanf("%f", &pounds);
        kilograms = pounds / 2.20462;
        printf("The weight in pounds is: %.2f kgs\n", kilograms);
    }
    else{
        printf("Type valid option. (Option 1 or 2)\n"); // Guard code
    }
}