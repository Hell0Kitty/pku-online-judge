#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int n, m;
int r[200], sc[200], k[200], f[200][200];
int dr[200], dc[200];
void input() {
  scanf("%d %d", &n, &m);
  int i, j;
  for (i = 0; i < n; ++i) {
    scanf("%d %d %d", r + i, sc + i, k + i);
    for (j = 0; j < k[i]; ++j) {
      scanf("%d", f[i] + j);
      --f[i][j];
    }
  }
  for (i = 0; i < m; ++i) scanf("%d %d", dr + i, dc + i);
}

struct elem {
  int uv, id;
};

bool operator<(const elem &a, const elem &b) {
  if (r[a.id] == dr[a.uv]) {
    if (r[b.id] == dr[b.uv])
      return sc[a.id] > sc[b.id];
    else
      return 10 * sc[a.id] > 7 * sc[b.id];
  } else {
    if (r[b.id] == dr[b.uv])
      return 7 * sc[a.id] >= 10 * sc[b.id];
    else
      return sc[a.id] > sc[b.id];
  }
}

int usd[200], tsd[200];
void match() {
  memset(usd, -1, sizeof(usd));
  memset(tsd, 0, sizeof(tsd));
  vector<priority_queue<elem> > sts;
  priority_queue<elem> tmp;
  int i, cs;
  for (i = 0; i < m; ++i) sts.push_back(tmp);
  elem atmp, btmp;
  queue<int> qu;
  for (i = 0; i < n; ++i)
    if (k[i] > 0) qu.push(i);
  while (!qu.empty()) {
    cs = qu.front();
    qu.pop();
    atmp.id = cs;
    atmp.uv = f[cs][tsd[cs]];
    ++tsd[cs];
    if (sts[atmp.uv].size() < dc[atmp.uv]) {
      sts[atmp.uv].push(atmp);
      usd[atmp.id] = atmp.uv;
    } else {
      if (atmp.uv >= m || dc[atmp.uv] == 0) {
        if (tsd[atmp.id] < k[atmp.id]) qu.push(atmp.id);
      } else {
        btmp = sts[atmp.uv].top();
        if (atmp < btmp) {
          sts[atmp.uv].pop();
          sts[atmp.uv].push(atmp);
          usd[atmp.id] = atmp.uv;
          usd[btmp.id] = -1;
          if (tsd[btmp.id] < k[btmp.id]) qu.push(btmp.id);
        } else {
          if (tsd[atmp.id] < k[atmp.id]) qu.push(atmp.id);
        }
      }
    }
  }
}
void output() {
  int i;
  for (i = 0; i < n; ++i)
    if (usd[i] < 0)
      printf("not accepted\n");
    else
      printf("%d\n", usd[i] + 1);
}
int main() {
  int cs, i;
  scanf("%d", &cs);
  for (i = 0; i < cs; ++i) {
    input();
    match();
    if (i) printf("\n");
    output();
  }
  return 0;
}
