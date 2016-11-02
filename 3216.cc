#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0X1f1f1f1f;
#define clr(x) memset(x, 0, sizeof(x))

struct Task
{
    int p;
    int t;
    int d;
}task[210];

struct Edge
{
    int next;
    int to;
}edge[1000000];
int tot;
int head[210];

int link[210];
int vis[210];
int G[25][25], dis[25][25];
int sum, n;
int Q, M;

void floyd()
{
    for(int k = 0; k < Q; ++k)
    for(int i = 0; i < Q; ++i) {
        for(int j = 0; j < Q; ++j)
          G[i][j] = G[i][j] < G[i][k]+G[k][j]?G[i][j]:G[i][k]+G[k][j];
    }
  }

void add(int s, int u)
{
    edge[tot].to = u;
    edge[tot].next = head[s];
    head[s] = tot++;
}

int dfs(int x)
{
    for(int i = head[x]; i != 0; i = edge[i].next){
        int y = edge[i].to;
        if(!vis[y]){
            vis[y] = true;
            if(link[y] == 0 || dfs(link[y])){
                link[y] = x;
                return true;
            }
        }
    }
    return false;
}

void solve()
{
    clr(link);
    sum = 0;
    for(int i = 1; i <= n; ++i){
        clr(vis);
        if(dfs(i))
            sum++;
    }
}

int main()
{
    int i, j, k;
    while(scanf("%d %d", &Q, &M) != EOF)
    {
        if(Q == 0 || M == 0) break;
        clr(G), clr(dis), clr(head);
        n = M;
        tot = 1;

        for(i = 0; i < Q; ++i)
        for(j = 0; j < Q; ++j) {
            scanf("%d", &G[i][j]);
            if(G[i][j] == -1) G[i][j] = INF;
        }
        for(i = 1; i <= n; ++i)
            scanf("%d %d %d", &task[i].p, &task[i].t, &task[i].d);

        floyd();
        for(i = 1; i <= n; ++i)
        for(j = 1; j <= n; ++j)
        if(i != j) {
            if(task[i].d + task[i].t + G[task[i].p-1][task[j].p-1] <= task[j].t)
            add(i, j);
        }
        solve();

        printf("%d\n", n-sum);
    }
    return 0;
}



