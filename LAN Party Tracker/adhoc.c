//Deone'Ta Levy
//Keep Track of MAC addresses for LAN

#include <stdio.h>

//Linked list
struct friendlaptops{
int MAC;
struct friendlaptops * next;
};

struct tree_node{
int MAC;
char Name[21];
struct friendlaptops * links;
struct tree_node * left;
struct tree_node * right;
};


int main(){

int choice, mac;


printf("Welcome to the Ad Hoc Network program!\n");

while (choice != 3) {
printf("\nAdd a friend to the list (1)\nRemove a friend from the list (2)\nQuit (3)\n");
scanf("%d", &choice);

if (choice == 1){
    printf("\nWhat is your mac address?\n");
    scanf("%d", &mac);
}
else if (choice == 2){
    printf("\nWhat is your mac address?\n");
    scanf("%d", &mac);
}
else
    if (choice != 1 && choice != 2 && choice != 3){
    printf("\nThat is not a valid choice.\n");
    }
}

return 0;
}
