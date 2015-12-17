

#include <stdio.h>

const int INF = 500000;    // 无穷大
const int MAX_NODE = 120;  // 顶点数目
typedef int Graph[MAX_NODE][MAX_NODE];
typedef int Path[MAX_NODE];

void memset(Path a, int v, int n) {
  for (int i = 0; i < n; i++) a[i] = v;
}
int EdmondsKarp(Graph C, int n, int s, int t, Graph F) {
  int i, j, k, c, head, tail;
  Graph R;              // 残留网络
  Path prev, visit, Q;  // prev记录路径的前驱节点
  // 初始化流量网络和残留网络
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      F[i][j] = 0;
      R[i][j] = C[i][j];
    }
  }
  while (true) {
    // 在残留网络中找到一条 s 到 t 的最短路径
    head = tail = 0;
    memset(visit, 0, n);
    Q[tail++] = s;
    prev[s] = -1;
    visit[s] = 1;
    // BFS 从s到t的最短路径
    bool find = false;
    while (head < tail && !find) {
      k = Q[head++];
      for (i = 0; i < n; i++) {
        if (!visit[i] && R[k][i] > 0) {
          visit[i] = 1;
          prev[i] = k;
          if (i == t)  // 找到目标
          {
            find = true;
            break;
          }
          Q[tail++] = i;
        }
      }
    }
    // 如果残留网络中没有从s到t的路径，则流量已达到最大
    if (!visit[t]) break;

    // 找到可改进的流量c
    c = INF;
    j = t;
    while (j != s) {
      i = prev[j];
      if (c > R[i][j]) c = R[i][j];
      j = i;
    }
    // 下面改进流量
    j = t;
    while (j != s) {
      i = prev[j];
      F[i][j] = F[i][j] + c;
      F[j][i] = -F[i][j];
      R[i][j] = C[i][j] - F[i][j];
      R[j][i] = C[j][i] - F[j][i];
      j = i;
    }
  }
  // 计算最大流并返回
  c = 0;
  for (i = 0; i < n; i++) c += F[s][i];
  printf("%d\n", c);  // output the value of max flow
  return c;           // return answer
}
Graph C, F;
int n, s, t;
bool read_graph() {
  int i, j, N, np, nc, m;
  if (scanf("%d%d%d%d ", &N, &np, &nc, &m) == EOF) return false;
  n = N + 2, s = 1, t = n;
  for (i = 0; i <= n; i++)
    for (j = 0; j <= n; j++) C[i][j] = 0;
  int u, v, z;
  for (i = 0; i < m; i++) {
    scanf(" (%d,%d)%d ", &u, &v, &z);
    C[u + 2][v + 2] = z;
  }
  for (i = 0; i < np; i++) {
    scanf(" (%d)%d ", &u, &z);
    C[s][u+2] = z;
  }
  for(i=0; i<nc; i++)
  {
    scanf(" (%d)%d",&u,&z);
    C[u+2][t] = z;
  }
  return true;
}

int main()
{
  while(read_graph())
    EdmondsKarp(C,n+1,s,t,F);
  return 0;
}
