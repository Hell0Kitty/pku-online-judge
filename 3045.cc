#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e5+10;
long long  num[N];
long long  n,m,k;
struct node
{
    long long  sum ,w,s;
} pp[N];
bool cmp(node a,node b)
{
    return a.w+a.s<b.w+b.s;
    //if(a.w!=b.w) return a.w<=b.w;
    //else  return a.s<=b.s;
}
int main()
{
    //freopen("1.txt","r",stdin);
    scanf("%lld",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%lld%lld",&pp[i].w,&pp[i].s);
    }
    sort(pp,pp+n+1,cmp);
    pp[1].sum=0;
    for(int i=2; i<=n; i++)
    {
        pp[i].sum=pp[i-1].sum+pp[i-1].w;
    }
    long long maxx=-1e10;
    for(int i=1; i<=n; i++)
    {
        maxx=max(pp[i].sum-pp[i].s,maxx);
    }
    printf("%lld\n",maxx);
    return 0;
}



