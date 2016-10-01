#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
    int n, k, i, j;
    double dp[102][11];
    while(~scanf("%d%d",&k,&n))
    {
        for(i=0;i<=k;i++)
            dp[1][i]=1;
        for(i=2;i<=n;i++)
        {
            for(j=0;j<=k;j++)
                if(j==0)dp[i][j]=dp[i-1][j]+dp[i-1][j+1];
                else if(j==k)dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
                else dp[i][j]=dp[i-1][j]+dp[i-1][j-1]+dp[i-1][j+1];
        }
        double s=0;
        for(i=0;i<=k;i++)
            s+=dp[n][i];
        printf("%.5f\n",s*100/pow(k+1.0,n));
    }
    return 0;
}




