#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
using namespace std;
int main() {
  double a, b;
  scanf("%lf", &a);
  if (a != 999) {
    while (scanf("%lf", &b), b != 999) {
      printf("%.2f\n", b - a);
      a = b;
    }
  }
  printf("End of Output\n");
  return 0;
}
