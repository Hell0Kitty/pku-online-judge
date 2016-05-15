#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
ll pow_mod(ll a,ll b,ll c)
{
    ll res=1;
    while(b)
    {
        if(b&1) res=res*a%c;
        a=a*a%c;
        b>>=1;
    }
    return res;
}

int main()
{
    int a,n,ant=1,ans,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&n);
        ans=pow_mod(a,(n-1)/2,n);
        printf("Scenario #%d:\n",ant++);
        if(ans == n-1) printf("-1\n");
        else printf("1\n");
        printf("\n");
    }
    return 0;
}


