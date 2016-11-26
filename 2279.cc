#include <iostream>
using namespace std;

int a[15],dp[15][45],num[45],x,f[45],n,m;

int Gcd(int x,int y)
{
	return !y?x:Gcd(y,x%y);
}

int main()
{
	while(scanf("%d",&m),m)
	{
		memset(dp,0,sizeof(dp));
		n=0;
		int i,j,k,sum;
		for(i=1;i<=m;i++)
		{
			scanf("%d",&a[i]);
			n+=a[i];
			for(j=1;j<=a[i];j++) dp[i][j]=1;
		}
		x=0;
		for(i=1;i<=14;i++) for(j=1;j<=40;j++) if(dp[i][j])
		{
			sum=-1;
			for(k=i;k<=14;k++) sum+=dp[k][j];
			for(k=j;k<=40;k++) sum+=dp[i][k];
			if(sum>0) num[++x]=sum;
		}
		for(i=1;i<=n;i++) f[i]=i;
		for(i=1;i<=n;i++) for(j=1;j<=n;j++)
		{
			k=Gcd(f[i],num[j]);
			f[i]/=k;
			num[j]/=k;
		}
		__int64 ans=1;
		for(i=1;i<=n;i++) ans*=f[i];
		printf("%I64d\n",ans);
	}
	return 0;
}



