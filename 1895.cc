#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
const int inf=1<<30;
const int maxn=5e3;
const int maxm=1e5;
const int maxe=210;
struct Edge
{
    int from;
    int to;
}E[maxe];
struct Ship
{
    int pos;
    bool isupdate;
    bool islive;
    Ship(){};
    Ship(int spos)
    {
        pos=spos;
        isupdate=true;
        islive=true;
    }
}ship[55];
int n,m,k,s,t,st,des,e,head[maxn],pnt[maxm],nxt[maxm],flow[maxm],level[maxn];
queue<int> q;
void AddEdge(int u,int v,int f)
{
    pnt[e]=v;nxt[e]=head[u];flow[e]=f;head[u]=e++;
    pnt[e]=u;nxt[e]=head[v];flow[e]=0;head[v]=e++;
}
int GetPoint(int val)
{
    val%=n;
    if(!val)
        return n;
    return val;
}
bool BFS()
{
    memset(level,0,sizeof(level));
    level[s]=1;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=head[u];i!=-1;i=nxt[i])
            if(flow[i]&&!level[pnt[i]])
            {
                level[pnt[i]]=level[u]+1;
                q.push(pnt[i]);
            }
    }
    return level[des];
}
int DFS(int u,int maxf)
{
    if(u==des||!maxf)
        return maxf;
    for(int i=head[u],t;i!=-1;i=nxt[i])
        if(level[pnt[i]]==level[u]+1&&(t=DFS(pnt[i],min(flow[i],maxf))))
        {
            flow[i]-=t;
            flow[i^1]+=t;
            return t;
        }
    return level[u]=0;
}
int maxflow(int flow)
{
    int ans=0;
    while(BFS())
        while(1)
        {
            int val=DFS(s,flow-ans);
            ans+=val;
            if(!val)
                break;
            if(flow==ans)
                return ans;
        }
    return ans;
}
void Build(int days)
{
    for(int i=0;i<m;i++)
    {
        AddEdge(E[i].from+n*(days-1),E[i].to+n*days,1);
        AddEdge(E[i].to+n*(days-1),E[i].from+n*days,1);
    }
    for(int i=1;i<=n;i++)
        AddEdge(i+n*(days-1),i+n*days,inf);
}
int main()
{
    while(scanf("%d%d%d%d%d",&n,&m,&k,&s,&t)!=EOF)
    {
        e=0;
        memset(head,-1,sizeof(head));
        for(int i=0;i<m;i++)
            scanf("%d%d",&E[i].from,&E[i].to);
        int days=0,f=0;
        while(1)
        {
            Build(++days);
            des=n*days+t;
            f+=maxflow(k-f);
            if(f>=k)
                break;
        }
        printf("%d\n",days);
        int index=0,ex=0,id=1,ans[51];
        for(int i=1;i<=days;i++)
        {
            int cnt=0;
            memset(ans,0,sizeof(ans));
            for(int j=0;j<m;j++)
            {
                int f1=flow[ex];ex+=2;
                int f2=flow[ex];ex+=2;
                int u=-1,v=-1;
                if(f1==0&&f2==1)
                {
                    u=E[j].from;
                    v=E[j].to;
                }
                if(f1==1&&f2==0)
                {
                    u=E[j].to;
                    v=E[j].from;
                }
                if(u==-1)
                    continue;
                if(u==s)
                {
                    ship[++index]=Ship(v);
                    ans[index]=v;
                    cnt++;
                }
                else
                {
                    for(int l=1;l<=index;l++)
                        if(ship[l].pos==u&&ship[l].islive&&!ship[l].isupdate)
                        {
                            ship[l].pos=v;
                            ship[l].isupdate=true;
                            ans[l]=v;
                            cnt++;
                            if(v==t)
                                ship[l].islive=false;
                            break;
                        }
                }
            }
            ex+=2*n;
            printf("%d",cnt);
            for(int j=1;j<=index;j++)
            {
               if(ans[j])
                  printf(" %d %d",j,ans[j]); 
                ship[j].isupdate=false;
            }
            printf("\n");
        }
    }
    return 0;
}



