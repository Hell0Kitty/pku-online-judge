#include "stdio.h"
#include "memory.h"
#include "stdlib.h"
#define N 16

int n, t;
int sumlength, len;

int sticks[N], dsticks[N];
bool use[N], duse[N], judge1, judge2, sob[80];

int cmp(const void *a, const void *b) { return *((int *)a) - *((int *)b); }

void dfs(int now, int stick, int count)

{
  int i, len1;

  if (judge2 == 1) return;

  if (now == len) {
    now = 0;
    stick++;
  }

  if (stick == 3) {
    judge2 = 1;
    return;
  }

  for (i = 1; i < count; i++) {
    if (duse[i] == 1) continue;

    len1 = now + dsticks[i];

    if (sob[len1] == 1) continue;

    if (len1 > len) break;

    if (len1 == len) {
      duse[i] = 1;
      dfs(0, stick + 1, count);
      duse[i] = 0;
    }

    if (len1 < len) {
      sob[len1] = 1;
      duse[i] = 1;
      dfs(len1, stick, count);
      duse[i] = 0;
      sob[len1] = 0;
    }

    while (dsticks[i] == dsticks[i + 1] && i < count - 1) i++;
  }

  return;
}

void findsticks(int start, int now, int stick, int count)

{
  int i, len1;

  if (now == len) {
    now = 0;
    stick++;
    start = 0;
  }

  if (stick == 3) {
    memset(duse, 0, sizeof(duse));
    memset(sob, 0, sizeof(sob));
    dfs(0, 0, count);
    if (judge2 == 1) judge1 = 1;
    return;
  }

  for (i = start; i <= n; i++) {
    if (use[i] || sticks[i] == len) continue;
    len1 = now + sticks[i];

    if (len1 > len) break;
    dsticks[count] = sticks[i];
    use[i] = 1;
    findsticks(i + 1, len1, stick, count + 1);
    use[i] = 0;

    while (sticks[i] == sticks[i + 1] && i < n) i++;
  }

  return;
}

int solve() {
  if (n < 6) {
    printf("Case %d: 0\n", t);
    return 0;
  }
  if (sticks[1] == sticks[n]) {
    printf("Case %d: 0\n", t);
    return 0;
  }

  for (len = sumlength / 3; len >= sticks[1] + sticks[6]; len--) {
    memset(dsticks, 0, sizeof(dsticks));
    memset(use, 0, sizeof(use));
    judge1 = 0;
    judge2 = 0;
    findsticks(0, 0, 0, 0);

    if (judge1 == 1) {
      printf("Case %d: %d\n", t, len);
      return 0;
    }
  }
  printf("Case %d: 0\n", t);
  return 0;
}

int init() {
  sumlength = 0;
  len = 0;
  memset(sticks, 0, sizeof(sticks));

  int i;
  for (i = 1; i <= n; i++) {
    scanf("%d", sticks + i);
    sumlength += sticks[i];
  }

  qsort(sticks + 1, n, sizeof(int), cmp);

  return 0;
}

int main() {
  t = 0;
  while (scanf("%d", &n) != EOF && n > 0) {
    t++;
    init();
    solve();
  }
  return 0;
}
