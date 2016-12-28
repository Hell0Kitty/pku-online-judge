#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 1000001
int n, m, e;
int first[N], next[N << 1], v[N << 1], w[N << 1];
int dx[N], dy[N], d[N];
int qmin[N], qmax[N];
void init() {
  e = 0;
  memset(first + 1, -1, sizeof(first[0]) * n);
}
void add(int a, int b, int c) {
  v[e] = b;
  w[e] = c;
  next[e] = first[a];
  first[a] = e++;
}
void dfs(int a, int fa, int dist, int *d) {
  int i, b;
  for (i = first[a]; ~i; i = next[i]) {
    b = v[i];
    if (b ^ fa) dfs(b, a, d[b] = dist + w[i], d);
  }
}
void solve() {
  int i, j, front1, front2, rear1, rear2;
  int ans = 0;
  front1 = rear1 = 0;
  front2 = rear2 = 0;
  for (i = 1, j = 1; j <= n; j++) {
    while (rear1 > front1 && d[qmin[rear1 - 1]] >= d[j]) rear1--;
    qmin[rear1++] = j;

    while (rear2 > front2 && d[qmax[rear2 - 1]] <= d[j]) rear2--;
    qmax[rear2++] = j;

    if (d[qmax[front2]] - d[qmin[front1]] > m) {
      ans = max(ans, j - i);
      while (d[qmax[front2]] - d[qmin[front1]] > m) {
        i = min(qmin[front1], qmax[front2]) + 1;
        while (front1 < rear1 && qmin[front1] < i) front1++;
        while (front2 < rear2 && qmax[front2] < i) front2++;
      }
    }
  }
  ans = max(ans, j - i);
  printf("%d\n", ans);
}
int main() {
  int i, a, b, c, x, y;
  while (~scanf("%d%d", &n, &m)) {
    init();
    for (a = 2; a <= n; a++) {
      scanf("%d%d", &b, &c);
      add(a, b, c);
      add(b, a, c);
    }
    dfs(1, 0, dx[1] = 0, dx);

    for (x = 1, i = 2; i <= n; i++) {
      if (dx[i] > dx[x]) x = i;
    }
    dfs(x, 0, dx[x] = 0, dx);
    for (y = 1, i = 2; i <= n; i++) {
      if (dx[i] > dx[y]) y = i;
    }
    dfs(y, 0, dy[y] = 0, dy);
    for (int i = 1; i <= n; i++) d[i] = max(dx[i], dy[i]);
    solve();
  }
  return 0;
}
