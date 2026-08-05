#include <stdio.h>
#include <math.h>

int main(){

    // All variables 
double radius = 0.0;
double area = 0.0;
double volume = 0.0;
double surface_area = 0.0;
const double Pi = 3.14159;

// User input
printf("Enter the radius of circle: ");
scanf("%lf", &radius);

// Calculations
area = Pi * pow(radius, 2);
volume = (4/3) * Pi * pow(radius, 3);
surface_area = 4 * Pi * pow(radius, 2);

//Print statements
printf("Area of circle = %.2lf units.\n", area);
printf("Volume of sphere of same radius = %.2lf units.\n", volume);
printf("Surface area of sphere of same radius = %.2lf units.\n", surface_area);


}