#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 10010
#define inff 0x3fffffff

int p[maxn];
int dp[maxn];
int num,res;
int con[maxn];
struct node
{
    int en,next;
}bian[maxn*3];

void add(int st,int en)
{
    bian[num].en=en;
    bian[num].next=p[st];
    p[st]=num++;
}
void dfs(int u,int fa,int n)
{
    con[u]=1,dp[u]=0;
    int i,v;
    for(i=p[u];i+1;i=bian[i].next)
    {
        v=bian[i].en;
        if(v==fa)
            continue;
        dfs(v,u,n);
        con[u]+=con[v];
        dp[u]=max(dp[u],con[v]);
    }

    dp[u]=max(dp[u],n-con[u]);

    res=min(dp[u],res);
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        num=0;
        memset(p,-1,sizeof(p));
        int i,x,y;
        for(i=1;i<n;i++)
        {
            scanf("%d %d",&x,&y);
            add(x,y);
            add(y,x);
        }
        res=inff;
        dfs(1,-1,n);
        for(i=1;i<=n;i++)
            if(dp[i]==res)
                printf("%d\n",i);
    }
    return 0;
}



