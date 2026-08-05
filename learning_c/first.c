#include <stdio.h>
#include <string.h>

int main(){

char item_name[50] = "";
float price_item = 0.0f;
int number_item = 0;
float total_price = 0;

printf("What item would you like to buy?: ");
fgets(item_name, sizeof(item_name), stdin);
item_name[strcspn(item_name, "\n")] = '\0';

printf("What is the price of item?: ");
scanf("%f", &price_item);

printf("What is the quantity of item?: ");
scanf("%d", &number_item);

total_price = price_item * number_item;

printf("Your total bill for %d %s is %.2f\n", number_item, item_name, total_price);
printf("Thank you for your purchase!\n");



}