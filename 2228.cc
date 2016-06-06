#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[2][4000][3],aa[4000];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%d",aa+i);
        int ans=0,a,b;
        memset(dp[0],-1,sizeof(dp[0]));
        dp[0][0][0]=0;
        dp[0][1][1]=0;
        dp[0][1][2]=aa[1];
        for(int i=2;i<=n;i++)
        {
            a=i&1;
            b=a^1;
            memset(dp[b],-1,sizeof(dp[b]));
            for(int j=0;j<i&&j<=m;j++)
            {
                if(dp[a][j][0]!=-1)
                {
                    dp[b][j][0]=max(dp[b][j][0],dp[a][j][0]);
                    dp[b][j+1][1]=max(dp[b][j+1][1],dp[a][j][0]);
                }
                if(dp[a][j][1]!=-1)
                {
                    dp[b][j+1][2]=max(dp[b][j+1][2],dp[a][j][1]+aa[i]);
                }
                if(dp[a][j][2]!=-1)
                {
                    dp[b][j][0]=max(dp[b][j][0],dp[a][j][2]);
                    dp[b][j+1][2]=max(dp[b][j+1][2],dp[a][j][2]+aa[i]);
                }
            }
        }
        ans=max(dp[b][m][1],dp[b][m][2]);

        memset(dp[0],-1,sizeof(dp[0]));
        dp[0][0][0]=0;
        dp[0][1][1]=0;
        for(int i=2;i<=n;i++)
        {
            a=i&1;
            b=a^1;
            memset(dp[b],-1,sizeof(dp[b]));
            for(int j=0;j<i&&j<=m;j++)
            {
                if(dp[a][j][0]!=-1)
                {
                    dp[b][j][0]=max(dp[b][j][0],dp[a][j][0]);
                    dp[b][j+1][1]=max(dp[b][j+1][1],dp[a][j][0]);
                }
                if(dp[a][j][1]!=-1)
                {
                    dp[b][j+1][2]=max(dp[b][j+1][2],dp[a][j][1]+aa[i]);
                }
                if(dp[a][j][2]!=-1)
                {
                    dp[b][j][0]=max(dp[b][j][0],dp[a][j][2]);
                    dp[b][j+1][2]=max(dp[b][j+1][2],dp[a][j][2]+aa[i]);
                }
            }
        }
        ans=max(ans,max(dp[b][m][0],max(dp[b][m][1],dp[b][m][2])));
        printf("%d\n",ans);
    }
    return 0;
}




