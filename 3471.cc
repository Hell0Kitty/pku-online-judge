#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int64 __int64
using namespace std;

int64 MOD[] = {13251349, 13251361, 13251367, 13251373, 13251377, 13251383};

int64 prime[60000], isprime[60000], cnt;

void init() {
  int64 i, j;
  cnt = 0;
  for (i = 2; i < 60000; i++) {
    if (!isprime[i]) prime[++cnt] = i;
    for (j = 1; j <= cnt && prime[j] * i < 60000; j++) {
      isprime[prime[j] * i] = 1;
      if (i % prime[j] == 0) break;
    }
  }
}

struct node {
  int64 prime, num;
};

node a[100];
int64 n, aNum, factor[10000], factorNum;
int64 coef[105];

int64 ABS(int64 x) {
  if (x < 0) return -x;
  return x;
}

void DFS(int64 x, int dep) {
  int64 i;
  if (dep == aNum + 1) {
    factor[factorNum++] = x;
  } else {
    for (i = 0; i <= a[dep].num; i++) {
      DFS(x, dep + 1);
      x = x * a[dep].prime;
    }
  }
}

void cal(int64 p) {
  aNum = 0;
  int64 i;
  for (i = 1; i <= cnt; i++)
    if (p % prime[i] == 0) {
      aNum++;
      a[aNum].prime = prime[i];
      a[aNum].num = 0;
      while (p % prime[i] == 0) {
        a[aNum].num++;
        p /= prime[i];
      }
    }
  if (p > 1) {
    aNum++;
    a[aNum].prime = p;
    a[aNum].num = 1;
  }
  factorNum = 0;
  DFS(1, 1);
}

int OK(int64 a) {
  int64 r, b, i, j;
  for (i = 0; i < 6; i++) {
    r = 0;
    b = a % MOD[i];
    for (j = n; j >= 0; j--) r = (r * b + coef[j]) % MOD[i];
    if (r) return 0;
  }
  return 1;
}

int64 ans[10005], ansNum;

int main() {
  init();
  while (scanf("%d", &n) != -1) {
    int64 i, j, k, t, r, u;
    for (i = n - 1; i >= 0; i--) scanf("%I64d", &coef[i]);
    coef[n] = 1;
    ansNum = 0;
    k = 0;
    factorNum = 0;
    while (n) {
      if (coef[0] == 0) {
        ans[ansNum++] = 0;
        for (i = 0; i < n; i++) coef[i] = coef[i + 1];
        n--;
      } else {
        if (!factorNum) cal(ABS(coef[0]));
        t = 0;
        for (i = k; i < factorNum; i++)
          if (coef[0] % factor[i] == 0) {
            if (OK(factor[i])) {
              t = factor[i];
              k = i;
              break;
            }
            if (OK(-factor[i])) {
              t = -factor[i];
              k = i;
              break;
            }
          }
        if (!t) break;
        ans[ansNum++] = t;
        r = 0;
        for (i = n; i >= 0; i--) {
          u = r * t + coef[i];
          coef[i] = r;
          r = u;
        }
        n--;
      }
    }
    sort(ans, ans + ansNum);
    printf("%I64d\n", ansNum);
    for (i = 0; i < ansNum; i++) printf("%I64d\n", ans[i]);
  }
  return 0;
}
