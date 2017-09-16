#include <cstdio>
#include <cstring>
#include <cstdlib>

#define N 120
#define WC 10000

using namespace std;

int n,t,a[N],pre[N],dp[N][20001];

void read()
{
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
}

void go()
{
    memset(dp,0,sizeof dp);
    memset(pre,0,sizeof pre);
    dp[1][a[1]+WC]=2;
    dp[2][a[1]-a[2]+WC]=1;
    for(int i=3;i<=n;i++)
        for(int j=0;j<=20000;j++)
            if(dp[i-1][j]>0)
            {
                if(j+a[i]<=20000) dp[i][j+a[i]]=2;
                if(j-a[i]>=0) dp[i][j-a[i]]=1;
            }
    for(int i=n,j=t+WC;i>=1;i--)
    {
        if(dp[i][j]==2)
        {
            pre[i]=2;
            j-=a[i];
        }
        else if(dp[i][j]==1)
        {
            pre[i]=1;
            j+=a[i];
        }
    }
    int cnt=0;
    for(int i=2;i<=n;i++)
        if(pre[i]==2) printf("%d\n",i-1-cnt),cnt++;
    for(int i=2;i<=n;i++)
        if(pre[i]==1) puts("1");
}

int main()
{
    while(scanf("%d%d",&n,&t)!=EOF)
    {
        read();
        go();
    }
    return 0;
}



