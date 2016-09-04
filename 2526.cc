#include <cstdio>
#include <algorithm>
using namespace std;
const int num = 10005;
struct node {
  int x, y;
} data[num];
bool cmp(const node &a, const node &b) {
  if (a.x != b.x) return a.x < b.x;
  return a.y < b.y;
}
int main() {
  int t, n, i, flag;
  double sx, sy, ex, ey;
  // freopen("in.txt","r",stdin);
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d%d", &data[i].x, &data[i].y);
    sort(data, data + n, cmp);
    sx = (double)data[0].x + (double)data[n - 1].x;
    sy = (double)data[0].y + (double)data[n - 1].y;
    flag = 1;
    for (i = 1; i <= n / 2; i++) {
      ex = (double)data[i].x + (double)data[n - 1 - i].x;
      ey = (double)data[i].y + (double)data[n - 1 - i].y;
      if (ex != sx || ey != sy) {
        flag = 0;
        break;
      }
    }
    if (flag == 1)
      printf("yes\n");
    else
      printf("no\n");
  }
  return 0;
}
