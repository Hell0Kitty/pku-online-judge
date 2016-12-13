#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <set>
#include <queue>
#define maxn 200005
#define MAXN 1000000
#define mod 1000000000
#define INF 0x3f3f3f3f
using namespace std;

int n,m,ans;
int f[2*maxn][20];
int a[maxn],dp[maxn],pre[maxn];
int pos[2*MAXN+5];

void init_rmq()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        f[i][0]=dp[i];
    }
    for(j=1;(1<<j)<=n;j++)
    {
        for(i=1;i+j-1<=n;i++)
        {
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
}
int query_rmq(int l,int r)
{
    int k=0;
    while((1<<(k+1))<=r-l+1) k++;
    return max(f[l][k],f[r-(1<<k)+1][k]);
}
void presolve()
{
    int i,j;
    memset(pos,0,sizeof(pos));
    a[0]=-1;
    for(i=1;i<=n;i++)
    {
        if(a[i]==a[i-1]) dp[i]=1;
        else dp[i]=min(dp[i-1]+1,i-pos[a[i]]);
        pos[a[i]]=i;
        pre[i]=i-dp[i]+1;
    }
}
void solve()
{
    int i,j,t,u,v,pos;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&u,&v);
        u++,v++;
        ans=0;
        pos=lower_bound(pre+1,pre+n+1,u)-pre;
        if(pos<=v)  
        {
            ans=max(ans,query_rmq(pos,v));
            ans=max(ans,pos-u);
        }
        else ans=max(ans,v-u+1); 
        printf("%d\n",ans);
    }
}
int main()
{
    int i,j;
    while(~scanf("%d%d",&n,&m))
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            a[i]+=MAXN;
        }
        presolve();
        init_rmq();
        solve();
    }
    return 0;
}


