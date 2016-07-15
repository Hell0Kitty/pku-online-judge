#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
#define Max 0x1fffffff
#define SIZE 200
vector<pair<int, int> > jeo;
struct edge {
  int from, to, val, next;
} e[14000000];
int v[SIZE], que[SIZE], dis[SIZE], cnt, cur[SIZE];
void insert(int from, int to, int va) {
  e[cnt].from = from, e[cnt].to = to;
  e[cnt].val = va;
  e[cnt].next = v[from];
  v[from] = cnt++;
  e[cnt].from = to, e[cnt].to = from;
  e[cnt].val = 0;
  e[cnt].next = v[to];
  v[to] = cnt++;
}
bool bfs(int n, int s, int t) {
  int head, tail, id;

  head = tail = 0;
  que[tail++] = s;

  memset(dis, -1, sizeof(int) * n);
  dis[s] = 0;

  while (head < tail)

    for (id = v[que[head++]]; id != -1; id = e[id].next)

      if (e[id].val > 0 && dis[e[id].to] == -1)

      {
        dis[e[id].to] = dis[e[id].from] + 1;

        que[tail++] = e[id].to;

        if (e[id].to == t) return true;
      }

  return false;
}

int Dinic(int n, int s, int t)

{
  int maxflow = 0, tmp, i;

  while (bfs(n, s, t))

  {
    int u = s, tail = 0;

    for (i = 0; i < n; i++) cur[i] = v[i];

    while (cur[s] != -1)

      if (u != t && cur[u] != -1 && e[cur[u]].val > 0 && dis[u] != -1 &&
          dis[u] + 1 == dis[e[cur[u]].to])

      {
        que[tail++] = cur[u];
        u = e[cur[u]].to;
      }

      else if (u == t)

      {
        for (tmp = Max, i = tail - 1; i >= 0; i--)
          tmp = min(tmp, e[que[i]].val);

        for (maxflow += tmp, i = tail - 1; i >= 0; i--)

        {
          e[que[i]].val -= tmp;

          e[que[i] ^ 1].val += tmp;

          if (e[que[i]].val == 0) tail = i;
        }

        u = e[que[tail]].from;

      }

      else

      {
        while (tail > 0 && u != s && cur[u] == -1) u = e[que[--tail]].from;

        cur[u] = e[cur[u]].next;
      }
  }

  return maxflow;
}

int num[SIZE], ed[SIZE];

int m, p, tt;

bool build(int a, int b)

{
  memset(v, -1, sizeof(v));
  cnt = 0;

  int s = 0, t = 101;

  for (int i = 1; i <= 100; i++)
    if (i % 7 != a && i % 7 != b) insert(s, i, p / 2);

  memset(num, 0, sizeof(num));
  memset(ed, 0, sizeof(ed));

  for (int i = 0; i < m; i++)

  {
    num[jeo[i].second]++;

    for (int j = jeo[i].first; j < jeo[i].second; j++) ed[j]++;
  }

  for (int i = 1; i <= 100; i++) insert(i, t, num[i]), insert(i, i + 1, ed[i]);

  return Dinic(t + 1, s, t) == m;
}

int main() {
  scanf("%d", &tt);
  while (tt--) {
    scanf("%d%d", &m, &p);
    jeo.clear();
    for (int i = 0; i < m; i++) {
      int a, b;
      scanf("%d%d", &a, &b);

      jeo.push_back(make_pair(a, b));
    }
    if (build(6, 0))
      printf("fine\n");
    else if (build(-1, -1))
      printf("weekend work\n");
    else
      printf("serious trouble\n");
  }
  return 0;
}
