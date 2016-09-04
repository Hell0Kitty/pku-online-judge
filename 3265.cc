#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int P=305,M=1005,inf=0x3f3f3f3f;
int dp[2][P][M];
int a[P],b[P];
int main()
{
    int m,p,ans=inf,x,y;
    scanf("%d%d",&m,&p);
    for(int i=1;i<=p;i++)
        scanf("%d%d",&a[i],&b[i]);
    memset(dp,0x3f,sizeof(dp));
    dp[1][0][0]=0;
    x=0,y=1;
    for(int i=1;;i++)
    {
        x=i&1;
        y=x^1;
        memset(dp[y],0x3f,sizeof(dp[y]));
        for(int j=0;j<=p;j++)
        {
            for(int k=0;k<=m;k++)
            {
                if(dp[x][j][k]!=inf)
                {
                    if(j==p)
                        ans=min(ans,(dp[x][j][k]==0)?i:(i+1));
                    else if(k>=a[j+1]&&dp[x][j][k]+b[j+1]<=m)
                        dp[x][j+1][k-a[j+1]]=min(dp[x][j+1][k-a[j+1]],dp[x][j][k]+b[j+1]);
                    dp[y][j][m-dp[x][j][k]]=0;
                }
            }
        }
        if(ans!=inf)
            break;
    }
    printf("%d\n",ans);
    return 0;
}




