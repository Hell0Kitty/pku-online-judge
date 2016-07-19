#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
struct eg
{
	int x,n;
}e[50005];
int head[205],n,m,v[205],met[205],vd[205];
int dfs(int u)
{
	for(int i=head[u];i>0;i=e[i].n)
	{
		if(!vd[e[i].x]&&v[e[i].x]==1)
		{
			vd[e[i].x]=1;
			if(met[e[i].x]==-1||dfs(met[e[i].x]))
			{
				met[e[i].x]=u;
				return 1;
			}
		}
	}
	return 0;
}
int match()
{
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(!v[i])
		{
			memset(vd,0,sizeof(vd));
			ans+=dfs(i);
		}
	}
	return ans;
}
void deal()
{
	int q[205],len=0;
	memset(met,-1,sizeof(met));
	int ans=match();
	for(int i=0;i<n;i++)
	{
			v[i]=v[i]^1;
			memset(met,-1,sizeof(met));
			int tem=match();
			if(tem<ans)
			{
				ans=tem;
				q[len++]=i;
			}
			else
			{
				v[i]=v[i]^1;
			}

	}
	printf("%d",len);
	for(int i=0;i<len;i++)
	{
		printf(" %d",q[i]);
	}
	printf("\n");
}
int main()
{
	int c,tem,x,y,pos=1;
	scanf("%d",&c);
	while(c--)
	{
		memset(head,-1,sizeof(head));
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&v[i]);
		}
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&x,&y);
			if(v[x]!=v[y])
			{
				if(v[x]==0)
				{
					e[pos].x=y;
					e[pos].n=head[x];
					head[x]=pos++;
				}
				else
				{
					e[pos].x=x;
					e[pos].n=head[y];
					head[y]=pos++;
				}
			}
		}
		deal();
	}
	return 0;
}



