#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int getmax(int a, int b) {
  for (int i = 6; i >= 4; i--)
    if (i != a && i != b) return i;
}
int po[10005][7];
int main() {
  int T;
  for (scanf("%d", &T); T; T--) {
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      int a, b, c, d, e, f;
      scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
      po[i][a] = f;
      po[i][f] = a;
      po[i][b] = d;
      po[i][d] = b;
      po[i][c] = e;
      po[i][e] = c;
    }
    int sum, lx;
    for (int i = 1; i <= 6; i++) {
      sum = getmax(i, lx = po[0][i]);
      for (int j = 1; j < n; j++) {
        sum += getmax(lx, po[j][lx]);
        lx = po[j][lx];
      }
      ans = max(sum, ans);
    }
    printf("%d\n", ans);
  }
  return 0;
}
