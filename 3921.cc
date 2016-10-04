#include <cstdio>
#include <cstdlib>
#include <cstring>
#define N 200
#define M 500000
#define INF 100000000
using namespace std;
int head[N],next[M],len[M],w[M],to[M],cnt,n,m,k,S,T,dis[N],q[M<<4],pre[M];
bool vis[N];
void add(int u,int v,int c,int wp)
{
    to[cnt]=v; len[cnt]=c; w[cnt]=wp; next[cnt]=head[u]; head[u]=cnt++;
    to[cnt]=u; len[cnt]=0; w[cnt]=-wp; next[cnt]=head[v]; head[v]=cnt++;
}
void read()
{
    memset(head,-1,sizeof head);cnt=0;
    for(int i=2;i<n;i++) add(i,i+n,1,0);
    add(1,1+n,INF,0); add(n,n+n,INF,0);
    for(int i=1,a,b;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        add(a+n,b,INF,1);
    }
    S=1; T=n+n;
}
bool spfa()
{
    for(int i=0;i<=T;i++) dis[i]=INF;
    int h=1,t=2,sta;
    q[1]=S; vis[S]=true; dis[S]=0; pre[S]=-1;
    while(h<t)
    {
        sta=q[h++];
        vis[sta]=false;
        for(int i=head[sta];~i;i=next[i])
            if(len[i]>0&&dis[to[i]]>dis[sta]+w[i])
            {
                dis[to[i]]=dis[sta]+w[i];
                pre[to[i]]=i;
                if(!vis[to[i]])
                {
                    vis[to[i]]=true;
                    q[t++]=to[i];
                }
            }
    }
    return dis[T]!=INF;
}
void go()
{
    int cs=0;
    while(spfa())
    {
        if(dis[T]>k) break;
        cs++;//printf("%d\n",cs);
        for(int i=T,tmp;i!=S;i=to[tmp^1])
        {
            tmp=pre[i];
            len[tmp]-=1;
            len[tmp^1]+=1;
        }
    }
    printf("%d\n",cs);
}
int main()
{
    while(scanf("%d%d%d",&n,&m,&k),n||m||k)
    {
        read();
        go();
    }
    return 0;
}



