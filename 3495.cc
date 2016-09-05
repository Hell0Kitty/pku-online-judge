#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
long long x,y,z;
long long Calculate(long long a,long long b,long long c,long long n)
{
    if(n==0) return 0;
    return (b/c)*n+(a/c)*n*(n-1)/2+Calculate(c,(a*n+b)%c,a%c,(a%c*n+b%c)/c);
}
int main()
{
    int i;
    while(cin>>x>>y>>z)
    {
        long long ans=0;
        for(i=0;i<32;i++)
            ans|=(Calculate(z,x,1ll<<i,(y-x)/z+1)&1ll)<<i;
        cout<<ans<<endl;
    }
    return 0;
}


