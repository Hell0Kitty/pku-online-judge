#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
bool flag[1000005];

__int64 gcd(__int64 a,__int64 b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}

int main()
{
	__int64 n,s,t,a,b,c,ans1,ans2,i;
	while(scanf("%I64d",&n)!=EOF)
	{
		ans1=0,ans2=0;
		memset(flag,0,sizeof(flag));
		for(t=1;t<=n;t=t+2)
		{
			for(s=t+2;s<=n;s=s+2)
			{
				if(gcd(s,t)!=1)
					continue;
				a=s*t;
				b=(s*s-t*t)/2;
				c=(s*s+t*t)/2;
				if(c>n)
					break;
				ans1++;
				for(i=1;c*i<=n;i++)
				{
					flag[i*a]=true;
					flag[i*b]=true;
					flag[i*c]=true;
				}
			}
		}
		for(i=1;i<=n;i++)
			if(!flag[i])
				ans2++;
		printf("%I64d %I64d\n",ans1,ans2);
	}
	return 0;
}

