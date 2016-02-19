#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[50005][4],sum[50005];
int main()
{
    int T;
    for(scanf("%d",&T);T;T--)
    {
        int n,m;
        scanf("%d",&n);
        memset(dp,0,sizeof(dp));
        sum[0]=0;
        for(int i=1,tp;i<=n;i++)
        {
            scanf("%d",&tp);
            sum[i]=sum[i-1]+tp;
        }
        scanf("%d",&m);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                if(i<=m*j)
                    dp[i][j]=sum[i];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i-m][j-1]+sum[i]-sum[i-m]);
            }
        }
        printf("%d\n",dp[n][3]);
    }
    return 0;
}



