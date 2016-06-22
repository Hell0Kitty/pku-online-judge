#include<iostream>
#include<stdio.h>
#include<cstring>
#include<math.h>
#include<cmath>
using namespace std;
int dp[2][100000008];
int main()
{
	int n,m,x,sum,i,j,k;
	while(scanf("%d%d%d",&n,&m,&k)!=EOF)
	{
		if(n==0&&m==0&&k==0)
			break;
		sum=n*m;
		for(i=0;i<=sum;i++)
		{
			dp[0][i]=0;
			dp[1][i]=0;
		}
		for(i=1;i<=m;i++)
			dp[1][i]=1;
		for(i=2;i<=n;i++)
		{
			for(j=0;j<=sum;j++)
				dp[i%2][j]=0;
			for(x=sum;x>=1;x--)
			{
				for(j=1;j<=m&&j<x;j++)
					dp[i%2][x]=dp[i%2][x]+dp[1-i%2][x-j];
			}
		}
		double all;
		all=pow((double)m,(double)n);
		double ans=0.0;
		for(i=1;i<=k;i++)
			ans=ans+(double)dp[n%2][i];
		for(i=k+1;i<=sum;i++)
			ans=ans+(double)(i-k)*dp[n%2][i];
		printf("%.8lf\n",ans/all);
	}
	return 0;
}


