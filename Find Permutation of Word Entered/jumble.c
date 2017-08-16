//Deone'Ta Levy
//Find Permutations of Words entered
//Will only work with words that are in the dictionary.txt file ex:
//"HE" and "EH", "NO" and "ON"

#include <stdio.h>
#include <string.h>

//Function prototypes
int open_dictionary(char dictionary[][20]);
void permute(char jumbled[],int n, int size, char dictionary[][20]);
void swap(char jumbled[], int a, int b);
int compare_dictionary(char dictionary[][20], char permutation[], int size);
void write_to_file(char permutation[], char jumbled[]);


int main(){

//Variable Declaration
char choice = 0, word[20], dictionary[10000][20];
int size;

//Getting the number of words in the dictionary
size = open_dictionary(dictionary);


printf("Welcome to the Jumble Puzzle Solver!\n\n");

    printf("\nWould you like to enter a jumbled word? (Y,y or N,n)\n");
    scanf("%c", &choice);

    //Menu loop
    while (choice != 'n' && choice != 'N') {


    if (choice == 'y' || choice == 'Y'){
        printf("\nWhat word would you like scored?(In uppercase please)\n");
        scanf("%s", word);

        permute(word, 0, size, dictionary);


    }


    printf("\nWould you like to enter a jumbled word? (Y,y or N,n)\n");
    scanf("%c", &choice);

    }



return 0;
}

//Preconditions: Takes in a 2-D array from main
//Postconditions: Opens dictionary.txt file, gets the size,
//Gets the words in the dictionary, and returns those values
//to main.
int open_dictionary(char dict[][20]) {

    //Open dictionary file
    FILE * ifp = fopen("dictionary.txt", "r");

    int size, i;

    //Size is the first value in the dictionary
    fscanf(ifp, "%d", &size);

    //Getting words
    for (i = 0; i < size; i++)
        fscanf(ifp, "%s", dict[i]);


    fclose(ifp);

    //Size = the size in main
    return size;
}

//Preconditions: jumbled is a valid C string. N will be from 0 <= the
//length of jumbled. Size is the size of the dictionary.
//Postconditions: All permutations of jumbled are passed into compare_dictionary
//function.
void permute(char jumbled[], int n, int size, char dictionary[][20]){
    //Declare variables
    char permutation[20];
    int i;
    strcpy(permutation, jumbled);

    //Compare to dictionary and write to file
    if (n == strlen(jumbled)){
        if (compare_dictionary(dictionary, permutation, size) == 0){
            printf("A permutation of %s that is a valid word is %s.\n", jumbled, permutation);
            write_to_file(permutation, jumbled);
            }
        else
            printf("Sorry, no permutations of %s form a word.\n", jumbled);
    }
    //Permute
    else {
        for (i = n; n < strlen(jumbled); n ++){
            swap(jumbled, n, i);
            permute(jumbled, n+1, size, dictionary);
            swap(jumbled, i, n);
            }
        }

}

//Preconditions: Takes in the 2-D dictionary array. The current permutation.
//And the size of the dictionary file.
//Postconditions: Returns 0 to permute function if the permutation is in the
//dictionary. Returns 1 if it is not in the dictionary.
int compare_dictionary(char dictionary[][20], char permutation[], int size){
    int low = 0, high = size-1;

    //Binary search through dictionary
    while (low <= high){
        int mid = (low + high)/2;
        int compare = (strcmp(permutation, dictionary[mid]));

        if (compare < 0)
                high = mid - 1;
        else if (compare > 0)
                low = mid+1;
        else
            return 0;
    }
    //If not in dictionary, return 1
    return 1;
}

//Preconditions: jumbled is a string and a and b are indexes to it.
//Postconditions: The contents of a and b will be switched.
void swap(char jumbled[], int a, int b){

    //Make temp equal a
    char temp = jumbled[a];
    //Make a equal to b
    jumbled[a] = jumbled[b];
    //b is equal to previous a
    jumbled[b] = temp;

}

//Preconditions: Takes in two strings. One is a permuatation and another is the
//Original jumbled letters.
//Postconditions: Will create and write to the jumbleout.txt file.
void write_to_file(char permutation[], char jumbled[]){

FILE * ifp;

//Create jumbleout file
ifp = fopen("jumbleout.txt", "w");

//Write to jumbleout file
fprintf(ifp,"A permutation of %s that is a valid word is %s.\n", jumbled, permutation);

fclose(ifp);

return;
}
