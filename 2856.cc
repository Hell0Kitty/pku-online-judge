#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

int c, p, n, high, score;
int a[50][10], t[10];
string nam;

void cal() {
  high = 0;
  for (int i = 1; i <= c; ++i) {
    int sc = 0;
    for (int j = 1; j <= 3; ++j) sc += a[i][j] * t[j];
    if (i == p) score = sc;
    high = max(high, sc);
  }
}

bool work() {
  for (int i = 1; i <= 3; ++i)
    for (int j = 1; j <= 3; ++j)
      if (j != i)
        for (int k = 1; k <= 3; ++k)
          if (k != i && k != j) {
            t[i] = n * n;
            t[j] = n;
            t[k] = 1;
            cal();
            if (high == score) return true;
          }
  for (int i = 1; i <= 3; ++i) {
    t[1] = t[2] = t[3] = n;
    t[i] = 1;
    cal();
    if (high == score) return true;
  }
  for (int i = 1; i <= 3; ++i) {
    t[1] = t[2] = t[3] = 1;
    t[i] = n;
    cal();
    if (high == score) return true;
  }
  t[1] = t[2] = t[3] = 1;
  cal();
  if (high == score) return true;
  return false;
}

int main() {
  scanf("%d", &c);
  while (c) {
    n = 0;
    p = 0;
    for (int i = 1; i <= c; ++i) {
      cin >> nam;
      if (nam == "Canada") p = i;
      scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
      n += a[i][1] + a[i][2] + a[i][3];
    }
    if (p == 0)
      printf("Canada cannot win.\n");
    else if (work())
      printf("Canada wins!\n");
    else
      printf("Canada cannot win.\n");
    scanf("%d", &c);
  }
  return 0;
}
