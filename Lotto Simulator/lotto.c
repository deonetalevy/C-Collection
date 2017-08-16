// Deone'Ta Levy
// Lotto Program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct LottoPlayer {
	char fname[20];
	char lname[20];
	int numbers[5];
};


int main()
{
    //Generate random lotto numbers
    int i, rand_numbers[5];

      for (i = 0; i < 6; i++) {
       rand_numbers[i] = rand() % 60 + 1;
      //printf("%d\n", rand_numbers[i]); //Testing random number generator
      }



    FILE * ifp; //Open lotto.txt file
    ifp = fopen("lotto.txt","r");

    int numberofentries;
    fscanf(ifp, "%d\n", &numberofentries);
    struct LottoPlayer * lotto_player = malloc(sizeof(struct LottoPlayer)* numberofentries);
    i = 0;
    // read through the rest of the file
    for(i=0; i < numberofentries + 1; i++){
         fscanf(ifp, "%s %s %d %d %d %d %d %d", &lotto_player[i].fname, &lotto_player[i].lname, &lotto_player[i].numbers[0], &lotto_player[i].numbers[1], &lotto_player[i].numbers[2], &lotto_player[i].numbers[3], &lotto_player[i].numbers[4], &lotto_player[i].numbers[5] );

    }
     fclose(ifp);

     //printf("%s %s", lotto_player[0].fname, lotto_player[0].lname) //Checking if fscanf was successful
    // loop through all struct array values with numberofentries being your max loop number
    // loop through each one, compare their 6 numbers with the 6 numbers in the winning number array
    int number_of_matches = 0;

    for (i = 0; i < 5; i++){
         if (lotto_player[i].numbers == rand_numbers[i])
          number_of_matches = number_of_matches + 1;
    }
    //number_of_matches = 6; //Testing output
    for (i = 0; i < numberofentries; i++) //Going through arrays and printing out how much someone won
    if (number_of_matches == 4) {
        printf("%s %s matched 4 numbers and won $500.\n", lotto_player[i].fname, lotto_player[i].lname);
    }
    else if (number_of_matches == 5) {
        printf("%s %s matched 5 numbers and won $2500.\n", lotto_player[i].fname, lotto_player[i].lname);
    }
    else if (number_of_matches == 6) {
        printf("%s %s matched 6 numbers and won $10000.\n", lotto_player[i].fname, lotto_player[i].lname);
    }
    else {
    }


    return 0;
}
