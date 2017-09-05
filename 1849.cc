#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<pair<int, int> > edge[100010];
int step[100100];
int vis[100010];
int bfs(int &s) {
  int Max = 0;
  memset(vis, 0, sizeof(vis));
  queue<int> Q;
  Q.push(s);
  step[s] = 0;
  while (!Q.empty()) {
    int fr = Q.front();
    Q.pop();
    for (int i = 0; i < edge[fr].size(); i++) {
      int to = edge[fr][i].first, w = edge[fr][i].second;
      if (vis[to]) continue;
      step[to] = step[fr] + w;
      if (step[to] > Max) {
        Max = step[to];
        s = to;
      }
      vis[to] = 1;
      Q.push(to);
    }
  }
  return Max;
}
int main() {
  int n, s, i, a, b, w;
  while (scanf("%d%d", &n, &s) != EOF) {
    int sum = 0;
    for (i = 0; i < n - 1; i++) {
      scanf("%d%d%d", &a, &b, &w);
      sum += 2 * w;
      edge[a].push_back(make_pair(b, w));
      edge[b].push_back(make_pair(a, w));
    }
    bfs(s);
    int mm = bfs(s);
    printf("%d\n", sum - mm);
  }
}
