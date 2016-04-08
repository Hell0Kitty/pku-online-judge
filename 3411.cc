#include<iostream>
using namespace std;
int use[10010];
int best=100000000;
int n,m;
struct Path
{
	int s,e,m;
	int r,p;
}path[10010];
void dfs(int a,int tot,int t)
{
	int minn;
	int tmp1,tmp2,tmp3;
	if(path[a].e==n)
	{
		if(tot<best)
			best=tot;
		return ;
	}
	int i;
	for(i=1;i<=m;i++)
	{
		if(path[i].s==path[a].e&&use[i]<=2)
		{
			use[i]++;
			minn=path[i].r;
			tmp1=1<<(path[i].m-1);
			tmp2=1<<(path[i].s-1);
			tmp3=1<<(path[i].e-1);
			if(((t|tmp1)==t)&&path[i].p<minn)
				minn=path[i].p;
			dfs(i,tot+minn,((t|tmp2)|tmp3));
			use[i]--;
		}
	}
}
int main()
{
	int i;
	int tmp1,tmp2;
	int minn=100000000;
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
		scanf("%d %d %d %d %d",&path[i].s,&path[i].e,&path[i].m,&path[i].p,&path[i].r);
	if(n==1)
	{
		printf("0\n");
		return 0;
	}
	for(i=1;i<=m;i++)
	{
		best=100000000;
		if(path[i].s==1)
		{
			use[i]++;
			tmp1=(1<<(path[i].e-1));
			tmp2=(1<<(path[i].s-1));
			dfs(i,path[i].r,tmp1|tmp2);
			use[i]--;
		}
		if(best<minn)
			minn=best;
	}
	if(minn==100000000)
		printf("impossible\n");
	else
		printf("%d\n",minn);
	return 0;
}



