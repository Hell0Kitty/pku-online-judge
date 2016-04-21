#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=104;
int n,k,dp[maxn][maxn];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
	memset(dp,0,sizeof(dp));
	scanf("%d%d",&n,&k);
	int x=0,y=0;
	for(int i=1;i<=n;i++)
	{
	    int x1,y1,x2,y2,len;
	    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	    x=max(x,max(x1,x2));
	    y=max(y,y1);
	    len=max(x1,x2)-min(x1,x2)+1;
	    for(int j=min(x1,x2);j<=max(x1,x2);j++)
		dp[y1][j]=max(dp[y1][j],len--);
	}
	int ans=0;
	for(int i=0;i<=x;i++)
	{
	    int cnt=0;
	    for(int j=0;j<=y;j++)
		if(dp[j][i])
		    cnt++;
	    while(cnt>k)
	    {
		int maxi=0,pos=0;
		for(int j=0;j<=y;j++)
		    if(dp[j][i]>maxi)
		    {
			maxi=dp[j][i];
			pos=j;
		    }
		int p=dp[pos][i];
		for(int j=0;j<p;j++)
		    dp[pos][i+j]=0;
		cnt--;
		ans++;
	    }
	}
	printf("%d\n",ans);
    }
    return 0;
}


