#include <stdio.h>
#include <math.h>

int main(){

double final_amount = 0.0;
double principal_amount = 0.0;
double rate_interest = 0.0;
double compound_interest = 0.0;
int years = 0;
int num_compounds = 0.0;

printf("Enter Initial Investment: ");
scanf("%lf", &principal_amount);

printf("Enter rate of interest: ");
scanf("%lf", &rate_interest);
rate_interest = rate_interest / 100;

printf("Enter number of years: ");
scanf("%d", &years);

printf("Enter number of compounds per year: ");
scanf("%d", &num_compounds);

double ToPower = 1 + (rate_interest / num_compounds);
double PowerValue = pow(ToPower, (num_compounds * years));
final_amount = principal_amount * PowerValue;
compound_interest = final_amount - principal_amount;

printf("After %d years, your final amount will be: %.2lf\n", years, final_amount);
printf("Your total compound interest is: %.2lf\n", compound_interest);

}