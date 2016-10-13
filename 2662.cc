#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1010;
const int inf  = 0x3f3f3f3f;
int  G[maxn][maxn];
int  dis[maxn];
bool vis[maxn];
int  n, m, source, sink, ans;

void Dijkstra() {
    memset(dis, inf, sizeof(dis));
    memset(vis, false, sizeof(vis));
    dis[sink] = 0;
    for(int i = 1; i <= n; ++i) {
        int minD = inf, u = -1;
        for(int j = 1; j <= n; ++j) {
            if(!vis[j] && dis[j] < minD) {
                u = j;
                minD = dis[j];
            }
        }
        if(u == -1) break;
        vis[u] = true;
        for(int j = 1; j <= n; ++j) {
            if(!vis[j] && dis[j] > dis[u] + G[u][j]) {
                dis[j] = dis[u] + G[u][j];
            }
        }
    }
    return ;
}

int dp[maxn];

/**DAG涓婄殑鍔ㄦ�瑙勫垝**/
int dfs(int u) {
    if(dp[u] != -1) {
        return dp[u];
    }
    int t = 0;
    for(int i = 1; i <= n; ++i) {
        if(G[u][i] < inf && dis[u] > dis[i]) {
            t += dfs(i);
        }
    }
    dp[u] = t;
    return dp[u];
}

int main() {
    int u, v, w;
    while(scanf("%d", &n) && n) {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(i == j) G[i][j] = 0;
                else G[i][j] = inf;
            }
        }
        scanf("%d", &m);
        for(int i = 1; i <= m; ++i) {
            scanf("%d %d %d", &u, &v, &w);
            G[u][v] = G[v][u] = min(G[u][v], w);
        }
        source = 1, sink = 2; ans = 0;
        Dijkstra();
        memset(dp, -1, sizeof(dp));
        dp[sink] = 1;
        dfs(source);
        printf("%d\n", dp[source]);
    }
    return 0;
}



