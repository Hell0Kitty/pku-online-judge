#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

int min(int a,int b)
{
    if(a>b)a=b;
    return a;
}
int max(int a,int b)
{
    if(a<b)a=b;
    return a;
}
struct mnod
{
    long long x,y;
}node[5005];
int dp[1000005];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,dis,temp;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lld%lld",&node[i].x,&node[i].y);
        }
        memset(dp,-1,sizeof(dp[0])*(node[n-1].x+2));
        dp[node[0].x]=0;
        for(int i=1;i<n;i++)
        {
            dis=sqrt(node[i].y*node[i].y-(node[i].y-node[0].y)*(node[i].y-node[0].y));
            for(int j=1;j<=dis;j++)
            {
                if(node[i].x-j<node[0].x)break;
                if(dp[node[i].x-j]==-1)continue;
                else
                {
                    temp=min(node[i].x+j,node[n-1].x);
                    if(dp[temp]==-1)dp[temp]=dp[node[i].x-j]+1;
                    else dp[temp]=min(dp[temp],dp[node[i].x-j]+1);
                }
            }
        }
        printf("%d\n",dp[node[n-1].x]);
    }
    return 0;
}



