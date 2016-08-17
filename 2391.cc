#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<set>
#include<ctime>
#include<cmath>
#define eps 1e-8
#define ex 2.7182818284590452354
#define pi acos(-1.0)
#define inf 0x3fffffff
#define DC(n) printf("Case #%d:",++n)
#define SD(n) scanf("%d",&n)
#define SS(str) scanf("%s",str)
#define SDB(n) scanf("%lf",&n)
#define ll __int64
#define mm 1000000007
#define mmax  100010
using namespace std;
const ll INF=0x3fffffffffffffff;
struct edges
{
    int en;
    int cost;
    int next;
}edge[10000];
int point[300][2];
int p1[300];
int num1;
void init1()
{
    memset(p1,-1,sizeof p1);
    num1=0;
}
void add1(int st,int en,int cost)
{
    edge[num1].en=en;
    edge[num1].cost=cost;
    edge[num1].next=p1[st];
    p1[st]=num1++;
}

int n,m;
struct node
{
    int en,val;
    int next;
}E[100010];
int p[500];
int num;
void init()
{
    memset(p,-1,sizeof p);
    num=0;
}
void add(int st,int en,int val)
{
    E[num].en=en;
    E[num].val=val;
    E[num].next=p[st];
    p[st]=num++;
    E[num].en=st;
    E[num].val=0;
    E[num].next=p[en];
    p[en]=num++;
}

ll dis[210];
bool vis[510];
int q[510];
int cntq;
ll cost[210][210];
void spfa(int st)
{
    for(int i=1;i<=n;i++)
    {
        dis[i]=INF;
        vis[i]=0;
    }
    cntq=0;
    q[++cntq]=st;
    vis[st]=1;
    dis[st]=0;
    while(cntq)
    {
        int x=q[cntq];
        cntq--;
        vis[x]=0;
        for(int i=p1[x];i+1;i=edge[i].next)
        {
            int  v=edge[i].en;
            ll val=edge[i].cost;
            if(dis[v]>dis[x]+val)
            {
                dis[v]=dis[x]+val;
                if(!vis[v])
                {
                    vis[v]=1;
                    q[++cntq]=v;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
        cost[st][i]=dis[i];
}
void build(ll max_time)
{
    init();
    for(int i=1;i<=n;i++)
    {
        add(i,i+n,point[i][1]);
        add(0,i,point[i][0]);
        add(i+n,2*n+1,point[i][1]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i!=j)
            {
                if(cost[i][j]<=max_time)
                    add(i,j+n,inf);
            }
        }
    }
}

int h[510];
int vh[510];

int find(int u,int  st,int en,int F)
{

    if(u==en)
        return F;
    int left=F;
    int tmp=en;
    for(int i=p[u];i+1;i=E[i].next)
    {
        int v=E[i].en;
        int val=E[i].val;
        if(val>0)
        {
            if(h[v]+1==h[u])
            {
                int d=min(left,val);
                d=find(v,st,en,d);
                left-=d;
                E[i].val-=d;
                E[i^1].val+=d;
                if(h[st]>=en+1)
                    return F-left;
                if(!left)
                    break;
            }
            if(h[v]<tmp)
                tmp=h[v];
        }
    }

    if(left==F)
    {
        vh[ h[u] ]--;
        if(vh[h[u] ]==0)
            h[st]=en+1;
        h[u]=tmp+1;
        vh[ h[u] ]++;
    }
    return F-left;

}

int isap(int st,int en)
{
    memset(vh,0,sizeof vh);
    memset(h,0,sizeof h);
    int ans=0;
    vh[0]=en+1;
    while(h[st]<=en)
        ans+=find(st,st,en,inf);
    return ans;
}

int main()
{
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        int sum=0;
        ll times=0;
        init1();
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d",&point[i][0],&point[i][1]);
            sum+=point[i][0];
        }
        for(int i=1;i<=m;i++)
        {
            int st,en,val;
            scanf("%d %d %d",&st,&en,&val);
            add1(st,en,val);
            add1(en,st,val);
            times+=val;
        }
        for(int i=1;i<=n;i++)
            spfa(i);
        ll st=0,en=times+1;
        while(st<en)
        {
            ll mid=(st+en)>>1;
            build(mid);
            int tmp=isap(0,2*n+1);
            if(tmp==sum)
                en=mid;
            else
                st=mid+1;
        }
        if(en==times+1)
            printf("-1\n");
        else
            printf("%I64d\n",(st+en)/2);
    }
    return 0;
}



