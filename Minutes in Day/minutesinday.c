//Deone'Ta Levy
//Calculating the Amount of Minutes in a Day
//1/17/2012

#include <stdio.h>
   int main(void) {
    int min_day, min_hour, hour_day;
    min_hour = 60; //min_hour, hour_day, and min_day can be included on same line. Enter variable followed by a comma.
    hour_day = 24;
    min_day = min_hour*hour_day;

    printf("There are %d minutes in a day. \n", min_day);

    return 0;

   }
