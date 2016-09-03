#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

#define INF 0x3f3f3f3f
#define V 1005
#define E 20001

int pnt[E], cost[E], nxt[E];
int e, head[V], dist[V];
bool vis[V];
int cnt[V];

int relax(int u, int v, int c)
{
    if (dist[v] > dist[u] + c)
    {
        dist[v] = dist[u] + c;
        return 1;
    }
    return 0;
}

inline void addedge(int u, int v, int c)
{
    pnt[e] = v;
    cost[e] = c;
    nxt[e] = head[u];
    head[u] = e++;
}

int SPFA(int src, int n)
{
    int i;
    memset(cnt, 0, sizeof(cnt));
    memset(vis, false, sizeof(vis));
    for (i = 1; i <= n; ++i)
        dist[i] = INF;
    dist[src] = 0;
    queue<int> Q;
    Q.push(src);
    vis[src] = true;
    ++cnt[src];
    while (!Q.empty())
    {
        int u, v;
        u = Q.front();
        Q.pop();
        vis[u] = false;
        for (i = head[u]; i != -1; i = nxt[i])
        {
            v = pnt[i];
            if (1 == relax(u, v, cost[i]) && !vis[v])
            {
                Q.push(v);
                vis[v] = true;
                if ((++cnt[v]) > n)
                    return -1;
            }
        }
    }
    if (dist[n] == INF)
        return -2;
    return dist[n];
}

int main()
{
    int n, ml, md;
    int i, a, b, c;
    e = 0;
    scanf("%d%d%d", &n, &ml, &md);
    memset(head, -1, sizeof(head));
    for (i = 0; i < ml; ++i)
    {
        scanf("%d%d%d", &a, &b, &c);
        addedge(a, b, c);
    }
    for (i = 0; i < md; ++i)
    {
        scanf("%d%d%d", &a, &b, &c);
        addedge(b, a, -c);
    }
    printf("%d\n", SPFA(1, n));
    return 0;
}



