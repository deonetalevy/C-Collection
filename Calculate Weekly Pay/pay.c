//Deone'Ta Levy
//Calculate Weekly Pay

#include <stdio.h>
#include <math.h>
//Define variables
#define OVERTIME_RATE 1.5
#define REGULAR_WEEK 40

int main() {

double hourly_pay, week_pay; //Variables for the hourly pay rate and how much the user will get payed.
int emp_or_man, hours_worked; // Variables for whether the user is an employee or manager and the amount of hours worked fot the week

printf("Are you an hourly employee(1) or a manager(0)?\n");
scanf(" %d", &emp_or_man);

printf("How many hours did you work this week?\n");
scanf(" %d", &hours_worked);

printf("What is your hourly pay rate?\n");
scanf(" %lf", &hourly_pay);

if (emp_or_man == 0) //If the user is a manager then the following formula is used to calculate their weekly pay
    week_pay = hourly_pay * 50;

else if (hours_worked <= REGULAR_WEEK) //If the user is a regular employee and they work less than 40 hours then the following is executed
    week_pay = hourly_pay * hours_worked;

else //If the user is a regular employee and works more than 40 hours then the following is executed
    week_pay = hourly_pay*REGULAR_WEEK + OVERTIME_RATE*hourly_pay*(hours_worked - REGULAR_WEEK);

printf("You will get paid $%.2lf this week.\n", week_pay);

return 0;

}
