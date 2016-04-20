#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int t,n,a[1005],dp[1005][1005],i,j,k,l;

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i = 1; i<=n; i++)
            scanf("%d",&a[i]);
        memset(dp,0,sizeof(dp));
        for(l = 1; l<n; l+=2)
        {
            for(i = 1; i+l<=n; i++)
            {
                j = i+l;
                dp[i][j] = dp[i+1][j-1];
                if(a[i] == a[j])
                    dp[i][j]++;
                for(k = i+1; k<j; k+=2)
                    dp[i][j] = max(dp[i][j],dp[i][k]+dp[k+1][j]);
            }
        }
        printf("%d\n",dp[1][n]);
    }

    return 0;
}



