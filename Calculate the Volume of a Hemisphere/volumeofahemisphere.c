//Deone'Ta Levy
//Volume of a Hemisphere

#include <stdio.h>
#include <math.h> //Math Library
//Constants
#define PI 3.14159
int main() {
  double volume, radius;

  printf("What is the radius?\n");
  scanf("%lf", &radius);

  volume = (2/3.0)*M_PI*pow(radius, 3); //Radius raised to the third power. "pow" is the power command. "M_PI" pi.

  printf("The volume is %lf.\n", volume);

  return 0;
}
