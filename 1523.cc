#include <iostream>
using namespace std;
int edge[1001][1001];
int used[1001];
int n,cnt,dfn[1001],low[1001],son,sub[1001];
void init()
{
	low[1]=dfn[1]=1;
	cnt=1;
	son=0;
	memset(used,0,sizeof(used));
	used[1]=1;
	memset(sub,0,sizeof(sub));
}
void dfs(int u)
{
	int v;
	for(v=1;v<=n;v++)
	{
		if(!edge[u][v])continue;
		edge[u][v]=edge[v][u]=0;
		if(!used[v])
		{
			used[v]=1;
			cnt++;
			dfn[v]=low[v]=cnt;
			dfs(v);
			if(low[u]>low[v])low[u]=low[v];
			if(low[v]>=dfn[u])
			{
				if(u!=1)sub[u]++;
				else son++;
			}
		}
		else if(low[u]>dfn[v])low[u]=dfn[v];
	}
}
int main()
{
	int i,u,v,find,num=1;
	while(1)
	{
		scanf("%d",&u);
		if(!u)break;
		memset(edge,0,sizeof(edge));
		n=0;
		scanf("%d",&v);
		if(u>n)n=u;
		if(v>n)n=v;
		edge[u][v]=edge[v][u]=1;
		while(1)
		{
			scanf("%d",&u);
			if(!u)break;
			scanf("%d",&v);
			if(u>n)n=u;
			if(v>n)n=v;
			edge[u][v]=edge[v][u]=1;
		}
		if(num>1)puts("");
		printf("Network #%d\n",num++);
		init();
		dfs(1);
		if(son>1)sub[1]=son-1;
		find=0;
		for(i=1;i<=n;i++)
		{
			if(sub[i])
			{
				find=1;
				printf("  SPF node %d leaves %d subnets\n",i,sub[i]+1);
			}
		}
		if(!find)puts("  No SPF nodes");
	}
}