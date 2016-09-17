#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>

#define N 1100
#define M 1000100

using namespace std;

int a[M],b[M];
int head[N],next[M],to[M];
int q[M*5],im[N];
int vis[N];
int n,cnt,m,st;
double l,r,mid,c[M],dis[N],len[M],val[N];

inline void add(int u,int v,double w)
{
    to[cnt]=v; len[cnt]=w; next[cnt]=head[u]; head[u]=cnt++;
}

inline void read()
{
    memset(head,-1,sizeof head); cnt=0;
    for(int i=1;i<=n;i++) scanf("%lf",&val[i]);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%lf",&a[i],&b[i],&c[i]);
        add(a[i],b[i],c[i]);
    }
}
/*queue版spfa 
inline bool spfa()
{
    memset(im,0,sizeof im);
    int h=1,t=1,sta;
    for(int i=1;i<=n;i++)
    {
        q[t++]=i;
        dis[i]=0.0;
        vis[i]=true;
        im[i]++;
    }
    while(h!=t)
    {
        sta=q[h++]; vis[sta]=false;
        for(int i=head[sta];~i;i=next[i])
            if(dis[to[i]]>dis[sta]+len[i]*mid-val[sta])
            {
                dis[to[i]]=dis[sta]+len[i]*mid-val[sta];
                if(!vis[to[i]])
                {
                    vis[to[i]]=true;
                    q[t++]=to[i];
                    if(++im[to[i]]>n) return true;
                }
            }
    }
    return false;
}
*/

inline bool dfs(int u)
{
    vis[u]=st;
    for(int i=head[u];~i;i=next[i])
        if(dis[to[i]]>dis[u]+len[i]*mid-val[u])
        {
            dis[to[i]]=dis[u]+len[i]*mid-val[u];
            if(vis[to[i]]==st) return true;
            else if(dfs(to[i])) return true;
        }
    vis[u]=0;
    return false;
}
//dfs-spfa找负环 
inline bool spfa()
{
    memset(vis,0,sizeof vis);
    for(st=1;st<=n;st++)
        if(dfs(st)) return true;
    return false;
}

inline void go()
{
    l=0.0; r=1000.0;
    while(r-l>1e-4)
    {
        mid=(l+r)/2.0;
        if(spfa()) l=mid;
        else r=mid;
    }
    printf("%.2lf\n",mid);
}

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF) read(),go();
    return 0;
}



