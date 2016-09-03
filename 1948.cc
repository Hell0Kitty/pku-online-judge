#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX_N 50
#define MAX_LEN 850
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
    int i,j,k,sum=0,dp[MAX_LEN][MAX_LEN],fence[MAX_N],v;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&fence[i]);
        sum+=fence[i];
    }
    v=sum/2;
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(i=1;i<=n;i++)
    {
        for(j=v;j>=0;j--)
        {
        for(k=v;k>=0;k--)
        {
            if((dp[j-fence[i]][k]&&j>=fence[i])||(k>=fence[i]&&dp[j][k-fence[i]]))
                dp[j][k]=1;
        }
        }
    }
    int max=0;
    for(i=1;i<=v;i++)
    {
        for(j=1;j<=v;j++)
        {
        if(dp[i][j]&&i+j>sum-i-j)
        {
            double p=sum/2.0;
            int tem=(int)((sqrt(p*(p-i)*(p-j)*(p-sum+i+j)))*100);
            if(tem>max)
            max=tem;
        }
        }
    }
    if(max)
        printf("%d\n",max);
    else
        printf("-1\n");
    }
    return 0;
}



