#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int len[205],dp[205][205][205],n,color[205],flag;
int DP(int x,int y,int k)
{
	if(dp[x][y][k])return dp[x][y][k];
	if(x==y) return (len[x]+k)*(len[x]+k);
	dp[x][y][k]=DP(x,y-1,0)+(len[y]+k)*(len[y]+k);
	for(int i=x;i<y;i++)
	{
		if(color[y]==color[i])
		{
			dp[x][y][k]=max(dp[x][y][k],DP(x,i,len[y]+k)+DP(i+1,y-1,0));
		}
	}
	return dp[x][y][k];	
}
int main()
{
	int T,ans,tem;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		scanf("%d",&n);
		flag=0;
		memset(len,0,sizeof(len));
		memset(color,0,sizeof(color));
		for(int i=0;i<n;i++)
		{
			scanf("%d",&tem);
			if(color[flag]==tem)
				len[flag]++;
			else
			{
				flag++;
				len[flag]++;
				color[flag]=tem;
			}
		}
		memset(dp,0,sizeof(dp));
		ans=DP(1,flag,0);
		printf("Case %d: ",t);
		printf("%d\n",ans);
	}
	return 0;
}


