#include <cstdio>
using namespace std;

const int N = 50000;
int d[N], n, m, ans;

void Combine(int k) {
  int tmp = d[k] + d[k - 1];
  ans += tmp;
  m--;
  for (int i = k; i < m; i++) d[i] = d[i + 1];
  int j = k - 1;
  for (; j > 0 && d[j - 1] < tmp; j--) d[j] = d[j - 1];
  d[j] = tmp;
  while (j >= 2 && d[j] >= d[j - 2]) {
    tmp = m - j;
    Combine(j - 1);
    j = m - tmp;
  }
}

int main() {
  while (scanf("%d\n", &n)) {
    if (n == 0) return 0;
    for (int i = 0; i < n; i++) scanf("%d\n", &d[i]);
    scanf("\n");
    ans = m = 0;
    for (int i = 0; i < n; i++) {
      d[m++] = d[i];
      while (m > 2 && d[m - 1] >= d[m - 3]) Combine(m - 2);
    }
    while (m > 1) Combine(m - 1);
    printf("%d\n", ans);
  }
  return 0;
}