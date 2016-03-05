#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

#define MAXN 310
#define MOD 1000000000

char str[MAXN];
long long  dp[MAXN][MAXN];

long long dfs(int i,int j)
{
    if(i==j) return 1;
    if(str[i]!=str[j]) return 0;
    if(dp[i][j]>=0) return dp[i][j];
    dp[i][j]=0;
    for(int k=i+2;k<=j;k++)
        if(str[i]==str[k])
            dp[i][j]=(dp[i][j]+dfs(i+1,k-1)*dfs(k,j))%MOD;
    return dp[i][j];
}

int main()
{
    while(~scanf("%s",str))
    {
       for(int i=0;i<310;i++)
        for(int j=0;j<310;j++)
            dp[i][j]=-1;
        printf("%lld\n",dfs(0,strlen(str)-1));
    }
    return 0;
}



