//Deone'Ta Levy
//Stocking the Shelves. Calculate available shelf space.


#include <stdio.h>
#include <math.h>

int main() {

  int game_length, shelf_length, games_displayed; //game_length = the length of the game, shelf_length = the length of the shelf, games_displayed = the amount of games that can be displayed on one shelf
  int shelves, games_to_display, amount_of_games, games_stored; //shelves = the amount of shelves, games_to_display = amount of games that can be displayed on the specified amount of shelves, games_stored = amount of games stored

  printf("What is the length of the shelf, in inches?\n");
  scanf("%d", &shelf_length);

  printf("What is the length of the game, in inches?\n");
  scanf("%d", &game_length);

  games_displayed = shelf_length/game_length; //Equation for the amount of games that can be displayed on one shelf

  printf("%d games can be displayed on 1 shelf.\n\n", games_displayed);

  printf("How many shelves are there?\n");
  scanf("%d", &shelves);

  printf("How many games do you want to display?\n");
  scanf("%d", &amount_of_games);

  games_to_display = games_displayed*shelves; //Equation for the amount of games that can be displayed on a specified number of shelves
  games_stored = amount_of_games - games_to_display; //Equation for the amount of games that need to be stored

  printf("%d games can be displayed on %d shelves. %d games will have to be stored in the back.\n", games_to_display, shelves, games_stored);

  return 0;

}

