#include <iostream>
using namespace std;
const int maxN=256;
int dp[maxN][maxN];
int sum[maxN][maxN];
int p[maxN],q[maxN];
int n;
int main()
{
	int n;
	while(scanf("%d",&n)==1&&n){
		for(int i=1;i<=n;++i)
			scanf("%d",&p[i]);
		for(int i=0;i<=n;++i)
			scanf("%d",&q[i]);
		for(int i=1;i<=n;++i)
			sum[i][i]=p[i]+q[i]+q[i-1];
		for(int d=1;d<n;++d)
			for(int i=1;i+d<=n;++i)	
				sum[i][i+d]=sum[i][i+d-1]+p[i+d]+q[i+d];
		for(int i=1;i<=n+1;++i){
			dp[i][i-1]=0;
			sum[i][i-1]=q[i-1];
		}
		for(int d=0;d<n;++d)
			for(int i=1;i+d<=n;++i){
				int j=i+d;
				int minx=INT_MAX;
				for(int r=i;r<=j;++r)
					minx=min(minx,dp[i][r-1]+dp[r+1][j]);
				dp[i][j]=minx+sum[i][j];
			}	
		printf("%d\n",dp[1][n]);
	}
	return 0;	
}
