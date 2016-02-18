#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CY 60
#define E 3000

struct re {
  int v, nxt;
} e[E];

char str[CY][CY];
int C[27][CY][CY], g[CY], m2[CY];
bool vis[CY], vst[CY][CY];
int K, N, M, H, W, idx;

void init() {
  idx = 0;
  memset(g, -1, sizeof(g));
}

void addedge(int u, int v) {
  e[idx].v = v;
  e[idx].nxt = g[u];
  g[u] = idx++;
}

int calc(int k, int i, int j) {
  return C[k][i - 1][j] + C[k][i][j - 1] - C[k][i - 1][j - 1] + 1;
}

void get_sum(int n, int m) {
  memset(C, 0, sizeof(C));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int u = str[i][j] - 'A';
      for (int k = 0; k < 27; ++k) {
        if (str[i][j] == '0')
          C[k][i][j] = calc(k, i, j);
        else {
          C[k][i][j] = calc(k, i, j);
          if (u != k) C[k][i][j]--;
        }
      }
    }
  }
}

int cal(int u, int i, int j) {
  return C[u][i][j] - C[u][i - H][j] - C[u][i][j - W] + C[u][i - H][j - W];
}

bool can(int u) {
  int area = H * W;
  for (int i = H; i <= N; ++i) {
    for (int j = W; j <= M; ++j) {
      if (cal(u, i, j) == area) {
        return true;
      }
    }
  }
  return false;
}

bool path(int u) {
  for (int i = g[u]; ~i; i = e[i].nxt) {
    int v = e[i].v;
    if (!vis[v]) {
      vis[v] = true;
      if (-1 == m2[v] || path(m2[v])) {
        m2[v] = u;
        return true;
      }
    }
  }
  return false;
}

int MaxMatch(int n) {
  memset(m2, -1, sizeof(m2));
  int res = 0;
  for (int i = 0; i < n; ++i) {
    memset(vis, false, sizeof(vis));
    if (path(i)) res++;
  }
  return res;
}

void print(int n, int m) {
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      if (j > 1) putchar(' ');
      printf("%d", C[1][i][j]);
    }
    puts("");
  }
}

int main(void) {
  int cas;
  scanf("%d", &cas);
  for (int Cas = 1; Cas <= cas; ++Cas) {
    scanf("%d%d%d%d%d", &K, &N, &M, &H, &W);
    init();
    memset(vst, false, sizeof(vst));
    int sum = 0;
    for (int k = 0; k < K; ++k) {
      for (int i = 1; i <= N; ++i) {
        scanf("%s", str[i] + 1);
      }
      get_sum(N, M);
      if (can(26))
        sum++;
      else {
        for (int i = 0; i < 26; ++i) {
          if (can(i)) vst[i][k + 26] = true;
        }
      }
    }
    for (int i = 0; i < CY; ++i) {
      for (int j = 0; j < CY; ++j) {
        if (vst[i][j]) addedge(i, j);
      }
    }
    sum += MaxMatch(26);
    printf("%d\n", sum);
  }
  return 0;
}
