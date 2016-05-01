#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=505*2,M=N*N+10;
int next[M],head[N],list[M],tot,n,m;
void add(int a,int b)
{
	tot++;
	list[tot]=b;
	next[tot]=head[a];
	head[a]=tot;
}
int fa[N],vis[N];
bool dfs(int v)
{
	for(int i=head[v];i;i=next[i])
	{
		int u=list[i];
		if(!vis[u])
		{
			vis[u]=1;
			if(fa[u]==0||dfs(fa[u]))
			{
				fa[u]=v;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(head,0,sizeof head);tot=0;
		memset(fa,0,sizeof fa);
		for(int i=1;i<=m;i++)
		{
			int a,b;scanf("%d%d",&a,&b);
			add(a,b);
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			memset(vis,0,sizeof vis);
			ans+=dfs(i);
		}
		printf("%d\n",ans);
	}
    return 0;
}



