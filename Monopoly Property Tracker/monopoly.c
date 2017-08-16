//Deone'Ta Levy
//Monopoly Property Tracking Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Property structure
struct property {
	char name[30];
	int user;
	int num_houses;
	int num_hotels;
	struct property * next;
};


//Function Prototypes
void buy_property(struct property * front, int player);
struct property * add_property(struct property * front, char prop_name[], int player);
struct property * improve_property(struct property * front, int player);
struct property * remove_property(struct property * front, char prop_name[], int player);
void sell_property(struct property * front, int player);
void print_list(struct property * front);


int main(){

  struct property * list = NULL;

  //Define variables for current player, menu choice, and amount of players array
  int n = 0, choice;


  printf("Welcome to the Monopoly Property Tracker!\n\n");
  printf("How many people are playing?\n\n");

  scanf("%d", &n); //Get amount of players

  int *amount_players; //Dynamically allocate memory for the amount of players array
  amount_players = (int*) malloc(sizeof(int) * n);

  int i;

  for ( i = 0; i < n; i++) {
      amount_players[i] = i + 1;//Creating amount of players array
      //printf("%d\n", amount_players[i]);
      }

  int m, w, j;

    //Menu loop
    for (m = 0; choice != 6; m++){

      //Loop through amount_players array
      for (w = 0; w < n && choice != 6; w++){

        //Create loop for the current player's turn
        for (choice = 0; choice != 5; j++){

        //Print out menu for current player
        printf("\n\nPlayer %d, what would you like to do?\n", amount_players[w]);
        printf("   1 - Buy Property\n   2 - Improve Property\n   3 - Sell Property\n");
        printf("   4 - View Properties\n   5 - End Turn\n   6 - End Game\n");
        scanf("%d", &choice);

        if (choice == 6){ //If a player chooses 6 then this will end the loops
           break;
        }

        else if (choice == 1) {
            //Call buy property function
            buy_property(list, amount_players[w]);

        }
        else if (choice == 2) {
            //Call improve property function
            improve_property(list, amount_players[w]);
        }
        else if (choice == 3) {
            //Call sell property function
            sell_property(list, amount_players[w]);
        }
        else if (choice == 4) {//Print all properties owned and player that owns the property
         print_list(list);
        }

        }
      }
    }


    //Game has ended so final list of all properties is printed
    print_list(list);

    return 0;
}

void print_list(struct property * front) {
    //Precondition: Input will be the front of the property list
    //Postcondition: All nodes in the list will be printed out
    while (front != NULL) {
        printf("%s, owned by %d\n", front->name, front->user);
        front = front->next;
    }

}


void buy_property(struct property * front, int player){
    //Preconditions: Input will be a list, front points to head of
    //a property list, player <= 6, player is the current player
    //Postconditions: Asks user for a property name, traverses list
    //to look for property name, if name is in the list tell user
    //the property is already owned, if not, call add property function

    //struct property * list = NULL;
    char property_name[30];

    printf("\nWhat is the name of the property you wish to buy?\n");
    scanf("%s", property_name);

    //Create helper to traverse list
    struct property * help_ptr;
    help_ptr = front;

    //If list is empty go ahead and add property
    if (help_ptr == NULL){
        front = add_property(front, property_name, player);
        return;
    }
    //Begin traversing

    while (help_ptr != NULL) {

        //If property is already in the list
        if (help_ptr->name == property_name){

            //Print statement depending on the player that owns it
            if (help_ptr->user == player)
               printf("\nYou already own that property!\n\n");
            else
               printf("\nPlayer %d owns that property.\n\n", help_ptr->user);
           //Return to main
           return;
        }

        //Move on to the next node
        else
        help_ptr = help_ptr->next;

    }
    help_ptr = front;
    front = add_property(front, property_name, player);
    return;

}


