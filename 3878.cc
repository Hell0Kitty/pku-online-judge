#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 0x3fffffff;

class Sssp {
  struct edge {
    int to, weight;
    edge(int t, int w) : to(t), weight(w) {}
  };
  vector<vector<edge>> adj;
  vector<int> dist;

 public:
  void init(int nodes) {
    adj.clear();
    adj.resize(nodes);
    dist.resize(nodes);
    fill(dist.begin(), dist.end(), INF);
  }
  void addedge(int node, int dest, int wei) {
    edge ed(dest, wei);
    adj[node].push_back(ed);
  }
  int spfa();
};

int Sssp::spfa() {
  queue<int> q;
  vector<int> cnt(adj.size(), 0);
  vector<bool> inq(adj.size(), false);
  q.push(0);
  inq[0] = true;
  dist[0] = 0;
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    inq[node] = false;
    for (int i = 0; i < adj[node].size(); ++i) {
      int dest = adj[node][i].to;
      int wei = adj[node][i].weight;
      if (dist[dest] > dist[node] + wei) {
        if (dest == 0) return -INF;
        dist[dest] = dist[node] + wei;
        ++cnt[dest];
        if (cnt[dest] >= adj.size()) return -INF;
        if (!inq[dest]) {
          q.push(dest);
          inq[dest] = true;
        }
      }
    }
  }
  return dist[adj.size() - 1];
}

enum status { entry, grass, stone, hole, out };
status graphic[30][30];
int w, h;
Sssp sssp;

inline int getnode(int x, int y) { return x * h + y; }

void solve() {
  scanf("%d %d", &w, &h);
  if (w == 0 && h == 0) exit(0);
  sssp.init(w * h);
  fill(graphic[0], graphic[30], grass);
  graphic[0][0] = entry;
  graphic[w - 1][h - 1] = out;
  int gsto;
  scanf("%d", &gsto);
  while (--gsto >= 0) {
    int x, y;
    scanf("%d %d", &x, &y);
    graphic[x][y] = stone;
  }
  int hunthole;
  scanf("%d", &hunthole);
  while (--hunthole >= 0) {
    int x1, y1, x2, y2, t;
    scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &t);
    graphic[x1][y1] = hole;
    sssp.addedge(getnode(x1, y1), getnode(x2, y2), t);
  }
  static int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  for (int i = 0; i < w; ++i)
    for (int j = 0; j < h; ++j) {
      if (graphic[i][j] == grass || graphic[i][j] == entry) {
        int node = getnode(i, j);
        for (int k = 0; k < 4; ++k) {
          int x = i + dir[k][0];
          int y = j + dir[k][1];
          if (x >= w || x < 0 || y >= h || y < 0) continue;
          if (graphic[x][y] != stone) {
            sssp.addedge(node, getnode(x, y), 1);
          }
        }
      }
    }
  int dest = sssp.spfa();
  if (dest == -INF)
    printf("Never\n");
  else if (dest == INF)
    printf("Impossible\n");
  else
    printf("%d\n", dest);
}

int main() {
  while (true) solve();
  return 0;
}
