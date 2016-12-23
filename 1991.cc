#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define N 1005
#define INF 10000005
int dp[N][N][2];
struct node
{
    int x;
    int t;
} a[N];
int cmp(node a,node b)
{
    if(a.x==b.x)
        return a.t<b.t;
    return a.x<b.x;
}
void DP(int n)
{
//大区间推出小区间
    dp[1][n][0] = max(a[1].x, a[1].t);
    dp[1][n][1] = max(a[n].x, a[n].t);
    for(int d=n-2; d>=0; d--)
    {
        for(int i=1; i+d<=n; i++)
        {
            int s=i;
            int e=i+d;
            dp[s][e][0]=INF;

            if(s-1>0)
            {
                dp[s][e][0]=min(dp[s][e][0],dp[s-1][e][0]+a[s].x-a[s-1].x);
            }
            if(e+1<=n)
            {
                dp[s][e][0]=min(dp[s][e][0],dp[s][e+1][1]+a[e+1].x-a[s].x);
            }
            if(dp[s][e][0]<a[s].t)
                dp[s][e][0]=a[s].t;

            dp[s][e][1]=INF;
            if(e+1<=n)
            {
                dp[s][e][1]=min(dp[s][e][1],dp[s][e+1][1]+a[e+1].x-a[e].x);
            }
            if(s-1>0)
            {
                dp[s][e][1]=min(dp[s][e][1],dp[s-1][e][0]+a[e].x-a[s-1].x);
            }
            if(dp[s][e][1]<a[e].t)
                dp[s][e][1]=a[e].t;

        }
    }
}
int main()
{
    int C,H,B;
    scanf("%d%d%d",&C,&H,&B);
    for(int i=1; i<=C; i++)
    {
        scanf("%d%d",&a[i].x,&a[i].t);
    }
    sort(a+1,a+C+1,cmp);
    a[0].x=0;
    a[0].t=0;
    DP(C);
    int ans=INF;

    for(int i=1; i<=C; i++)
    {
        ans=min(min(dp[i][i][0]+abs(a[i].x-B),dp[i][i][1]+abs(a[i].x-B)),ans);
    }
    printf("%d\n",ans);
    return 0;
}



