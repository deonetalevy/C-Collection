//Deone'Ta Levy
//Inventory Decisions: Company wants to purchase 1500 games based on customer interest


#include <stdio.h>
#include <math.h>

int main() {
  int per_fantasy, per_shooting, per_arcade;
  int fantasy, shooting, arcade;

  printf("What percentage of people prefer fantasy games?\n");
  scanf("%d", &per_fantasy);

  printf("What percentage of people prefer shooting games?\n");
  scanf("%d", &per_shooting);

  printf("What percentage of people prefer arcade games?\n");
  scanf("%d", &per_arcade);

  printf("\n");

  fantasy = 500*per_fantasy;
  shooting = 500*per_shooting;
  arcade = 500*per_arcade;

  printf("The business should buy %d fantasy games.\n", fantasy);
  printf("The business should buy %d shooting games.\n", shooting);
  printf("The business should buy %d arcade games.\n", arcade);


  return 0;
  }
