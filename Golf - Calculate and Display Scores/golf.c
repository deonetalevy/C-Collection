//Deone'Ta Levy
//Calculate and Display Golf Scores

#include <stdio.h>
#include <math.h>


int main() {

FILE *ifp; //File pointer

int a, b, players, counter, gamescore, par[18], individual[4][18], breakdown[4][18]; //Set variables

ifp = fopen("input.txt", "r"); //open file

  fscanf(ifp, "%d\n", &players); //Get amount of players
  printf("%d players are golfing\n\n", players);


    for(a = 0; a < 18; a++) { //Calculate par
            fscanf(ifp, "%d", &par[a]);
    }


    for(counter = 0; counter < players; counter++) {

        for(a = 0; a < players; a++){ //Get players scores.
            for(b = 0; b < 18; b++){
                fscanf(ifp, "%d", &individual[a][b]);
        }
    }

        for(a = 0; a < players; a++){ //Calculate Breakdown
            printf("\n\n");
            gamescore=0;
            for(b = 0; b < 18; b++){ //Calculate Scores

                breakdown[a][b] = individual[a][b] - par[b];
                gamescore += breakdown[a][b];
            }
            printf("Player %d scored %d.\n\n", a+1 ,gamescore);
        }
            printf("Breakdown: ");
            for(a = 0; a < players ; a++){
               for(b = 0; b < 18; b++){
                printf("%d ", breakdown[a][b]);
               }
            }

    }

            printf("Player %d is the winner!", gamescore);


fclose(ifp);



return 0;
}
