#include<cstdio>
#include<cstring>
using namespace std;
const int mod=10000;
int main()
{
    int p,n,ca=0;
    while(scanf("%d%d",&p,&n),n||p)
    {
        int ans=1;
        while(n)
        {
            ans*=(n%p+1);
            n/=p;
            if(ans>=mod)
                ans%=mod;
        }
        printf("Case %d: %04d\n",++ca,ans);
    }
    return 0;
}



