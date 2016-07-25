#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int dp[110000],p[11000],p_low[11000],p_up[11000];
int max(int a,int b)
{
    return a>b?a:b;
}
int min(int a,int b)
{
    return a<b?a:b;
}
int abs(int n)
{
    return n>0?n:-n;
}
int main()
{
    int n,i,j,l,d,t;
    scanf("%d%d",&n,&l);
    for (i=0; i<n; i++)
    {
        scanf("%d",p+i);
    }
    if (n == 1)
    {
        printf("0\n");
        return 0;
    }
    d=l/(n-1);
    p_low[0]=0;
    p_up[0]=0;
    p_low[n-1]=l;
    p_up[n-1]=l;
    for (i=1; i<n-1; i++)
    {
        p_low[i]=max(d*i,l-(d+1)*(n-i-1));
        if (p_low[i] < 0)
            p_low[i]=0;
        p_up[i]=min((d+1)*i,l-d*(n-i-1));
        if (p_up[i] > l)
            p_up[i]=l;
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0]=p[0];
    for (i=1; i<n; i++)
    {
        for (j=p_up[i]; j>=p_low[i]; j--)
        {
            t=j-d;
            dp[j]=0x3f3f3f3f;
            if (t >= p_low[i-1] && t <= p_up[i-1])    
                dp[j]=min(dp[j],dp[t]+abs(j-p[i]));
            t--;
            if (t >= p_low[i-1] && t <= p_up[i-1])
                dp[j]=min(dp[j],dp[t]+abs(j-p[i]));
        }
    }
    printf("%d\n",dp[l]);
}



