# include <stdio.h>
# include <algorithm>
# include <string.h>
using namespace std;
struct node
{
	int w;
	int v;
};
struct node a[10010];
int n,d,maxa;
int vis[10010];
int max1(int x,int y)
{
	return x>y?x:y;
}
void dfs(int w1,int w2,int v2,int ans,int flag)
{
	if(ans==n)
	{
		maxa=max1(maxa,v2);
		return ;
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			if(vis[i]==0)
			{
				vis[i]=1;
				if(flag&&w1>d+w2)
				{
					dfs(w1,w2+a[i].w,v2+a[i].v,ans+1,0);
				}
				else if(flag&&w1<=d+w2)
				{
					dfs(w1+a[i].w,w2,v2,ans+1,1);
				}
				else if(!flag&&w2>d+w1)
				{
					dfs(w1+a[i].w,w2,v2,ans+1,1);
				}
				else if(!flag&&w2<=d+w1)
				{
					dfs(w1,w2+a[i].w,v2+a[i].v,ans+1,0);
				}
				vis[i]=0;
			}
		}
	}
	return ;
}
int main()
{
	while(~scanf("%d%d",&n,&d))
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a[i].w,&a[i].v);
		}
		memset(vis,0,sizeof(vis));
		maxa=0;
		dfs(0,0,0,0,1);
		printf("%d\n",maxa);
	}
	return 0;
}


