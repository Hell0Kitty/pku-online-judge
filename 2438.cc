#include <cstdio>
#include <cstring>

const int maxn = 410;

bool map[maxn][maxn];
bool visit[maxn];
int ans[maxn];
int ansi, n, tmp;

inline void reverse(int s, int t) {
  int temp;
  while (s < t) {
    temp = ans[s];
    ans[s] = ans[t];
    ans[t] = temp;
    ++s;
    --t;
  }
}

void Hamilton() {
  int s = 1, t, i, j;
  ansi = 2;
  memset(visit, 0, sizeof(visit));
  for (i = 1; i <= n; ++i)
    if (map[s][i]) {
      t = i;
      break;
    }
  ans[0] = s;
  ans[1] = t;
  visit[s] = visit[t] = true;
  while (true) {
    while (true) {
      for (i = 1; i <= n; ++i)
        if (!visit[i] && map[t][i]) break;
      if (i > n) break;
      visit[i] = true;
      ans[ansi++] = i;
      t = ans[ansi - 1];
    }
    reverse(0, ansi - 1);
    s = ans[0];
    t = ans[ansi - 1];
    while (true) {
      for (i = 1; i <= n; ++i)
        if (!visit[i] && map[t][i]) break;
      if (i > n) break;
      visit[i] = true;
      ans[ansi++] = i;
      t = ans[ansi - 1];
    }
    if (!map[s][t]) {
      for (i = 1; i < ansi - 2; ++i)
        if (map[ans[i]][t] && map[s][ans[i + 1]]) break;

      reverse(i + 1, ansi - 1);
      t = ans[ansi - 1];
    }
    if (ansi == n) break;
    for (i = 1; i <= n; ++i) {
      if (visit[i]) continue;
      for (j = 1; j < ansi - 2; ++j)
        if (map[ans[j]][i]) break;
      if (map[ans[j]][i]) break;
    }
    reverse(0, j - 1);
    reverse(j, ansi - 1);
    ans[ansi++] = i;
    visit[i] = true;  // attention: visit[i]=true!!!
    s = ans[0];
    t = ans[ansi - 1];
  }
}

int main() {
  int m, a, b;
  while (scanf("%d%d", &n, &m), n || m) {
    n <<= 1;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        if (i != j)
          map[i][j] = true;
        else
          map[i][j] = false;
    while (m--) {
      scanf("%d%d", &a, &b);
      map[a][b] = map[b][a] = false;
    }

    Hamilton();

    for (int i = 0; i < ansi - 1; ++i) printf("%d ", ans[i]);
    printf("%d\n", ans[ansi - 1]);
  }
  return 0;
}
