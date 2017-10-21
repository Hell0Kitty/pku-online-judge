#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INFINITE 900000000

const int maxn = 100;

struct XEdge {
  int s;
  int v;  //边端点
  int w;  //边权值
  XEdge(int s_ = 0, int v_ = 0, int w_ = INFINITE) : s(s_), v(v_), w(w_) {}
};

vector<vector<XEdge> > G(maxn);  //图的邻接表

int n, m, maxval[maxn][maxn], map[maxn][maxn];
bool used[maxn][maxn];

void init() {
  int i, a, b, d;

  memset(used, 0, sizeof(used));
  memset(maxval, 0, sizeof(maxval));
  memset(map, 0, sizeof(map));
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++) G[i].clear();
  for (i = 0; i < m; i++) {
    scanf("%d%d%d", &a, &b, &d);
    a--;
    b--;
    G[a].push_back(XEdge(a, b, d));
    G[b].push_back(XEdge(b, a, d));
    map[a][b] = map[b][a] = d;
  }
}

bool operator<(const XEdge &e1, const XEdge &e2) { return e1.w > e2.w; }

void dp(vector<int> &vUsed, int u, int w) {
  int v, i;

  for (i = 0; i < n; i++) {
    v = i;
    maxval[v][u] = _cpp_max(w, maxval[v][u]);
    maxval[u][v] = maxval[v][u];
  }
}

int HeapPrim(const vector<vector<XEdge> > &G)
// G是邻接表,n是顶点数目，返回值是最小生成树权值和
{
  int i;
  XEdge xDist(0, 0);
  priority_queue<XEdge> pq;
  vector<int> vDist(n);  //各顶点到已经建好的那部分树的距离
  vector<int> vUsed(n);  //标记顶点是否已经被加入最小生成树
  int nDoneNum = 0;      //已经被加入最小生成树的顶点数目
  for (i = 0; i < n; i++) {
    vUsed[i] = 0;
    vDist[i] = INFINITE;
  }
  nDoneNum = 0;
  int nTotalW = 0;
  pq.push(XEdge(0, 0, 0));
  while (nDoneNum < n && !pq.empty()) {
    do {
      xDist = pq.top();
      pq.pop();
    } while (vUsed[xDist.v] == 1 && !pq.empty());
    if (vUsed[xDist.v] == 0) {
      nTotalW += xDist.w;
      vUsed[xDist.v] = 1;
      used[xDist.s][xDist.v] = true;
      used[xDist.v][xDist.s] = true;
      dp(vUsed, xDist.v, xDist.w);
      nDoneNum++;
      for (i = 0; i < G[xDist.v].size(); i++) {
        int k = G[xDist.v][i].v;
        if (vUsed[k] == 0) {
          int w = G[xDist.v][i].w;
          if (vDist[k] > w) {
            vDist[k] = w;
            pq.push(XEdge(xDist.v, k, w));
          }
        }
      }
    }
  }
  if (nDoneNum < n) return -1;  //图不连通
  return nTotalW;
}

bool unique() {
  int i, j;

  for (i = 0; i < n; i++)
    for (j = i; j < n; j++)
      if (map[i][j] && !used[i][j] && maxval[i][j] == map[i][j]) return false;
  return true;
}

int main() {
  int t, ans;
  bool ok;
  scanf("%d", &t);
  while (t--) {
    init();
    ans = HeapPrim(G);
    ok = unique();
    if (ok)
      printf("%d\n", ans);
    else
      printf("Not Unique!\n");
  }
  return 0;
}
