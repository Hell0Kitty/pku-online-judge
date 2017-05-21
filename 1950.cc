#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 50;

char opr2[N];
char opr[N];
int opn[N];
int cnt, n;

void dfs(int p, int p2, int m, int sum, int t) {
  int i, j, tsum;
  if (sum == 0 && t == n) {
    if (cnt < 20) {
      for (i = 0; i < p; i++) {
        printf("%d %c ", i + 1, opr[i]);
      }
      printf("%d\n", t);
    }
    cnt++;
    return;
  }
  if (t >= n) return;

  t++;

  opr[p] = opr2[p2] = '+';
  opn[m] = t;
  tsum = sum + t;
  dfs(p + 1, p2 + 1, m + 1, tsum, t);

  opr[p] = opr2[p2] = '-';
  opn[m] = t;
  tsum = sum - t;
  dfs(p + 1, p2 + 1, m + 1, tsum, t);

  opr[p] = '.';
  if (t >= 10)
    opn[m - 1] = opn[m - 1] * 100 + t;
  else
    opn[m - 1] = opn[m - 1] * 10 + t;
  j = 0;
  tsum = opn[0];
  for (i = 1; i <= m - 1; i++) {
    if (opr2[j] == '+')
      tsum += opn[i];
    else
      tsum -= opn[i];
    j++;
  }
  dfs(p + 1, p2, m, tsum, t);
}

int main() {
  while (~scanf("%d", &n)) {
    memset(opr, 0, sizeof(opr));
    memset(opr2, 0, sizeof(opr2));
    memset(opn, 0, sizeof(opn));

    cnt = 0;
    opn[0] = 1;
    dfs(0, 0, 1, 1, 1);
    printf("%d\n", cnt);
  }
  return 0;
}
