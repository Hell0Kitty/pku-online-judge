#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int t;
char weekday[10][20] = {"Friday",  "Saturday",  "Sunday",  "Monday",
                        "Tuesday", "Wednesday", "Thursday"};
int monthday[20] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int cal(int y) {
  if (y % 100 == 0) {
    if (y % 400 == 0) return 366;
    return 365;
  }
  if (y % 4 == 0) return 366;
  return 365;
}

void work() {
  int y, m, d;
  int n = t + 1;
  y = 2000;
  while (1) {
    d = cal(y);
    if (n > d)
      n -= d;
    else
      break;
    y++;
  }
  int i = 0;
  m = 0;
  while (1) {
    if (i == 1)
      d = monthday[i] + cal(y) - 365;
    else
      d = monthday[i];
    if (n > d)
      n -= d;
    else
      break;
    m++;
    i++;
  }
  m++;
  printf("%d-%02d-%02d %s\n", y, m, n, weekday[(t + 1) % 7]);
}

int main() {
  while (scanf("%d", &t), t != -1) {
    work();
  }
  return 0;
}
