#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
typedef long long int64;
int64 gcd(int64 a,int64 b)
{
    return b==0?a:gcd(b,a%b);
}
int64 mult_mod(int64 a,int64 b,int64 c)
{
    int64 ret=0;
    int64 tmp=a;
    a%=c,b%=c;
    while(b)
    {
        if(b&1)
        {
            ret+=tmp;
            if(ret>c)   ret-=c;
        }
        tmp<<=1;
        if(tmp>c)tmp-=c;
        b>>=1;
    }
    return ret;
}
int64 pow_mod(int64 a,int64 n,int64 mod)
{
    int64 ret = 1;
    int64 tmp = a%mod;
    while(n)
    {
        if(n & 1)ret = mult_mod(ret,tmp,mod);
        tmp = mult_mod(tmp,tmp,mod);
        n >>= 1;
    }
    return ret;
}
bool check(int64 a,int64 n,int64 x,int64 t)
{
    int64 ret = pow_mod(a,x,n);
    int64 last = ret;
    for(int i = 1;i <= t;i++)
    {
        ret = mult_mod(ret,ret,n);
        if(ret == 1 && last != 1 && last != n-1)return true;
        last = ret;
    }
    if(ret != 1)return true;
    else return false;
}
bool Miller_Rabin(long long n,int k)
{
    if( n < 2)return false;
    if( n == 2)return true;
    if( (n&1) == 0)return false;
    long long x = n - 1;
    long long t = 0;
    while( (x&1)==0 ){x >>= 1; t++;}
    srand(time(NULL));
    for(int i=0;i<k;i++)
    {
        long long a = rand()%(n-1) + 1;
        if( check(a,n,x,t) )
        return false;
    }
    return true;
}
int64 factor[10000];
int tot;
int64 pollard_rho(int64 x,int64 c)
{
    int64 i=1, k=2;
    srand(time(NULL));
    int64 x0=rand()%(x-1)+1;
    int64 y=x0;
    while(1)
    {
        i++;
        x0=(mult_mod(x0,x0,x)+c)%x;
        int64 d=gcd(y-x0+x,x);
        if(d!=1&&d!=x)return d;
        if(y==x0)return x;
        if(i==k){y=x0;k+=k;}
    }
}
void findfac(int64 n,int k)
{
    if(n==1)return;
    if(Miller_Rabin(n,10))
    {
        factor[tot++]=n;
        return;
    }
    int64 p=n;
    int c=k;
    while(p>=n)
    p=pollard_rho(p,c--);
    findfac(p,k);
    findfac(n/p,k);
}
int64 mins,aa,bb;int top;
void dfs(int64 a,int64 b,int p)
{
    if(a+b>=mins) return;
    if(p==top)
    {
        if(a+b<mins)
        {
            mins=a+b;
            aa=a;
            bb=b;
        }
        return;
    }
    dfs(a*factor[p],b,p+1);
    dfs(a,b*factor[p],p+1);
}
int main()
{
    int64 g,l,c;
    while(~scanf("%I64d%I64d",&g,&l))
    {
        if(g==l){printf("%I64d %I64d\n",g,l);continue;};
        mins=~0ull>>1;tot=0;
        c=l/g;
        findfac(c,107);
        top=0;
        sort(factor,factor+tot);
        for(int i=0;i<tot;i++)
        {
            if(i==0) factor[top++]=factor[i];
            else if(factor[i]==factor[i-1]) factor[top-1]*=factor[i];
            else factor[top++]=factor[i];
        }
        dfs(g,g,0);
        if(aa>bb) swap(aa,bb);
        printf("%I64d %I64d\n",aa,bb);
    }
    return 0;
}



