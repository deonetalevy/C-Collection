//Calculate distance using rate and time

#include <stdio.h>
int main(void) {
   int rate; //rate is and int
   double time; //time is a double

   printf("How fast did you run?\n");
   scanf("%d", &rate);
   printf("How many hours did you run dude?\n");
   scanf("%lf", &time);

   printf("Your ran %lf miles for %lf hours at %d mph.\n", rate*time, time, rate);

   return 0;

}
