#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define MAX_N 100005
#define MAX_FACTOR 16

int n, f[MAX_N];
int count[MAX_N];
int factor[MAX_FACTOR];
int prime_fac_num[MAX_N];

void input() {
  for (int i = 0; i < n; i++) scanf("%d", &f[i]);
}

void make(int a) {
  int factor_cnt = 0;
  for (int i = 2; i * i <= a; i++)
    if (a % i == 0) {
      factor[factor_cnt++] = i;
      while (a % i == 0) a /= i;
    }
  if (a > 1) factor[factor_cnt++] = a;
  for (int i = 1; i < (1 << factor_cnt); i++) {
    int used_fac = 0;
    int cur_fac = 1;
    for (int j = 0; (i >> j) > 0; j++) {
      if ((i >> j) & 1) {
        used_fac++;
        cur_fac *= factor[j];
      }
    }
    count[cur_fac]++;
    prime_fac_num[cur_fac] = used_fac;
  }
}

long long cal(long long a) { return a * (a - 1) * (a - 2) * (a - 3) / 24; }

int main() {
  while (scanf("%d", &n) != EOF) {
    input();
    memset(count, 0, sizeof(count));
    memset(prime_fac_num, 0, sizeof(prime_fac_num));
    for (int i = 0; i < n; i++) make(f[i]);
    long long ans = cal(n);
    for (int i = 2; i <= 10000; i++) {
      if (prime_fac_num[i] & 1)
        ans -= cal(count[i]);
      else
        ans += cal(count[i]);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
