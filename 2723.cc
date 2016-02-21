#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=4100;
const int M=62000;
#define CLR(a,v) memset(a,v,sizeof(a))
#define MCY(d,s) memcpy(d,s,sizeof(d))
struct Edge
{
	int v,next;
}edge[M];
int ehead[N],ehead_bak[N];
int ecnt,ecnt_bak;
inline void AddEdge(int u,int v)
{
	edge[ecnt]={v,ehead[u]};
	ehead[u]=ecnt++;
}
int dfn[N],low[N];
int timestamp;
bool inst[N];
int st[N],sp;
int scc[N],scccnt;
int n;
bool dfs(int u)
{
	dfn[u]=low[u]=++timestamp;
	inst[st[sp++]=u]=true;
	for(int i=ehead[u];~i;i=edge[i].next)
	{
		int v=edge[i].v;
		if(!dfn[v])
		{
			if(!dfs(v))return false;
			low[u]=min(low[u],low[v]);
		}
		else if(inst[v])
			low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		scccnt++;
		do
		{
			int x=st[--sp];
			if(scc[x^1]==(scc[x]=scccnt))return false;
			inst[x]=false;
		}while(st[sp]!=u);
	}
	return true;
}
bool Tarjan(int _n)
{
	n=_n;
	CLR(dfn,0);
	CLR(low,0);
	CLR(scc,0);
	CLR(inst,false);
	timestamp=sp=scccnt=0;
	for(int i=0;i<n*2;i++)if(!dfn[i]&&!dfs(i))return false;
	return true;
}
int lock1[N],lock2[N];
#define SE(x) x<<1
#define NS(x) SE(x)|1
bool judge(int n,int x)
{
	ecnt=ecnt_bak;
	MCY(ehead,ehead_bak);
	for(int i=0;i<=x;i++)
	{
		AddEdge(NS(lock1[i]),SE(lock2[i]));
		AddEdge(NS(lock2[i]),SE(lock1[i]));
	}
	return Tarjan(n);
}
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m),n|m)
	{
		CLR(ehead,-1);ecnt=0;
		for(int i=0;i<n;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			AddEdge(SE(a),NS(b));
			AddEdge(SE(b),NS(a));
		}
		ecnt_bak=ecnt;
		MCY(ehead_bak,ehead);
		for(int i=0;i<m;i++)scanf("%d%d",lock1+i,lock2+i);
		int ans=-1;
		int l=0,r=m-1;
		n<<=1;
		while(l<=r)
		{
			int m=(l+r)>>1;
			if(judge(n,m))l=(ans=m)+1;
			else r=m-1;
		}
		printf("%d\n",ans+1);
	}
	return 0;
}



