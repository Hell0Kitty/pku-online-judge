#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 105, maxm = maxn * maxn / 2, inf = 0x3f3f3f3f;

struct Edge {
  int a, b, w;
} edge[maxm];

int n, m;
int father[maxn];

bool operator<(const Edge &a, const Edge &b) { return a.w < b.w; }

void input() {
  for (int i = 0; i < m; i++) {
    int a, b, w;
    scanf("%d%d%d", &a, &b, &w);
    a--;
    b--;
    edge[i].a = a;
    edge[i].b = b;
    edge[i].w = w;
  }
}

int getanc(int a) {
  if (a == father[a]) return a;
  return father[a] = getanc(father[a]);
}

int cal(int l) {
  for (int i = 0; i < n; i++) father[i] = i;
  int i = l;
  int block_num = n;
  while (i < m && block_num > 1) {
    int a = getanc(edge[i].a);
    int b = getanc(edge[i].b);
    if (a != b) {
      block_num--;
      father[a] = b;
    }
    i++;
  }
  if (block_num > 1) return -1;
  return edge[i - 1].w - edge[l].w;
}

void work() {
  int ans = cal(0);
  if (ans == -1) {
    printf("-1\n");
    return;
  }
  for (int i = 1; i < m; i++) {
    if (edge[i].w == edge[i - 1].w) continue;
    int temp = cal(i);
    if (temp == -1) break;
    ans = min(ans, temp);
  }
  printf("%d\n", ans);
}

int main() {
  while (scanf("%d%d", &n, &m), n | m) {
    memset(edge, -1, sizeof(edge));
    input();
    sort(edge, edge + m);
    work();
  }
  return 0;
}
