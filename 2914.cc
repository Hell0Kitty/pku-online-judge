#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#define eps 1.0e-20
using namespace std;
#define mo 1000000000
#define inf 1000000000

int cap[505][505];
int node[505], dis[505];
int Stoer_Wagner(int n) {
  int i, j, now, ans = 0x3fffffff;
  for (int i = 0; i < n; i++) node[i] = i;
  while (n > 1) {
    for (now = 0, i = 1; i < n; i++) dis[node[i]] = 0;
    for (i = 1; i < n; i++) {
      swap(node[now], node[i - 1]);
      for (now = j = i; j < n; j++) {
        dis[node[j]] += cap[node[i - 1]][node[j]];
        if (dis[node[now]] < dis[node[j]]) now = j;
      }
    }
    ans = min(ans, dis[node[now]]);
    for (j = 0; j < n; j++)
      cap[node[j]][node[now - 1]] = cap[node[now - 1]][node[j]] +=
          cap[node[j]][node[now]];
    node[now] = node[--n];
  }
  return ans;
}

int n, m;

int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    memset(cap, 0, sizeof(cap));
    for (int i = 1, a, b, c; i <= m; i++) {
      scanf("%d%d%d", &a, &b, &c);
      cap[a][b] += c;
      cap[b][a] += c;
    }
    printf("%d\n", Stoer_Wagner(n));
  }

  return 0;
}
