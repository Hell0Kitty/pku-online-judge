#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define N 40005
struct node {
  int v, l;
  node(){};
  node(int _v, int _l) : v(_v), l(_l){};
};
vector<node> g[N];
bool done[N], vis[N];
int n, m, K, size, ans, root, s[N], f[N], d[N];
vector<int> dep;

void dfs(int now) {
  int u;
  vis[now] = true;
  s[now] = 1;
  for (int i = 0; i < g[now].size(); i++) {
    u = g[now][i].v;
    if (!vis[u]) {
      dfs(u);
      s[now] += s[u];
    }
  }
}
void getroot(int now, int fa) {
  int u;
  f[now] = 0;
  s[now] = 1;
  for (int i = 0; i < g[now].size(); i++)
    if ((u = g[now][i].v) != fa && !done[u]) {
      getroot(u, now);
      s[now] += s[u];
      f[now] = max(f[now], s[u]);
    }
  f[now] = max(f[now], size - s[now]);
  if (f[now] < f[root]) root = now;
}
void getdep(int now, int fa) {
  dep.push_back(d[now]);
  int u;
  s[now] = 1;
  for (int i = 0; i < g[now].size(); i++)
    if ((u = g[now][i].v) != fa && !done[u]) {
      d[u] = d[now] + g[now][i].l;
      getdep(u, now);
      s[now] += s[u];
    }
}
int calc(int now, int init) {
  d[now] = init;
  dep.clear();
  getdep(now, 0);
  sort(dep.begin(), dep.end());
  int ret = 0;
  for (int l = 0, r = dep.size() - 1; l < r;)
    if (dep[l] + dep[r] <= K)
      ret += r - l++;
    else
      r--;
  return ret;
}
void work(int now) {
  ans += calc(now, 0);
  int u;
  done[now] = true;
  for (int i = 0; i < g[now].size(); i++)
    if (!done[u = g[now][i].v]) {
      ans -= calc(u, g[now][i].l);
      f[0] = size = s[u];
      getroot(u, root = 0);
      work(root);
    }
}
int main() {
  char ch;
  int a, b, l;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d %c", &a, &b, &l, &ch);
    g[a].push_back(node(b, l));
    g[b].push_back(node(a, l));
  }
  scanf("%d", &K);

  memset(done, false, sizeof(done));
  memset(vis, false, sizeof(vis));
  for (int i = 1; i <= n; i++)
    if (!vis[i]) dfs(i);

  ans = 0;
  for (int i = 1; i <= n; i++)
    if (!done[i]) {
      f[0] = size = s[i];
      getroot(i, root = 0);
      work(root);
    }

  printf("%d\n", ans);
  return 0;
}
