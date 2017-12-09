#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    double r;
    int n;
    scanf("%lf%d", &r, &n);
    printf("Scenario #%d:\n%.3f\n\n", i + 1,
           (1 - 1 / (1 + sin(3.1415926 / n))) * r);
  }
  return 0;
}
