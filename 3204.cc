#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1000,M=10000;
const int inff=1<<29;
int head[N],nc;
struct edge
{
    int x,y,next;
    int cap;
} edge[M*3];
void add(int x,int y,int cap)
{
    edge[nc].x=x;
    edge[nc].y=y;
    edge[nc].cap=cap;
    edge[nc].next=head[x];
    head[x]=nc++;
    edge[nc].x=y;
    edge[nc].y=x;
    edge[nc].cap=0;
    edge[nc].next=head[y];
    head[y]=nc++;
}
int num[N],h[N],S,T,n;
int findpath(int x,int flow)
{
    if(x==T)
        return flow;
    int res=flow,pos=n-1;
    for(int i=head[x]; i!=-1; i=edge[i].next)
    {
        int y=edge[i].y;
        if(h[x]==h[y]+1&&edge[i].cap>0)
        {
            int tp=findpath(y,min(edge[i].cap,res));
            res-=tp;
            edge[i].cap-=tp;
            edge[i^1].cap+=tp;
            if(!res||h[S]==n)
                return flow-res;
        }
        if(edge[i].cap>0&&h[y]<pos)
            pos=h[y];
    }
    if(res==flow)
    {
        num[h[x]]--;
        if(num[h[x]]==0)
        {
            h[S]=n;
            return flow-res;
        }
        h[x]=pos+1;
        num[h[x]]++;
    }
    return flow-res;
}
void Sap()
{
    memset(h,0,sizeof(h));
    memset(num,0,sizeof(num));
    int ans=0;
    num[0]=n;
    while(h[S]!=n)
        ans+=findpath(S,inff);
}
bool vis[N];
void dfs(int now)
{
    vis[now]=true;
    for(int i=head[now];i!=-1;i=edge[i].next)
    {
        if(!vis[edge[i].y]&&edge[i].cap)
            dfs(edge[i].y);
    }
}
bool mark[N];
bool check(int now)
{
    mark[now]=true;
    if(now==T)
        return true;
    for(int i=head[now];i!=-1;i=edge[i].next)
    {
        if(!mark[edge[i].y]&&edge[i].cap&&check(edge[i].y))
                return true;
    }
    return false;
}
int main()
{
    int m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        nc=0;
        memset(head,-1,sizeof(head));
        for(int i=0; i<m; i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c);
        }
        S=0,T=n-1;
        Sap();
        memset(vis,false,sizeof(vis));
        dfs(S);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
                continue;
            for(int j=head[i];j!=-1;j=edge[j].next)
            {
                if(j&1)
                    continue;
                int t=edge[j].y;
                if(!vis[t])
                {
                    memset(mark,false,sizeof(mark));
                    if(check(t))
                        cnt++;
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}



