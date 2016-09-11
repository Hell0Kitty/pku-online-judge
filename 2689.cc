#include <cstdio>
#include <cstring>
using namespace std;
int prime[4948],top=0;
bool isp[48005];
inline void init()
{
    int i,j,k;
    memset(isp,1,sizeof(isp));
    for(i=2;i<=48000;++i)
    {
        if(isp[i])prime[top++]=i;
        for(j=0;j<top;++j)
        {
            if(i*prime[j]>48000)break;
            isp[i*prime[j]]=0;
            if(!(i%prime[j]))break;
        }
    }
}
bool tmp[1000005];
inline void solve(int l,int r)
{
    int i,j,k,a,b,aa,bb;bool*p=tmp-l;
    int m=0x7fffffff,M=0x80000000;
    memset(tmp,1,sizeof(tmp));
    if(l==1)p[1]=0;
    for(i=0;i<top;++i)
    {
        if(prime[i]>r)break;
        j=(l-1)/prime[i]+1;if(j==1)++j;
        for(j*=prime[i];j>0&&j<=r;j+=prime[i])
            p[j]=0;
    }
    for(i=l;i<r;++i)
    {
        if(!p[i])continue;
        for(j=i+1;j<=r;++j)
            if(p[j])break;
        if(j>r)break;

        if(m>j-i){m=j-i;a=i;b=j;}
        if(M<j-i){M=j-i;aa=i;bb=j;}
    }
    if(m==0x7fffffff)
    {
        puts("There are no adjacent primes.");
        return;
    }
    printf("%d,%d are closest, %d,%d are most distant.\n",a,b,aa,bb);
}
int main()
{
    int l,r;
    init();
    while(~scanf("%d%d",&l,&r))
        solve(l,r);
    return 0;
}


