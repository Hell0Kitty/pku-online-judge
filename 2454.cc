#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <cmath>
#include <time.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
#define INF (INT_MAX / 10)
#define SQR(x) ((x) * (x))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repf(i, a, b) for (int i = (a); i <= (b); ++i)
#define repd(i, a, b) for (int i = (a); i >= (b); --i)
#define clr(ar, val) memset(ar, val, sizeof(ar))
#define N 200
int n;
struct node {
  int x, i;
};
node a[N];
bool cmp(node a, node b) { return a.x > b.x; }
int main() {
  srand(time(0));
  while (~scanf("%d", &n)) {
    repf(i, 1, 3 * n) scanf("%d", &a[i].x), a[i].i = i;
    sort(a + 1, a + n * 3 + 1, cmp);
    int sum = 0, mid;
    repf(i, 1, 2 * n) {
      sum += a[i].x;
      if (i == n) mid = sum;
    }
    int l = n * 1000 / 2 + 1;  // min
    int r = sum - l;
    sum = mid;
    while (true) {
      int x = rand() % n + 1;
      int y = rand() % n + n + 1;
      sum = sum - a[x].x + a[y].x;
      swap(a[x], a[y]);
      if (sum >= l && sum <= r) break;
    }
    repf(i, 1, 3 * n) printf("%d\n", a[i].i);
  }
  return 0;
}
