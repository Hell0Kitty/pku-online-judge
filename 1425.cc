#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>
#include <set>
using namespace std;

#define ll long long
#define MAX 110

double quickPow(double base, int p) {
  if (!p) return 1;

  double temp = quickPow(base, p / 2);
  temp *= temp;

  if (p & 1) temp *= base;

  return temp;
}

double getCase1(int n) {
  double cost = 0, total = 0;

  for (int i = 1; i <= n; i++) {
    cost += quickPow(n - 1, i) * i * n;
    total += quickPow(n - 1, i) * n;
  }

  return cost / total;
}

double fac[20];

void calculateFac() {
  int i;

  fac[0] = 1;

  for (i = 1; i <= 15; i++) fac[i] = fac[i - 1] * i;
}

int main() {
  int l;
  calculateFac();
  while (scanf("%d", &l) == 1) {
    if (l == 0) break;
    double case2, case3, a = 0, b = 0;
    for (int i = 2; i < l; i++) {
      a += (i + 1) * fac[l - 1] / fac[l - 1 - i];
      b += fac[l - 1] / fac[l - 1 - i];
    }
    case2 = a / b;
    a = 0;
    b = 0;
    for (int i = 1; i < l; i++) {
      a += i * fac[l - 1] / fac[l - 1 - i];
      b += fac[l - 1] / fac[l - 1 - i];
    }
    case3 = a / b;
    printf("%.4lf %.4lf %.4lf\n", getCase1(l), case3, case2);
  }
  return 0;
}
