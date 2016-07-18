#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int int_inf = 0x3f3f3f3f;

#define maxn 1010
#define maxm 200010
#define x first
#define y second

int ne;
int n, m;
int d[maxn];
bool flag[maxn];
int inq[maxn];

struct edge {
  int to, dist;
  int flag;
  edge *next;
} e[maxm], *head[maxn];

struct pii {
  int x, y;
};

inline pii mp(int x, int y) {
  pii now;
  now.x = x;
  now.y = y;
  return now;
}

inline bool operator<(const pii &a, const pii &b) {
  return a.y + d[a.x] > b.y + d[b.x];
}

inline void add_edge(int from, int to, int dist, int flag) {
  e[ne].to = to;
  e[ne].flag = flag;
  e[ne].dist = dist;
  e[ne].next = head[from];
  head[from] = &e[ne++];
}

inline void spfa(int s) {
  queue<int> q;
  q.push(s);
  flag[s] = 1;
  for (int i = 1; i <= n; i++) d[i] = int_inf;
  d[s] = 0;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (edge *p = head[x]; p; p = p->next) {
      if (!p->flag) continue;
      if (d[x] + p->dist < d[p->to]) {
        d[p->to] = d[x] + p->dist;
        if (!flag[p->to]) {
          q.push(p->to);
          flag[p->to] = 1;
        }
      }
    }
    flag[x] = 0;
  }
}

inline void k_th(int s, int t, int k) {
  priority_queue<pii> q;
  if (s == t) k++;
  for (int i = 1; i <= n; i++) inq[i] = 0;
  q.push(mp(s, 0));
  while (!q.empty()) {
    pii now = q.top();
    q.pop();
    inq[now.x]++;
    if (inq[t] == k) {
      printf("%d\n", now.y);
      while (!q.empty()) q.pop();
      return;
    }
    for (edge *p = head[now.x]; p; p = p->next) {
      if (p->flag) continue;
      if (inq[p->to] > k) continue;
      q.push(mp(p->to, now.y + p->dist));
    }
  }
  puts("-1");
}

int main() {
  while (scanf("%d%d", &n, &m) == 2) {
    ne = 0;
    for (int i = 1; i <= n; i++) head[i] = 0;
    for (int i = 1; i <= m; i++) {
      int x, y, z;
      scanf("%d%d%d", &x, &y, &z);
      add_edge(x, y, z, 0);
      add_edge(y, x, z, 1);
    }
    int s, t, k;
    scanf("%d%d%d", &s, &t, &k);
    spfa(t);
    if (d[s] == int_inf) {
      puts("-1");
      continue;
    }
    k_th(s, t, k);
  }
  return 0;
}
