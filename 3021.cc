#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=101;
const int inf=1<<28;
int n,m,a[maxn],b[maxn],dp[301][301];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	    scanf("%d%d",&a[i],&b[i]);
	for(int i=0;i<=m;i++)
	    for(int j=0;j<=m;j++)
		dp[i][j]=inf;
	dp[0][0]=0;
	for(int i=0;i<=m;i++)
	    for(int j=0;j<=m;j++)
		for(int k=0;k<n;k++)
		    if(i>=a[k]&&j>=b[k])
			dp[i][j]=min(dp[i][j],dp[i-a[k]][j-b[k]]+1);
	int ans=inf;
	for(int i=0;i<=m;i++)
	    for(int j=0;j<=m;j++)
		if(i*i+j*j==m*m)
		    ans=min(ans,dp[i][j]);
	if(ans==inf)
	{
	    printf("not possible\n");
	    continue;
	} 
	printf("%d\n",ans);
    }
    return 0;
}



