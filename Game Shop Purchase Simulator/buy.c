//Deone'Ta Levy
//Video Game Shop Purchase Simulator

#include <math.h>
#include <stdio.h>

int main(){

    int choice = 0, numb_games = 0, tot_games = 0, cur_game = 1; //Declare variables: choice, number of games, total games, current game
    float average_price = 0, game_price = 0, total_price = 0; //Declare variables: average price, game price, total price

    printf("Welcome to UCF Games!");
    srand(time(0)); //Start random number generator

    while (choice != 3) { //Main loop
      void printmenu(); //Open menu

      printf("What would you like to do?\n");
      printf("\t1. Buy New Games\n");
      printf("\t2. Buy Used Games\n");
      printf("\t3. Quit\n\t");
      scanf("%d", &choice);

      if (choice == 1) { //User wants to buy new games
            cur_game = 1;
            double buy_new(int *total_games);//call on new game function

            printf("How many new games would you like to buy?\n");
            scanf("%d", &numb_games); //Get input on how many games user would like to buy
            tot_games += numb_games;

            while (cur_game <= numb_games){
              game_price = (rand()%2500+2500)/100.00; //Get random prices
              printf("Game %d costs %.2f\n", cur_game, game_price); //Print out prices
              cur_game += 1;
              total_price += game_price; }
        }

       else if (choice == 2) { //User would like to buy used games
            cur_game = 1;
            double buy_used(int *total_games);//Call on used game function

            printf("How many used games would you like to buy?\n");
            scanf("%d", &numb_games); //Get input for number of games user wants to buy
            tot_games += numb_games;

            while (cur_game <= numb_games){
                game_price = (rand()%1500+500)/100.00; //Get random price of games
                printf("Game %d costs %.2f\n", cur_game, game_price);
                cur_game += 1;
                total_price += game_price;}
        }

        else if (choice == 3){

            average_price = total_price/tot_games; //Calculate average price
            printf("Your total cost is $%.2f\n", total_price); //Tell User total price
            printf("The average cost of each game was $%.2f", average_price);} //Tell User average price

        else
            printf("Sorry, %d is not a valid choice.\n", choice); //Invalid choice
    }
    return 0;
}





