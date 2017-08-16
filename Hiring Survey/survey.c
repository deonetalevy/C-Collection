//Deone'Ta Levy
//Hiring Survey. Determine employee fit based on results

#include <stdio.h>

int main() {

char previous_work, sales_exp, like_games; //Variables for whether or not there is previous work experience, sales experience, and whether or not they like games
int months_exp; //Months of experience
char X, Y; //Characters for Yes and No


printf("Have you previously worked in a game store?\n");
scanf(" %c", &previous_work); //Receive user input


printf("Do you have any experience in sales?\n");
scanf(" %c", &sales_exp); //Receive user input


if (sales_exp = Y) //If the applicant has sales experience then apply this line code
    printf("How many months of experience do you have?\n");
    scanf(" %d", months_exp); //Receive user input on the amount of experience



printf("Do you like video games?\n");
scanf(" %c", &like_games); //Does the user like video games?


if (previous_work == Y && like_games == Y || months_exp >= 3 && like_games)
    printf("You are a good fit for UCF games!\n");
//If applicant has previous work experience and likes games, or if they have more than 3 months experience and they like games, then previous line is executed.
else
    printf("You do not seem like a good fit for UCF games.\n");
//Execute the previous line if nothing else applies

return 0;
}
