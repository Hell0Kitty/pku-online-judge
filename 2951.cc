#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
int dp[405][25][25];
int dfs(int m,int w,int h)
{
    if(dp[m][w][h]!=inf)
        return dp[m][w][h];
    else if(m==0)
        return dp[m][w][h]=w*h;
    else
    {
        int ans=inf;
        for(int i=1,lim=w/2+1;i<=lim;i++)
            for(int k=0;k<=m-1;k++)
                ans=min(ans,max(dfs(k,i,h),dfs(m-1-k,w-i,h)));
        for(int i=1,lim=h/2+1;i<=lim;i++)
            for(int k=0;k<=m-1;k++)
                ans=min(ans,max(dfs(k,w,i),dfs(m-1-k,w,h-i)));
        return dp[m][w][h]=ans;
    }
}
int main()
{
    int w,h,m;
    memset(dp,0x3f,sizeof(dp));
    while(scanf("%d%d%d",&w,&h,&m),w||h||m)
        printf("%d\n",dfs(m-1,w,h));
    return 0;
}