void sell_property(struct property * front, int player){
//Preconditions: Input will be the front of the property list and
//the current player determined by main
//Postconditions: Will ask user for name of property to sell. It will
//traverse the list and print out user does not own property or will
//call the sell property function.

    char property_name[30];

    printf("\nWhich property would you like to sell?\n");
    scanf("%s", property_name);

    //Create helper to traverse list
    struct property * help_ptr;
    help_ptr = front;

    //If list is empty then this is printed
    if (help_ptr == NULL){
    printf("\nYou do not own that property.\n\n");
    return;
    }

    //Traverse the list
    while (help_ptr != NULL){

        //If user owns this property then call sell_property function
        if (help_ptr->name == property_name && help_ptr->user == player){
            remove_property(help_ptr, property_name, player);
            return;
            }
       else {
            help_ptr = help_ptr->next;
        }
    }
    printf("\nYou do not own that property.\n\n");
    return;

}


struct property * add_property(struct property * front, char prop_name[], int player){
//Preconditions: Takes in front which points to the head of the property list,
//Takes in the property name stored as a string, and takes in the player number, these
//values are determined by the buy property function
//Postconditions: Adds new property to the front of the list, player and prop_name
//are separate values in the node, the values of houses and hotels are set to 0

int i;
//Creating temp node
struct property * temp;

//Allocating memory
temp = (struct property *)malloc(sizeof(struct property));

//Store new data
for (i = 0; i <30; i++){
temp->name[i] = prop_name[i];
}

temp->num_hotels = 0;
temp->num_houses = 0;
temp->user = player;

//Link to front of list
temp->next = front;

//Return new head of list
return temp;

}

struct property * remove_property(struct property * front, char prop_name[], int player){
//Preconditions: Will take in a node of a property list, the name of a property,
//and the current player. These values are determined by the sell_property function.
//Postconditions: This function will remove the front node from the list and will
//Print out how much it was sold for. All properties are worth 100, hotels are 50
//each, and houses are 20 each.

int num_houses, num_hotels, sell_price;

num_houses = front->num_houses;
num_hotels = front->num_hotels;

sell_price = 100 + (num_hotels * 50) + (num_houses * 25);

printf("You sold %s for $%d.00!\n", prop_name, sell_price);

struct property * temp;

while (temp != NULL){
    if (temp->next == front)
        temp->next = temp->next->next;
        free(front);
        return temp;
}


}

struct property * improve_property(struct property * front, int player){
//Preconditions: Front points to the head of the property list, player is
//the number of the current player, these values come from main
//Postconditions: Gets a property name from a user then traverses the list.
//If the user owns the property then they will choose the amount of houses
//or hotels that they wish to add. If the user doesn't own the property then
//they are not allowed to improve the property and are prompted that they
//do not own that property.

    char property_name[30];

    printf("\nWhich property would you like to improve?\n");
    scanf("%s", property_name);

    //Create helper to traverse list
    struct property * help_ptr;
    help_ptr = front;

    //If the list is empty then this player does not own the property
    if (help_ptr == NULL){
        printf("\nYou do not own that property.\n\n");
        return;
        }

    //Begin traversal
    while (help_ptr != NULL){

        //If user owns this property then call improve_property function
        if (help_ptr->name == property_name && help_ptr->user == player){
            int build_choice, amount_houses, amount_hotels;
            printf("\nDo you wish to build houses(1) or hotels(2)?\n");
            scanf("%d", &build_choice);

            if (build_choice == 1){
                printf("\nHow many houses do you want to build?\n");
                scanf("%d", amount_houses);
                help_ptr->num_houses = amount_houses;
            }
            else if (build_choice == 2) {
                printf("\nHow many hotels do you want to build?\n");
                scanf("%d", amount_hotels);

                help_ptr->num_hotels = amount_hotels;

            return front;
            }
            else {
                printf("\nThat is not a valid choice.\n");
                return front;
            }
        }
       else {
           help_ptr = help_ptr->next;
           }
}
     //Property was not in the list
    printf("\nYou do not own that property.\n\n");
    return front;
}
