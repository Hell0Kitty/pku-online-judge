#include <cstdio>
#include <stack>
#include <queue>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int NN=2100;
const int MM=1000000;
const int INF=0x3f3f3f3f;

struct interval{
    int s,t,cost;
    bool operator <(const interval a)const{
        return s<a.s;
    }
} a[NN];

int n,S,T,NV,en,head[NN];
struct Edge{
    int u,v,f,c,next;
}e[MM];
void add(int u,int v,int f,int c)
{
    e[en].u=u; e[en].v=v; e[en].c=c; e[en].f=f; e[en].next=head[u];
    head[u]=en++;
    e[en].u=v; e[en].v=u; e[en].c=-c; e[en].f=0; e[en].next=head[v];
    head[v]=en++;
}

void build_graph()
{
    en=0;
    S=0; T=2*n+1; NV=T+1;
    memset(head,-1,sizeof(head));

    for (int i=1; i<=n; i++) add(S,i,1,0);
    for (int i=1; i<=n; i++) add(i,i+n,1,a[i].cost);
    for (int i=1; i<=n; i++) add(i+n,T,1,0);

    for (int i=1; i<n; i++)
    {
        int j=i+1;
        while (j<=n && a[j].s<=a[i].t) j++;
        for (; j<=n; j++) add(i+n,j,1,0);
    }
}

int dis[NN],p[NN];
bool vis[NN];
bool spfa()//最长路
{
    for (int i=0; i<NV; i++) dis[i]=-INF;
    dis[S]=0;
    p[S]=-1;
    stack<int> q; //queue版超时~~
    q.push(S);
    while (!q.empty())
    {
        int u=q.top();
        q.pop();
        vis[u]=false;
        for (int i=head[u]; i!=-1; i=e[i].next)
        {
            int v=e[i].v;
            if (e[i].f && dis[v]<dis[u]+e[i].c)
            {
                dis[v]=dis[u]+e[i].c;
                p[v]=i;
                if (!vis[v])
                {
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
    }
}

int fee_flow()
{
    int u,v,ret=0;
    for (int i=1; i<=2; i++)//两个大厅，两条流量
    {
        spfa();
        for (v=T; p[v]!=-1; v=u){
            u=e[p[v]].u;
            e[p[v]].f--;
            e[p[v]^1].f++;
        }
        ret+=dis[T];
    }
    return ret;
}

int main()
{
    while (scanf("%d",&n),n)
    {
        for (int i=1; i<=n; i++) scanf("%d%d%d",&a[i].s,&a[i].t,&a[i].cost);
        sort(a+1,a+n+1);
        if (n==1) { printf("%d\n",a[1].cost); continue; }
        if (n==2) { printf("%d\n",a[1].cost+a[2].cost); continue; }

        build_graph();
        printf("%d\n",fee_flow());
    }
    return 0;
}



