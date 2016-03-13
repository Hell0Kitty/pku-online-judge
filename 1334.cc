#include <cstdio>
using namespace std;
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
int p[1001][2], n, p1, p2, ans, last;
int main() {
  int test;
  scanf("%d", &test);
  while (test--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d %d", &p[i][0], &p[i][1]);
    p1 = 0, p2 = n - 1, ans = 0;
    last = p[0][1];
    while (p2 > p1) {
      if (p[p2 - 1][1] > p[p2][1] && p[p1 + 1][1] > p[p1][1]) {
        ans += 2 * (min(p[p2 - 1][1], p[p1 + 1][1]) - last);
        last = min(p[p2 - 1][1], p[p1 + 1][1]);
        if (p[p2 - 1][1] == last) p2--;
        if (p[p1 + 1][1] == last) p1++;
      } else if (p[p2 - 1][1] < p[p2][1] && p[p1 + 1][1] > p[p1][1]) {
        ans += 2 * (last - max(p[p2 - 1][1], p[p1][1]));
        last = max(p[p2 - 1][1], p[p1][1]);
        if (last == p[p2 - 1][1])
          p2--;
        else
          p1--;
      } else if (p[p2 - 1][1] > p[p2][1] && p[p1 + 1][1] < p[p1][1]) {
        ans += 2 * (last - max(p[p2][1], p[p1 + 1][1]));
        last = max(p[p2][1], p[p1 + 1][1]);
        if (last == p[p1 + 1][1])
          p1++;
        else
          p2++;
      } else {
        ans += 2 * (min(p[p1][1], p[p2][1]) - last);
        last = min(p[p1][1], p[p2][1]);
        if (last == p[p1][1])
          p1--;
        else
          p2++;
      }
    }
    printf("%d\n", ans * 2);
  }
  return 0;
}
