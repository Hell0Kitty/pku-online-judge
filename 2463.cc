#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define eps 1e-9

using namespace std;

double k, l, s, w, vv, g = 9.81;

int main() {
  while (1) {
    scanf("%lf %lf %lf %lf", &k, &l, &s, &w);
    if (k > 0 - eps && k < eps && l > 0 - eps && l < eps && s > 0 - eps &&
        s < eps && w > 0 - eps && w < eps)
      break;
    if (l > s - eps)
      vv = 2 * g * s;
    else
      vv = 2 * g * s - k * (s - l) * (s - l) / w;
    if (vv < 0 - eps)
      printf("Stuck in the air.\n");
    else if (vv > 100)
      printf("Killed by the impact.\n");
    else
      printf("James Bond survives.\n");
  }

  return 0;
}
