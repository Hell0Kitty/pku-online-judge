

#include <iostream>

using namespace std;

bool visited[205];
int house[205][2];
int man[205][2];
char str[205];

struct Node {
  int pre, flow, cost;

} label[205];

struct edge {
  int cap, currentflow;
  int unitcost;

} network[205][205];

void intialNode(int n) {
  for (int i = 0; i < n; i++)
    label[i].cost = 1000000000, label[i].flow = 0, label[i].pre = 0;
}

void IntialEdge(int n) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      network[i][j].cap = network[i][j].unitcost = network[i][j].currentflow =
          0;
}

struct Vertix {
  int vertix, cost;
  Vertix(int v = 0, int c = 0) : vertix(v), cost(c) {}
  bool operator>(const Vertix &lhs) const { return (lhs.cost < cost); }
};

bool modefiedDijkstra(int n, int s, int t) {
  intialNode(n);
  fill_n(visited, n, false);
  Vertix w;
  w.cost = 0, w.vertix = s;
  label[s].pre = -1, label[s].flow = 1000000000, label[s].cost = 0;
  int v = 0, u = 0;

  while (true) {
    int minv = 10000000000;
    for (int w = 0; w < n; w++)
      if (!visited[w] && label[w].cost < minv) {
        v = w, minv = label[w].cost;
      }
    if (v == t)
      if (label[t].cost >= 1000000000)
        return false;
      else
        return true;

    visited[v] = true;
    for (u = 0; u < n; u++)
      if (!visited[u]) {
        if (network[v][u].cap > 0 &&
            network[v][u].cap - network[v][u].currentflow > 0 &&
            label[v].cost + network[v][u].unitcost < label[u].cost) {
          label[u].pre = v;
          label[u].cost = label[v].cost + network[v][u].unitcost;

          label[u].flow =
              min(label[v].flow, network[v][u].cap - network[v][u].currentflow);
        } else if (network[u][v].cap > 0 && network[u][v].currentflow > 0 &&
                   label[v].cost - network[u][v].unitcost < label[u].cost) {
          label[u].pre = v;

          label[u].flow = min(label[v].flow, network[u][v].currentflow);
          label[u].cost = label[v].cost - network[u][v].unitcost;
        }
      }
  }
}

void arguementpath(int t) {
  for (int k = t; k != -1; k = label[k].pre) {
    if (network[label[k].pre][k].cap > 0)
      network[label[k].pre][k].currentflow += label[t].flow;
    else
      network[k][label[k].pre].currentflow -= label[t].flow;
  }
}

void MaxFlowMincostAlgorithm(int n, int s, int t) {
  int mincost = 0;
  while (modefiedDijkstra(n, s, t)) {
    arguementpath(t);
    mincost += label[t].cost;
  }
  printf("%d\n", mincost);
}

void add(int x, int y, int cap, int cost) {
  network[x][y].cap += cap;
  network[x][y].unitcost += cost;
}

int ABS(int num) { return num > 0 ? num : (-num); }

int main() {

  int N, M, m, h, i, j;
  while (scanf("%d%d", &N, &M) && (N || M)) {
    m = 0, h = 0;
    for (i = 0; i < N; i++) {
      scanf("%s", &str);
      for (j = 0; j < M; j++) {
        if (str[j] == 'H') {
          house[h][0] = i;
          house[h][1] = j;
          h++;
          continue;
        }
        if (str[j] == 'm') {
          man[m][0] = i;
          man[m][1] = j;
          m++;
          continue;
        }
      }
    }
    IntialEdge(m + h + 2);
    for (i = 0; i < m; i++)
      add(0, i + 1, 1, 0);
    for (i = 0; i < m; i++) {
      for (j = 0; j < h; j++) {
        int weight =
            ABS(man[i][0] - house[j][0]) + abs(man[i][1] - house[j][1]);
        add(i + 1, m + j + 1, 1, weight);
      }
    }
    for (j = 0; j < h; j++)
      add(m + j + 1, m + h + 1, 1, 0);
    MaxFlowMincostAlgorithm(m + h + 2, 0, m + h + 1);
  }
  return 0;
}
