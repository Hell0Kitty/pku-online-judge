#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
double dp[100][100];
int main()
{
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<100;i++)
    {
        for(int j=1;j<=i;j++)
            dp[i][j]=dp[i-1][j]*j+dp[i-1][j-1];
    }
    int n;
    while(scanf("%d",&n),n)
    {
        double ans=0;
        for(int i=1;i<=n;i++)
            ans+=dp[n][i];
        printf("%d %.0lf\n",n,ans);
    }
    return 0;
}



