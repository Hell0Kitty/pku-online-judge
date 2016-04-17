#include<iostream>
#include<string>
#include<cstring>
#include <cstdio>

using namespace std;

#define INF 0x3f3f3f3f
int dp[10005];
int sta[10005];
#define min(a,b) (a)<(b)?(a):(b)
#define max(a,b) (a)>(b)?(a):(b)
int main()
{
	int l1,l2,l3;
	int c1,c2,c3;
	//cin >> l1 >> l2 >> l3 >> c1 >> c2 >> c3;
	scanf("%d%d%d%d%d%d",&l1,&l2,&l3,&c1,&c2,&c3);
	int n;
	int a,b;
	scanf("%d%d%d",&n,&a,&b);

	for( int i=2;i<=n;i++ )
		scanf("%d",&sta[i]);

	for( int i=0;i<=n;i++ )
		dp[i] = INF;

	if( a>b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	dp[a] = 0;

	for( int i=a;i<b;i++ )
	{
		for( int j=i+1;j<=b;j++ )
		{
			if( sta[j] - sta[i] <= l1 && dp[j] > dp[i]+c1 )
				dp[j] = dp[i]+c1;
			if( sta[j] - sta[i] <= l2 && dp[j] > dp[i]+c2 )
				dp[j] = dp[i]+c2;
			if( sta[j] - sta[i] <= l3 && dp[j] > dp[i]+c3 )
				dp[j] = dp[i]+c3;
		}
	}
	printf("%d\n",dp[b]);
	return 0;
}



