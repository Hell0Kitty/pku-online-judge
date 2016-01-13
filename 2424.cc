#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int a, b, c;
int time1[111];
int time2[111];
int time3[111];

char t[6];
int n;
int main() {
  while (scanf("%d%d%d", &a, &b, &c), a + b + c) {
    int ans = 0;
    memset(time1, 0, sizeof(time1));
    memset(time2, 0, sizeof(time2));
    memset(time3, 0, sizeof(time3));
    while (scanf("%s", t) && t[0] != '#') {
      int ti = ((t[0] - '0') * 10 + t[1] - '0') * 60 + (t[3] - '0') * 10 +
               t[4] - '0';
      scanf("%d", &n);
      if (n == 1 || n == 2) {
        if (a == 0) continue;
        sort(time1, time1 + a);
        if (time1[0] <= ti + 30) {
          ans += n;
          if (time1[0] < ti)
            time1[0] = ti + 30;
          else
            time1[0] += 30;
        }
      } else if (n == 3 || n == 4) {
        sort(time2, time2 + b);
        if (time2[0] <= ti + 30) {
          ans += n;
          if (time2[0] < ti)
            time2[0] = ti + 30;
          else
            time2[0] += 30;
        }
      } else if (n == 5 || n == 6) {
        sort(time3, time3 + c);
        if (time3[0] <= ti + 30) {
          ans += n;
          if (time3[0] < ti)
            time3[0] = ti + 30;
          else
            time3[0] += 30;
        }
      }
    }
    printf("%d\n", ans);
  }
}
