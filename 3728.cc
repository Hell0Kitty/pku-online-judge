#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 50010
#define Q 50010
#define M 50010
#define INF 0x3f3f3f3f

int val[N],tote,totea,totes;
int head[N];
struct edge{
    int u,v,next;
}e[5*M];
int __head[N];
struct ask{
    int u,v,lca,next;
}ea[5*Q];
int head__[N];
struct res{
    int n,next;
}es[5*Q];
bool vis[N];
int up[N],down[N],Max[N],Min[N],ans[Q],fa[N];

inline void add_edge(int u ,int v){
    e[tote].u = u; e[tote].v = v; 
    e[tote].next = head[u]; head[u] = tote++;
}
inline void add_ask(int u ,int v){
    ea[totea].u = u; ea[totea].v = v; ea[totea].lca = -1;
    ea[totea].next = __head[u]; __head[u] = totea++;
}
inline void add_ans(int u ,int k){
    es[totes].n = k; es[totes].next = head__[u]; head__[u] = totes++;
}

int updata(int v)
{
    if(v == fa[v]) return v;
    int par = fa[v];
    fa[v] = updata(fa[v]);
    up[v] = max( up[v] , max(up[par] , Max[par]-Min[v]) );
    down[v] = max( down[v] , max(down[par] , Max[v] - Min[par]));
    Max[v] = max(Max[v] , Max[par]);
    Min[v] = min(Min[v] , Min[par]);
    return fa[v];
}

void Tarjan(int u)
{
    for(int k=__head[u]; k!=-1; k=ea[k].next)
        if(vis[ea[k].v])
        {
            int v = ea[k].v;
            int lca = updata(v);
            add_ans(lca,k);
        }
    vis[u] = true; fa[u] = u;
    for(int k=head[u]; k!=-1; k=e[k].next)
        if(!vis[e[k].v])
        {
            int v = e[k].v;
            Tarjan(v);
            fa[v] = u;
        }

    for(int i=head__[u]; i!=-1; i=es[i].next)
    {
        int k = es[i].n , x = ea[k].u , y = ea[k].v;
        if(k&1) //反
        { k = k^1; swap(x,y); }
        k /= 2;
        updata(x); updata(y);
        ans[k] = max(up[x] , down[y]);
        ans[k] = max(ans[k] , Max[y] - Min[x]);
    }

}

int main()
{
    int n,q;
    while(scanf("%d",&n)!=EOF)
    {
        tote = totea = totes = 0;
        memset(head,-1,sizeof(head));
        memset(__head,-1,sizeof(__head));
        memset(head__,-1,sizeof(head__));
        memset(vis,false,sizeof(vis));
        memset(ans,0,sizeof(ans));

        for(int i=1; i<=n; i++){
            scanf("%d",&val[i]); 
            up[i] = down[i] = 0;
            Max[i] = Min[i] = val[i];
        }

        for(int i=1; i<n; i++){
            int u,v;
            scanf("%d%d",&u,&v);
            add_edge(u,v);
            add_edge(v,u);
        }

        scanf("%d",&q);
        for(int i=0; i<q; i++){
            int u,v;
            scanf("%d%d",&u,&v);
            add_ask(u,v);
            add_ask(v,u);
        }

        Tarjan(1);
        for(int i=0; i<q; i++) printf("%d\n",ans[i]);
    }
    return 0;
}




