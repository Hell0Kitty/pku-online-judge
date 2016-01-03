#include <stdio.h>
#include <string.h>
#include <stack>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#define LL long long int
using namespace std;
long long  gcd(long long  a,long long  b)
{
   return b==0?a:gcd(b,a%b);
}
int shuru()
{
    int res = 0, flag = 0;
    char ch;
    if((ch = getchar()) == '-') flag = 1;
    else if(ch >= '0' && ch <= '9') res = ch - '0';
    while((ch = getchar()) >= '0' && ch <= '9')
        res = res * 10 + (ch - '0');
    return flag ? -res : res;
}
int main()
{
    int t;
    t=shuru();
    while(t--)
    {
        bool flag=false;
        int n;
        int m;
        n=shuru();
        long long k=1;
        for(int i=0;i<n;i++)
        {
           m=shuru();
            if(!flag) k=k*m/gcd(k,m);
            if(k>1000000000) flag=true;
        }
         if(flag) puts("More than a billion.");
        else printf("%lld\n",k);
    }
    return 0;
}



