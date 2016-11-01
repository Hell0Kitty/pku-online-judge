#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX_NODE_NUM 1505
#define INF 0x3f3f3f3f

struct Edge {
  int v;
  int weight;
  int length;
  Edge() {}
  Edge(int v, int length, int weight) : v(v), length(length), weight(weight) {}
} dist[MAX_NODE_NUM];

int node_num, road_num;
int origin, destination;
int least_fee[MAX_NODE_NUM];
bool vis[MAX_NODE_NUM];
int push_cnt[MAX_NODE_NUM];

vector<vector<Edge> > G;
vector<vector<Edge> > R;

void addedge(vector<vector<Edge> > &G, int u, int v, int length, int weight) {
  G[u].push_back(Edge(v, length, weight));
}

void input() {
  fill(least_fee, least_fee + node_num, INF);
  G.clear();
  G = vector<vector<Edge> >(node_num);
  for (int i = 0; i < road_num; i++) {
    int u, v, l, fuv, fvu;
    char st[50];
    scanf("%s", st);
    sscanf(st, "(%d,%d,%d[%d]%d)", &u, &v, &fuv, &l, &fvu);
    addedge(G, u, v, l, fuv);
    addedge(G, v, u, l, fvu);
    least_fee[u] = min(least_fee[u], fuv);
    least_fee[v] = min(least_fee[v], fvu);
  }
}

void clean_edge() {
  for (int i = 0; i < node_num; i++) {
    int j = 0;
    for (vector<Edge>::iterator j = G[i].begin(); j != G[i].end();) {
      if (j->weight > least_fee[i])
        j = G[i].erase(j);
      else
        j++;
    }
  }
}

void reverse_graph() {
  R.clear();
  R = vector<vector<Edge> >(node_num);
  for (int i = 0; i < node_num; i++) {
    for (vector<Edge>::iterator j = G[i].begin(); j != G[i].end(); j++)
      addedge(R, j->v, i, j->length, j->weight);
  }
}

void dfs(int id) {
  if (vis[id]) return;
  vis[id] = true;
  for (vector<Edge>::iterator i = R[id].begin(); i != R[id].end(); i++)
    dfs(i->v);
}

void clean_node() {
  for (int i = 0; i < node_num; i++) {
    if (!vis[i]) {
      G[i].clear();
      continue;
    }
    for (vector<Edge>::iterator j = G[i].begin(); j != G[i].end();) {
      if (!vis[j->v])
        j = G[i].erase(j);
      else
        j++;
    }
  }
}

bool relax(Edge &dist, int length, int weight) {
  if (dist.weight > weight || (dist.weight == weight && dist.length > length)) {
    dist.weight = weight;
    dist.length = length;
    return true;
  }
  return false;
}

void SPFA() {
  fill(dist, dist + node_num, Edge(-1, INF, INF));
  memset(push_cnt, 0, sizeof(push_cnt));
  queue<Edge> q;
  q.push(Edge(origin, 0, 0));
  dist[origin] = Edge(-1, 0, 0);
  bool unbound = false;
  while (!q.empty()) {
    Edge temp = q.front();
    q.pop();
    for (vector<Edge>::iterator i = G[temp.v].begin(); i != G[temp.v].end();
         i++) {
      if (relax(dist[i->v], temp.length + i->length, temp.weight + i->weight)) {
        q.push(Edge(i->v, dist[i->v].length, dist[i->v].weight));
        push_cnt[i->v]++;
        if (push_cnt[i->v] > node_num) {
          puts("UNBOUND");
          return;
        }
      }
    }
  }
  printf("%d %d\n", dist[destination].weight, dist[destination].length);
}

int main() {
  while (scanf("%d%d%d%d", &node_num, &road_num, &origin, &destination) !=
         EOF) {
    input();
    clean_edge();
    reverse_graph();
    memset(vis, 0, sizeof(vis));
    dfs(destination);
    if (!vis[origin]) {
      puts("VOID");
      continue;
    }
    clean_node();
    SPFA();
  }
  return 0;
}
