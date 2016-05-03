#include <iostream>
#include <cmath>

using namespace std;

#define EPS 0.00001

int main() {
  double B, W, C;
  while (scanf("%lf%lf%lf", &B, &W, &C) && (B + W + C)) {
    B *= 16, W *= 16;
    double ans = B / W;
    double raW = 0, raB = 1;
    int sum = 0;
    while (fabs(raW / (1 - raW) - ans) > EPS ||
           fabs(raB / (1 - raB) - ans) > EPS) {
      raW = 1 - (W * (1 - raW) + C * (1 - raB)) / (C + W);
      raB = ((B - C) * raB + C * raW) / B;
      sum++;
    }
    printf("%d\n", sum);
  }
}
