#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
#define maxe 2001000
#define maxn 10010
#define INF 1<<29
struct node{
 int u,v,w,next;
}edge[maxe],nedge[maxe];
int head[maxn],add;
void adj(int u,int v,int w)
{
 edge[add].u=u; edge[add].v=v; edge[add].w=w; edge[add].next=head[u]; head[u]=add++;
}

int nhead[maxn],nadd;
void nadj(int u,int v,int w)
{
 nedge[nadd].u=u; nedge[nadd].v=v; nedge[nadd].w=w; nedge[nadd].next=nhead[u]; nhead[u]=nadd++;
}
int dis[maxn],vis[maxn],n,m,k;
int ndis[maxn];
queue<int>q;
void spfa(node edge[],int head[],int dis[],int st)
{
 int i,j,u,v;
 for(i=1;i<=n;i++)
 dis[i]=INF,vis[i]=0;
 dis[st]=0; q.push(st);
 while(!q.empty())
 {
 u=q.front(); q.pop();
 vis[u]=0;
 for(i=head[u];i!=-1;i=edge[i].next)
 {
 v=edge[i].v;
 if(dis[v]>dis[u]+edge[i].w)
 {
 dis[v]=dis[u]+edge[i].w;
 if(!vis[v])
 {
 vis[v]=1;
 q.push(v);
 }
 }
 }
 }
}
int vv[maxe];
void solve()
{
 int i,j,u,v,w; memset(head,-1,sizeof(head)); add=0;
 memset(nhead,-1,sizeof(nhead)); nadd=0;
 for(i=0;i<m;i++)
 {
 scanf("%d %d %d",&u,&v,&w);
 adj(u,v,w);
 nadj(v,u,w);
 }
 spfa(edge,head,dis,1);
 spfa(nedge,nhead,ndis,n);
 memset(vv,0,sizeof(vv)); int tot=0;
 for(i=0;i<m;i++)
 {
 if(ndis[edge[i].v]+dis[edge[i].u]+edge[i].w<=dis[n]+k)
 tot++,vv[i]=1;
 }
 printf("%d\n",tot);
 for(i=0;i<m;i++)
 if(vv[i])
 printf("%d\n",i+1);
}
int main()
{
 while(scanf("%d %d %d",&n,&m,&k)!=EOF)
 solve();
}


