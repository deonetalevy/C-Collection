//Deone'Ta Levy
//Distance Formula

#include <stdio.h>
#include <math.h>
  int main() {
  double X1, X2, Y1, Y2;
  double distance;

  printf("Enter the first coordinate: \n");
  scanf("%lf %lf", &X1, &Y1);

  printf("Enter the second coordinate: \n");
  scanf("%lf &lf", &X2, &Y2);

  distance = sqrt(pow(X2-X1, 2) + pow(Y2-Y1, 2));

  printf("The distance between these two coordinates is %lf.\n", distance);

  return 0;

  }
