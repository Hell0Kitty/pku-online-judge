#include <stdio.h>
#include <string.h>
#include <queue>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;

#define clr(a, x) memset(a, x, sizeof a)

const int MAXN = 1000005;

LL phi[MAXN];
int pri[MAXN], cnt;

void preprocess() {
  cnt = 0;
  for (int i = 2; i < MAXN; ++i) {
    phi[i] = i;
  }
  for (int i = 2; i < MAXN; ++i) {
    if (phi[i] == i) {
      phi[i] = i - 1;
      pri[cnt++] = i;
    }
    for (int j = 0; j < cnt && i * pri[j] < MAXN; ++j) {
      if (i % pri[j] == 0) {
        phi[i * pri[j]] = phi[i] * pri[j];
        break;
      }
      phi[i * pri[j]] = phi[i] * (pri[j] - 1);
    }
    phi[i] += phi[i - 1];
  }
}

int main() {
  int n;
  preprocess();
  while (~scanf("%d", &n) && n) printf("%I64d\n", phi[n]);
  return 0;
}
