#include <cstdio>
#include <algorithm>
using namespace std;
#define maxn 100001
int n, a[maxn];
typedef long long LL;
LL limit;

int find(int x, int y) {
  int left = 1, right = y, mid;
  while (left < right) {
    mid = (left + right) >> 1;
    if (a[mid] < x)
      left = mid + 1;
    else
      right = mid;
  }
  return left;
}

bool check(int x) {
  LL sum = 0;
  for (int i = 1; i <= n; ++i) {
    sum += (LL)i - find(a[i] - x, i);
    if (sum >= limit) return true;
  }
  return false;
}
void solve() {
  int left = 0, right = 0x7fffffff, mid;
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  limit = (LL)n * (n - 1) / 2;
  limit = (limit + 1) / 2;
  sort(a + 1, a + n + 1);
  while (left < right) {
    mid = (left + right) >> 1;
    if (!check(mid))
      left = mid + 1;
    else
      right = mid;
  }
  printf("%d\n", left);
}
int main() {
  while (scanf("%d", &n) > 0) solve();
  return 0;
}
