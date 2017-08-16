//Deone'Ta Levy
//Encrypt file using Hill Cipher


#include <stdio.h>
#include <string.h>

int main(){

FILE *a, *b, *c;

char input_file[30], output_file[30], key[30];

char plaintext[10000], ciphertext[10000];
int keytext[30];

printf("Please enter the name of the file storing the key.\n");
scanf("%s", key);

printf("Please enter the name of the file to encrypt.\n");
scanf("%s", input_file);

printf("Please enter the name of the file to store the ciphertext.\n");
scanf("%s", output_file);

a = fopen("%s", input_file);

b = fopen("%s", output_file);

c = fopen("%s", key);

fscanf(a, "%s", plaintext);

fscanf(b, "%s", ciphertext);

fscanf(c, "%d", &keytext);

fclose(a);
fclose(b);
fclose(c);


return 0;


}
