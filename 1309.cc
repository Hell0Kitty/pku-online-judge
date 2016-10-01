#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int mr = (1 << 16) + 1;
bool notp[mr];
int pr[mr];
int pn;
void getpri() {
  pn = 0;
  memset(notp, 0, sizeof(notp));
  for (int i = 2; i < mr; i++) {
    if (!notp[i]) {
      pr[pn++] = i;
    }
    for (int j = 0; j < pn && i * pr[j] < mr; j++) {
      int k = i * pr[j];
      notp[k] = 1;
      if (i % pr[j] == 0) {
        break;
      }
    }
  }
}
int fac[100];
int tot[100], top;
void div(int n) {
  for (int i = 0; i < pn && pr[i] * pr[i] <= n; i++) {
    if (n % pr[i] == 0) {
      fac[top] = pr[i];
      tot[top] = 0;
      while (n % pr[i] == 0) {
        tot[top]++;
        n /= pr[i];
      }
      top++;
    }
  }
  if (n > 1) fac[top] = n, tot[top++] = 1;
}
bool solve(int m, int n) {
  for (int i = 0; i < n; i++) {
    if (m % n != 1) return false;
    m = (m - 1) / n * (n - 1);
  }
  return m % n == 0;
}
int ans;
int po(int n, int k) {
  int p = 1;
  while (k--) p *= n;
  return p;
}
void dfs(int k, int res, int m) {
  if (k == top) {
    if (solve(m, res)) ans = max(ans, res);
    return;
  }
  for (int i = tot[k]; i >= 0; i--) dfs(k + 1, res * po(fac[k], i), m);
}
int main() {
  getpri();
  int m;
  while (scanf("%d", &m), m >= 0) {
    int mm = m - 1;
    top = 0;
    div(mm);
    ans = -1;
    dfs(0, 1, m);
    if (ans == -1)
      printf("%d coconuts, no solution\n", m);
    else
      printf("%d coconuts, %d people and 1 monkey\n", m, ans);
  }
  return 0;
}
