#include<cstdio>
#include<cstring>
#include<iostream>
#include<utility>
#include<string>
#include<set>
#include<vector>
#include<stack>
#include<algorithm>
#include<queue>
#include<cstdlib>
#include<map>
#include<cmath>
using namespace std;
#define FOR(i,a,b) for(int i(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define CL(a,b) memset(a,b,sizeof(a))

const int M=1100;
const int N=1000010;
const int inf=1<<29;
const double eps=1e-8;
const double pi=acos(-1.0);

struct node
{
	int v;
	int next;
	bool vis;
}edge[2*N];
int head[M],num;
int bcc[M],bcnt,dep[M],low[M];
int  stac[M],top;
bool instac[M],vis[M];
int n,m;

void init()
{
	for(int i=0;i<=n+2;i++)
	{
		head[i]=-1;
		dep[i]=0;
		low[i]=0;
		bcc[i]=0;
		vis[i]=instac[i]=0;
	}
	num=top=bcnt=0;
}

void addege(int u,int v)
{
	edge[num].v=v;
	edge[num].vis=0;
	edge[num].next=head[u];
	head[u]=num++;
}

void tarjan(int u,int fa,int dfsindex)
{
	dep[u]=low[u]=dfsindex++;
	instac[u]=1;
	stac[top++]=u;
	for(int i=head[u];i!=-1;i=edge[i].next)
	{
		int v=edge[i].v;
		if(v!=fa)
		{
			if(!dep[v])
			{
				tarjan(v,u,dfsindex);
				if(low[u]>low[v])
					low[u]=low[v];
			}
			else if(instac[v] && dep[v]<low[u])
			{
				low[u]=dep[v];
			}
		}
	}
	if(dep[u]==low[u])
	{
		bcnt++;
		int v;
		do
		{
			v=stac[top-1];
			top--;
			instac[v]=0;
			bcc[v]=bcnt;
		}while(v!=u);
	}
}

void solve(int u,int fa)
{
	for(int i=head[u];i!=-1;i=edge[i].next)
	{
		int v=edge[i].v;
		if(v!=fa)
		{
			if(bcc[u]==bcc[v] && edge[i].vis==false)
			{
				printf("%d %d\n",u,v);
			}
			else if(bcc[u]!=bcc[v] && edge[i].vis==false)
			{
				printf("%d %d\n",u,v);
				printf("%d %d\n",v,u);
			}
			edge[i].vis=true;
			edge[i^1].vis=true;
			if(!vis[v])
			{
				vis[v]=1;
				solve(v,u);
			}
		}
	}
}

int main()
{
	int T=1;
	while(scanf("%d%d",&n,&m)==2)
	{
		if(!n && !m) break;
		init();
		int a,b;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			addege(a,b);
			addege(b,a);
		}
		tarjan(1,0,1);
		vis[1]=1;
		printf("%d\n\n",T++);
		solve(1,0);
		printf("#\n");
	}
	return 0;
}


