#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 100005
#define maxk 32

int sum[maxn][maxk], c[maxn][maxk];
int head[maxn], next[maxn], v[maxn], ecount;
int n, p;

void addedge(int a, int b) {
  next[ecount] = head[a];
  head[a] = ecount;
  v[ecount] = b;
  ecount++;
}

int hash(int c[]) {
  int ret = 0;
  for (int i = 0; i < p; i++) ret = ((ret << 2) + (c[i] >> 4)) ^ (c[i] << 10);
  ret = (ret % maxn + maxn) % maxn;
  return ret;
}

void input() {
  memset(sum, 0, sizeof(sum));
  memset(c, 0, sizeof(c));
  memset(head, -1, sizeof(head));
  scanf("%d%d", &n, &p);
  ecount = 0;
  int ans = 0;
  addedge(hash(c[0]), 0);
  for (int i = 1; i <= n; i++) {
    int a;
    scanf("%d", &a);
    for (int j = 0; j < p; j++) {
      sum[i][j] = sum[i - 1][j] + (1 & a);
      a >>= 1;
    }
    for (int j = 0; j < p; j++) c[i][j] = sum[i][j] - sum[i][0];
    int h = hash(c[i]);
    for (int j = head[h]; j != -1; j = next[j]) {
      int ok = true;
      for (int k = 0; k < p; k++)
        if (c[v[j]][k] != c[i][k]) {
          ok = false;
          break;
        }
      if (ok && ans < i - v[j]) ans = i - v[j];
    }
    addedge(h, i);
  }
  printf("%d\n", ans);
}

int main() {
  input();
  return 0;
}
