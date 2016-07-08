#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

const int maxn=11000;
const int INF=1e6;

struct Edge
{
	int to,next;
}edge[maxn*2];

int Adj[maxn],Size;

int dp[maxn][3],n;

void init()
{
	Size=0; 
	for(int i=0;i<=n+10;i++)
	{
		Adj[i]=-1;
		dp[i][0]=1; dp[i][1]=0; dp[i][2]=INF;
	}
}

void add_edge(int u,int v)
{
	edge[Size].to=v;
	edge[Size].next=Adj[u];
	Adj[u]=Size++;
}

void dfs(int u,int fa)
{
	for(int i=Adj[u];~i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v==fa) continue;
		dfs(v,u);
		dp[u][0]+=min(dp[v][0],dp[v][1]);
		dp[u][1]+=dp[v][2];
		dp[u][2]=min(dp[u][2],dp[v][0]-dp[v][2]);
	}
	dp[u][2]+=dp[u][1];
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		if(n==-1) break;
		else if(n==0) continue;
		init();
		for(int i=0;i<n-1;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			add_edge(a,b); add_edge(b,a);
		}
		dfs(1,0);
		printf("%d\n",min(dp[1][0],dp[1][2]));
	}

    return 0;
}


