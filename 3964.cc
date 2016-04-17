#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10010;
int prime[maxn + 10], len;
int mk[maxn + 10];
void getprime() {
  len = 0;
  memset(mk, 0, sizeof(mk));
  for (int i = 2; i <= maxn; i++) {
    int sign = 0;
    for (int j = 1; j <= len && prime[j] * prime[j] <= i; j++)
      if (i % prime[j] == 0) {
        sign = 1;
        break;
      }
    if (sign == 0) {
      mk[i] = 1;
      prime[++len] = i;
    }
  }
}
int calcpow(int x, int y) {
  if (x == 0)
    return 0;
  else
    return calcpow(x / y, y) + x / y;
}
int pow[maxn];
const int inf = 0x3fffffff;
int calc(int be, int &times) {
  int low = 1, high = be;
  while (low < high) {
    int mid = (low + high + 1) / 2;
    int mk = 0, nowtimes = inf;
    for (int i = 1; i <= len && prime[i] <= mid; i++) {
      int tmp = pow[i] / calcpow(mid, prime[i]);
      if (tmp == 0) {
        mk = 1;
        break;
      } else
        nowtimes = min(tmp, nowtimes);
    }
    if (mk == 1)
      high = mid - 1;
    else {
      low = mid;
      times = nowtimes;
    }
  }
  for (int i = 1; i < len; i++) pow[i] -= calcpow(low, prime[i]) * times;
  return low;
}
int n, m;
int main() {
  getprime();
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    for (int j = 1; j <= len && prime[j] <= x; j++) {
      pow[j] += calcpow(x, prime[j]);
    }
  }
  for (int i = 1; i <= m; i++) {
    int x;
    scanf("%d", &x);
    for (int j = 1; j <= len && prime[j] <= x; j++) {
      pow[j] -= calcpow(x, prime[j]);
    }
  }
  int ok = 1;
  for (int i = 0; i <= len && ok; i++)
    if (pow[i] < 0) {
      ok = 0;
    }
  if (!ok)
    puts("-1");
  else {
    int be = 10006;
    int fine = 0;
    int times = 0;
    int cnt = 0;
    int ans[maxn], t[maxn];
    int tmp;
    while ((tmp = calc(be, times)) != 1) {
      fine = 1;
      ans[++cnt] = tmp;
      t[cnt] = times;
      be = tmp - 1;
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i++) printf("%d %d\n", ans[i], t[i]);
  }
  return 0;
}
