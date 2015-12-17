// 144K 0Ms
#include <iostream>
#include <stdio.h>

using namespace std;

int cal(int h, int m, int s) { return h * 3600 + m * 60 + s; }

int main() {
  int h, m, s;
  double speed = 0;
  double ans = 0;
  int last = 0;
  while (scanf("%d:%d:%d", &h, &m, &s) != EOF) {
    char ch = getchar();
    if (ch == ' ') {
      int a;
      scanf("%d", &a);
      int now = cal(h, m, s);
      ans += (now - last) * speed;
      last = now;
      speed = a / 3.6;
    } else
      printf("%02d:%02d:%02d %.2f km\n", h, m, s,
             ((cal(h, m, s) - last) * speed + ans) / 1000);
  }
  return 0;
}