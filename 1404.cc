#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#define ll long long
#define maxn 50000000
#define inf 1000000000000000
using namespace std;

int N,M;
ll dp[110][110];
int num[110][110];
ll val[110];
char s1[1000],s2[1000];
int pre;

ll f(int x,int y)
{
    int res=0;
    int i,j;
    for(i=x;i<=y;i++)
    {
        res+=val[i]*(i-x+1);
    }
    return res;
}

ll DP(int n,int m)
{
    int i,j;
    if(dp[n][m]!=-1)
    {
        return dp[n][m];
    }

    if(n==N)
    {
        if(m==M)
        {
            return 0;
        }
        else
        {
            return inf;
        }
    }

    dp[n][m]=inf;
    for(i=m+1;i<=M;i++)
    {
        ll temp=DP(n+1,i)+f(m,i-1);
        if(temp<dp[n][m])
        {
            dp[n][m]=temp;
            num[n][m]=i;
        }
    }
    return dp[n][m];
}

void output(int cur,int e)
{
    int i,j;
    printf("%c: ",s1[cur]);
    for(i=pre;i<e;i++)
    {
        printf("%c",s2[i]);
    }
    puts("");
    pre=e;
    if(cur==N-1)
    {
        return;
    }
    output(cur+1,num[cur+1][e]);
}
int main()
{
    int i,j;
    int T;
    scanf("%d",&T);
    int test=0;
    while(T--)
    {
        scanf("%d %d",&N,&M);
        scanf("%s %s",s1,s2);
        memset(dp,-1,sizeof(dp));
        for(i=0;i<M;i++)
        {
            scanf("%lld",&val[i]);
        }
        DP(0,0);
        printf("Keypad #%d:\n",++test);
        pre=0;
        output(0,num[0][0]);
        printf("\n");
    }
    return 0;
}



