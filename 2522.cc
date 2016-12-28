#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define M 500
#define N 100
int  dp[M][N][M];

bool vis[M][N][M];

int getdp(int m,int n,int x)
{
	if(m<x)return 0;
	if(vis[m][n][x])return dp[m][n][x];
	vis[m][n][x]=true;
	if(n==1)
	{
		if(x==m)dp[m][n][x]=1;
		else dp[m][n][x]=0;
	}
	else {
		int ans=0;
		for(int i=x;i<=m-x;i++)
			ans+=getdp(m-x,n-1,i);
		dp[m][n][x]=ans;
	}
	return dp[m][n][x];
}

void dfs(int m,int n,int k,int pre)
{
	if(m<=0||k<=0||n<=0){return;}
	for(int i=pre;i<=m;i++)
	{
		int d=getdp(m,n,i);
		if(d<k){
			k-=d;
		}
		else
		{
			printf("%d\n",i);
			dfs(m-i,n-1,k,i);
		//	cout<<dp[m][n][i]<<'!'<<endl;
			break;
		}
	}
}

int main()
{
	int C;
	scanf("%d",&C);
	int m,n,k;
	while(C--)
	{
		scanf("%d%d%d",&m,&n,&k);
		dfs(m,n,k,1);
	}
	return 0;
}



