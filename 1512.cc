#include <iostream>
#include <stdio.h>

#define FOR(i, l, r) for (i = l; i <= r; i++)
#define MAXN 28
#define MAXG 35

using namespace std;
int n, m;
int ki[MAXN], p[MAXN][2], a[MAXN][110], nex[MAXN];
int tim[MAXG], ans[MAXG][260], q[MAXG][MAXN];

void jump(int num) {
  while (num--) getchar();
}

void solve(int top, int now, int l, int r, int bot) {
  int i, j, k;
  if (l > r) return;
  if (q[top][now] == tim[top]) {
    for (j = 0, i = now;;) {
      j += a[i][0];
      if ((i = nex[i]) == now) break;
    }
    if (l != 0) {
      r -= ((l - 1) / j) * j;
      l -= ((l - 1) / j) * j;
    }
  }
  if (ki[now]) {
    if (p[now][0] == now && l == 1) {
      solve(top + 1, p[now][1], 1, 1, 0);
      ans[top][1] = ans[top + 1][1];
      solve(top, now, 3, r + 1, 1);
      return;
    }
    tim[top + 1]++;
    solve(top + 1, p[now][0], (l + 2) >> 1, (r + 1) >> 1, 0);
    j = ((r + 1) >> 1) - ((l + 2) >> 1) + 1;
    FOR(i, 1, j) ans[top][bot + i + i - ((l & 1))] = ans[top + 1][i];
    tim[top + 1]++;
    solve(top + 1, p[now][1], (l + 1) >> 1, (r + 0) >> 1, 0);
    j = ((r + 0) >> 1) - ((l + 1) >> 1) + 1;
    FOR(i, 1, j) ans[top][bot + i + i - (!(l & 1))] = ans[top + 1][i];
  } else {
    q[top][now] = tim[top];
    if (l > a[now][0]) {
      solve(top, nex[now], l - a[now][0], r - a[now][0], bot);
      return;
    }
    if (r <= a[now][0]) {
      FOR(i, l, r) ans[top][bot + (i - l + 1)] = a[now][i];
      return;
    }
    FOR(i, l, a[now][0]) ans[top][bot + (i - l + 1)] = a[now][i];
    solve(top, nex[now], 1, r - a[now][0], bot + (a[now][0] - l + 1));
  }
}

int main() {
  int i, j, k;
  char na, chi, chj;
  scanf("%d%d", &n, &m);
  for (; n; n--) {
    scanf("\n%c", &na);
    na -= 'A';
    if (jump(3), cin.peek() == 'z') {
      scanf("zip %c %c", &chi, &chj);
      ki[na] = 1;
      p[na][0] = int(chi - 'A');
      p[na][1] = int(chj - 'A');
    } else {
      for (;;) {
        if (isdigit(cin.peek())) {
          scanf("%d", &a[na][++a[na][0]]);
          getchar();
        } else if (isupper(cin.peek())) {
          scanf("%c", &chi);
          nex[na] = int(chi - 'A');
          break;
        }
      }
    }
  }
  for (; m; m--) {
    scanf("\n%c%d%d", &na, &i, &j);
    i++;
    j++;
    tim[0]++;
    solve(0, int(na - 'A'), i, j, 0);
    printf("%d", ans[0][1]);
    FOR(k, 2, j - i + 1) printf(" %d", ans[0][k]);
    printf("\n");
  }
  return 0;
}
