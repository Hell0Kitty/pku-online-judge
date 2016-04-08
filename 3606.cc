#include <iostream>
using namespace std;

const int mod=9973;
int n,C,op[10005],f00[20005],f10[20005],f01[20005],f11[20005],f0[20005],f1[20005];

int main()
{
	for(scanf("%d",&C);C--;)
	{		
		int i,p1,p2;
		scanf("%d",&n);
		for(i=1;i<=n-1;i++)scanf("%d",&op[i]);
		for(i=n*2-1;i>=n;i--)
		{
			f00[i]=f10[i]=f11[i]=0;
			f0[i]=f1[i]=f01[i]=1;
		}	
		for(i=n-1;i>=1;i--)
		{
			p1=i<<1;
			p2=(i<<1)^1;
			if(op[i])
			{
				f0[i]=(f0[p1]*(f0[p2]+f1[p2])+f1[p1]*f0[p2])%mod;
				f1[i]=(f1[p1]*f1[p2])%mod;
				f00[i]=(f1[p1]*f00[p2]+f0[p1]*(f0[p2]+f1[p2]-1)+f00[p1]+f01[p1])%mod;
				f01[i]=(f1[p1]*f01[p2])%mod;
				f10[i]=(f1[p1]*f10[p2]+f10[p1]+f11[p1])%mod;
				f11[i]=(f1[p1]*f11[p2])%mod;
			}
			else
			{
				f0[i]=(f0[p1]*f0[p2])%mod;
				f1[i]=(f0[p1]*f1[p2]+f1[p1]*f0[p2]+f1[p1]*f1[p2])%mod;
				f00[i]=(f0[p1]*f00[p2])%mod;
				f01[i]=(f0[p1]*f01[p2])%mod;
				f10[i]=(f0[p1]*f10[p2]+f00[p1]+f10[p1])%mod;
				f11[i]=(f1[p1]*(f0[p2]+f1[p2]-1)+f0[p1]*f11[p2]+f01[p1]+f11[p1])%mod;
			}
		}
		printf("%d %d\n",f01[1],f10[1]);
	}
	return 0;
}


