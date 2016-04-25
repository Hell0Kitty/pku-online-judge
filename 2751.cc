#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 10009;
struct Node {
  int x, y;
} a[N];
bool cmp(Node a, Node b) { return min(a.x, b.y) < min(b.x, a.y); }
int main() {
  int n, i;

  while (~scanf("%d", &n) && n) {
    for (i = 0; i < n; ++i) {
      scanf("%d%d", &a[i].x, &a[i].y);
    }

    sort(a, a + n, cmp);
    int t1 = 0, t2 = 0;

    for (i = 0; i < n; ++i) {
      t1 += a[i].x;
      t2 = max(t1, t2) + a[i].y;
    }

    printf("%d\n", t2);
  }

  return 0;
}
