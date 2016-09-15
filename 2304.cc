#include <stdio.h>
#include <math.h>
int main() {
  int a, b, c, d, cal;
  while (scanf("%d%d%d%d", &a, &b, &c, &d) != EOF) {
    if (a == b && b == c && c == d && a == 0) {
      break;
    } else {
      cal = 1080;
      if (b >= a) {
        cal += (40 - b + a) * 9;
      } else if (b < a) {
        cal = cal + 360 - (40 - a + b) * 9;
      }

      if (b >= c) {
        cal += (40 - b + c) * 9;
      } else if (b < c) {
        cal = cal + 360 - (40 - c + b) * 9;
      }

      if (c >= d) {
        cal = cal + 360 - (40 - c + d) * 9;
      } else if (c < d) {
        cal += (40 - d + c) * 9;
      }
      printf("%d\n", cal);
    }
  }

  return (0);
}
