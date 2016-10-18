#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=5e6+10;
int prime[maxn],t,vis[maxn];
void init()//打出素数表
{
    int i,j,k,m;
    m=(int)sqrt(maxn+0.5);
    t=0;
    memset(vis,0,sizeof(vis));
    for(i=2;i<=m;i++)
    {
        if(!vis[i])
        for(j=i*i;j<maxn;j+=i)
        vis[j]=1;
    }
    for(i=2;i<maxn;i++)
    if(!vis[i])prime[t++]=i;
}
int main()
{
    init();
    int n,T,m;
    scanf("%d",&T);
    while(T--)
    {
        int i,j,k,ans=1,t=0;
        scanf("%d",&n);
        m=(int)sqrt(n+0.5);
        for(i=0;prime[i]<=m;i++)
        {
            if(n%prime[i]==0)
            {
                t=0;
                while(n%prime[i]==0){n=n/prime[i];t++;}
                ans=ans*(t+1)*(t+1)*(t+2)*(t+2)/4;
            }
        }
        if(n>1)ans*=9;
        printf("%d\n",ans);
    }
    return 0;
}



