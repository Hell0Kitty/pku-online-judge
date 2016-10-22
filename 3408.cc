#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

queue<int>q;
#define maxn 1002
struct TT{int sun[maxn];}St[maxn];
int Max;
int ans;
bool vis[maxn];
int dis[maxn];
int N;
bool BFS(int n)
{
	while(!q.empty())q.pop();
	vis[n]=1;
	dis[n]=0;
	q.push(n);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		Max=Max>dis[u]?Max:dis[u];
		for(int k=0;St[u].sun[k]!=-1;k++)
		{
			int G=St[u].sun[k];
			if(!vis[G])
			{
				dis[G]=dis[u]+1;
				vis[G]=1;
				q.push(G);

			}
		}
	}

	for(int i=1;i<=N;i++)
		if(!vis[i])return false;
	return true;

}
int main()
{

	int n;
	int num;
	int sunnum;
	for(;scanf("%d",&n)==1;)
	{ 
		N=n;
		ans=-1;
		int LL;
		memset(St,-1,sizeof(St));
		for(int i=1;i<=n;i++)
		{
			sunnum=0;
			scanf("%d",&num);
			for(int j=0;j<num;j++)
			{
				scanf("%d",&St[i].sun[sunnum++]);
			}

		}

		for(int i=1;i<=n;i++)
		{
			Max=-1;
			memset(vis,false,sizeof(vis));
			if(BFS(i))
			{
				if(Max>=ans)
				{
					ans=Max;
					LL=i;
				}
			}
		}

		if(ans==-1)

		{
			printf("impossible\n");
		}
		else
		{
			printf("%d\n%d\n",ans,LL);
		}

	}
return 0;
}



