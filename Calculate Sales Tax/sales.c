//Deone'Ta Levy
//Calculating sales tax.


#include <stdio.h>
#include <math.h>

int main() {
   float price, tax;
   float final_price;

   printf("What is the price of the item?\n");
   scanf("%f", &price);

   printf("What is the sales tax in your county?\n");
   scanf("%f", &tax);

   final_price = ((tax/100)*price)+price; //This changes the percentage into a decimal then computes the final price.

   printf("Your total is $%.2f.\n", final_price); //%.2f rounds the number to two decimal places.

   return 0;


}
