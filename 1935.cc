#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int maxx = 50001;

struct edge {
  edge() { w = 0; }
  int v, nex;
  int w;
};

edge e[maxx * 2];
int head[maxx * 2];
int n, m, pr = 1;
bool vis[maxx];
int dp[maxx][2];

/*
题目意思：有一个城市有n个村庄n-1条路将其联通，现在有个人从k点开始访问这n个城市中的m个地方，问需要走的最少的路程m<n
总的思想就是访问完以k为根的子树中所有要访问的节点并回来的路径减去距离k最远的点回到k的距离就是相应的一个状态即dp[k][0]
最后选择dp[k][0],dp[k][1]中较小的一个即可
http://poj.org/problem?id=1935
*/

void addedge(int a, int b, int w) {
  e[pr].v = b;
  e[pr].w = w;
  e[pr].nex = head[a];
  head[a] = pr;
  pr++;
}

int min(int a, int b) { return a < b ? a : b; }

int max(int a, int b) { return a > b ? a : b; }

void DFS(int p, int pre) {
  int ma = -1;
  int ss = 0;
  for (int l = head[p]; l; l = e[l].nex) {
    int son = e[l].v;
    if (son == pre) continue;
    DFS(son, p);
    if (vis[son] || dp[son][1] != 0) {
      ss++;  //总的思想就是访问完以k为根的子树中所有要访问的节点并回来的路径减去距离k最远的点回到k的距离就是相应的一个状态即dp[k][0]
      ma = max(
          ma,
          dp[son][1] - dp[son][0] +
              e[l].w);  //此处的dp[son][1]-dp[son][0]+e[l].w不能直接写成dp[son][0]+e[l].w
      //因为要找以son为根的数中距离son最长的要访问的节点
      // dp[son][0]其实指的是访问完以son为根的子树中
      dp[p][1] += (dp[son][1] + 2 * e[l].w);  //所有要访问的节点的最小路径
                                              //这样用dp[son][1]-dp[son][0]就表示访问完son为根的子树中所有要访问的节点
    }                                         //并回到根的距离减去访问son为根的子树中所有要访问节点后不回来的最短路径就能得到访问的节点中到son最远的
                                              //路径这正是要求的
  }
  if (ss >= 1) {
    dp[p][0] = dp[p][1] - ma;
  }
}

int main() {
  int x, y, we, point, i, k;
  memset(head, 0, sizeof(head));
  memset(vis, false, sizeof(vis));
  scanf("%d%d", &n, &k);
  for (i = 1; i < n; i++) {
    scanf("%d%d%d", &x, &y, &we);
    addedge(x, y, we);
    addedge(y, x, we);
  }
  scanf("%d", &m);
  while (m--) {
    scanf("%d", &point);
    vis[point] = true;
  }
  DFS(k, -1);
  int ans = min(dp[k][0], dp[k][1]);
  printf("%d\n", ans);
  return 0;
}
