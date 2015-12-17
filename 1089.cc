#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

const int EM = 50003;
const int INF = 1e9 + 7;

struct node {
  int u, v;
};
node edge[EM];

bool cmp(node a, node b) {
  if (a.u == b.u) return a.v > b.v;
  return a.u < b.u;
}

int main() {
  int n;
  int cnt = 0;

  scanf("%d", &n);
  while (n--) {
    scanf("%d %d", &edge[cnt].u, &edge[cnt].v);
    cnt++;
  }
  sort(edge, edge + cnt, cmp);
  printf("%d ", edge[0].u);
  int end = edge[0].v;
  for (int i = 1; i < cnt; i++) {
    if (edge[i].u > end) {
      printf("%d\n", end);
      printf("%d ", edge[i].u);
      end = edge[i].v;
    } else if (edge[i].v > end)
      end = edge[i].v;
  }
  printf("%d\n", end);
  return 0;
}