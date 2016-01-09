#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
int dp[1000005][2],bit[1000005];
char s[1000005];
int main()
{
	int n,m,mod,T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&mod);
		getchar();
		memset(bit,0,sizeof(bit));
		memset(dp,0,sizeof(dp));
		scanf("%s",s);
		for(int i=0,j=m-1;j>=0;i++,j--)
			bit[i]=s[j]-'0';		
		dp[0][bit[0]]=1;

		for(int i=0;i<n;i++)
		{
			dp[i+1][bit[i+1]]+=dp[i][0]+dp[i][1];
			if(dp[i+1][bit[i+1]]>=mod)dp[i+1][bit[i+1]]%=mod;
			if(dp[i][1])
			{
				int j;
				for(j=i+1;bit[j]!=0;j++);
					dp[j][1]+=dp[i][1];
			}
		}
		printf("%d\n",(dp[n-1][1]+dp[n-1][0])%mod);
	}
	return 0;
}


