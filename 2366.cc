#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 50005
using namespace std;

int a[maxn], b[maxn];
int n, m;

bool check(int x) {
  int l = 0, r = m - 1;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (b[mid] >= x)
      r = mid;
    else
      l = mid + 1;
  }
  if (x == b[l]) return 1;
  return 0;
}

int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
      scanf("%d", &b[i]);
      b[i] = 10000 - b[i];
    }
    sort(b, b + m);
    bool flag = 0;
    for (int i = 0; i < n; i++) {
      if (check(a[i])) {
        flag = 1;
        break;
      }
    }
    if (flag)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
