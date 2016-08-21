#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 100000000
#define N 101
struct node
{
    int u,d,s,e;
    node(int a = 0,int b = 0,int c = 0,int f = 0)
    {
        u = a;
        d = b;
        s = c;
        e = f;
    }

}p;
vector<node> g[N];
int vis[N],d[N],n,m,src,dst;
bool operator<(const node &pp,const node &pt)
{
    return pp.d > pt.d;
}
int dij(int t)
{
    int i;
    memset(vis,0,sizeof(vis));
    for(i = 0; i <= n; ++i)
        d[i] = INF;
    p = node(src,t);
    d[src] = t;
    priority_queue<node> que;
    que.push(p);
    int u,v,w;
    while(!que.empty())
    {
        p = que.top();
        que.pop();
        u = p.u;
        if(vis[u])
            continue;
        vis[u] = 1;
        if(u == dst)
            return d[u] - d[src];

        for(i = 0; i < g[u].size(); ++i)
        {
            v = g[u][i].u;
            w = g[u][i].d;
            if(d[u] < g[u][i].s)
            {
                if(g[u][i].s + w < d[v])
                {
                    d[v] = g[u][i].s + w;
                    que.push(node(v,d[v]));
                }
            }
            else if(d[u] + w <= g[u][i].e && d[u] + w < d[v])
            {
                d[v] = d[u] + w;
                que.push(node(v,d[v]));
            }
        }
    }
    return INF;
}
int main()
{
    int x,y,s,e,c,mint,maxt;
    while(scanf("%d%d%d%d",&n,&m,&src,&dst) != EOF)
    {
        mint = INF;
        maxt = 0;
        memset(g,0,sizeof(g));
        while(m--)
        {
            scanf("%d%d%d%d%d",&x,&y,&s,&e,&c);
            if(e - s + 1 < c)
                continue;
            g[x].push_back(node(y,c,s,e));
            if(x == src)
            {
                mint = min(mint,s);
                maxt = max(maxt,s);
            }
        }
        int res = INF,tmp;

        for(x = mint; x <= maxt; ++x)
        {
            tmp = dij(x);
            if(tmp == INF)
                break;
            res = min(res,tmp);

        }
        printf(res == INF ? "Impossible\n":"%d\n",res);
    }
    return 0;
}



