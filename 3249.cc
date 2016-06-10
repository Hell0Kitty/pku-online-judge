#include <iostream>
#include <queue>
#include <cstdio>
#include <string.h>
using namespace std;
#define N 100100
#define M 1000100
#define INF 1 << 29

struct node {
  int v;
  int next;
} edge[M];

int dp[N];        // 最大价值
int enext[N];     //记录节点
int indegree[N];  //入度
int cost[N];      //价值
int res;
int idx;
std::queue<int> q;

int m, n, a, b, i, j;
void input() {
  for (i = 1; i <= n; i++) {
    scanf("%d", &cost[i]);
    dp[i] = -INF;
    indegree[i] = 0;
  }

  idx = 0;

  memset(enext, -1, sizeof(enext));

  for (i = 1; i <= m; i++) {
    scanf("%d %d", &a, &b);
    edge[idx].v = b;
    edge[idx].next = enext[a];
    enext[a] = idx++;
    indegree[b]++;
  }
  while (!q.empty()) q.pop();
  for (i = 1; i <= n; i++)
    if (!indegree[i]) q.push(i), dp[i] = cost[i];
}

int dag() {
  res = -INF;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    bool flag = true;
    int nextid;
    for (i = enext[cur]; i != -1; i = edge[i].next) {
      flag = false;
      nextid = edge[i].v;

      if (dp[nextid] < cost[nextid] + dp[cur])
        dp[nextid] = cost[nextid] + dp[cur];
      indegree[nextid]--;
      if (!indegree[nextid]) {
        q.push(nextid);
      }
    }
    if (flag && dp[cur] > res) res = dp[cur];
  }
  return res;
}

int main() {
  while (scanf("%d %d", &n, &m) != EOF) {
    input();
    printf("%d\n", dag());
  }
  return 0;
}
