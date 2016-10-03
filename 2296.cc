#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define clr(a,x) memset(a,x,sizeof(a))

const int N=222,M=22222;

int dfn[N],low[N],q[N],vis[N],id[N];
int head[N],ev[M],nxt[M];
int scc,e,idx,ed;

void init()
{
    clr(dfn,0);clr(vis,0);clr(head,-1);
    e=scc=idx=ed=0;
}
void add(int u,int v)
{
    ev[e]=v,nxt[e]=head[u];head[u]=e++;
}
void tarjan(int u)
{
    int i,v;
    dfn[u]=low[u]=++idx;
    vis[q[ed++]=u]=1;
    for(i=head[u];~i;i=nxt[i])
    {
        v=ev[i];
        if(!dfn[v]) tarjan(v),low[u]=min(low[u],low[v]);
        else if(vis[v]) low[u]=min(low[u],low[v]);
    }
    if(dfn[u]!=low[u]) return;
    do
    {
        id[v=q[--ed]]=scc;
        vis[v]=0;
    }while(v!=u);
    scc++;
}
int n,x[N],y[N];
bool jud(int mid)
{
    init();bool fg=1;
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++)
    {
        int a=abs(x[i]-x[j]),b=abs(y[i]-y[j]),u=i,d=j;
        if(y[d]>y[u]) swap(d,u);
        if(a>=mid||b>=mid*2) continue;
        if(b>=mid) add(d*2,u*2),add(u*2+1,d*2+1);
        else if(b>0) add(u*2+1,u*2),add(d*2,d*2+1);
        else add(u*2,d*2+1),add(u*2+1,d*2),add(d*2,u*2+1),add(d*2+1,u*2);
    }
    for(int i=0;i<n*2;i++) if(!dfn[i]) tarjan(i);
    for(int i=0;i<n;i++) if(id[i*2]==id[i*2+1]) fg=0;
    return fg;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d%d",&x[i],&y[i]);
        int low=0,up=40000,ans;
        while(low<=up)
        {
            int mid=(low+up)/2;
            if(jud(mid)) low=mid+1,ans=mid;
            else up=mid-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}



