#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=100000+50;

int v[maxn],pre[maxn],post[maxn];
long long sum[maxn];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		v[0]=-1,v[n+1]=-1;
		memset(sum,0,sizeof(sum));

		for(int i=1;i<=n;i++)
		{
			scanf("%d",&v[i]);
			sum[i]=sum[i-1]+v[i];
			for(int j=i-1;j>=0; )
			{
				if(v[j]<v[i])
				{
					pre[i]=j+1;
					break;
				}
				j=pre[j]-1;
			}
		}

		for(int i=n;i>=1;i--)
			for(int j=i+1;j<=n+1; )
			{
				if(v[j]<v[i])
				{
					post[i]=j-1;
					break;
				}
				j=post[j]+1;
			}

		long long ans=-1,l,r;
		for(int i=1;i<=n;i++)
		{
			long long temp=(sum[post[i]]-sum[pre[i]-1])*v[i];
			if(temp>ans)
			{
				ans=temp;
				l=pre[i];
				r=post[i];
			}
		}

		printf("%lld\n%lld %lld\n",ans,l,r);
	}

	return 0;
}



