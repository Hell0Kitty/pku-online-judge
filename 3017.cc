#include<iostream>
#include<algorithm>
#include<set>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=110002;
int q[maxn],a[maxn],pre,n;
__int64 sum,Max[maxn],m;
int main()
{
    scanf("%d%I64d",&n,&m);
    int i,j,l=0,r=-1,flag=0;
    pre=1,sum=0;
    Max[n]=-1;
    multiset<int>s;
    s.clear();
    for(i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
        while(sum>m) sum-=a[pre++];
        if(a[i]>m) flag=1;
        if(flag) continue;
        while(l<=r&&a[i]>=a[q[r]])
        {
            if(l<r)s.erase(Max[q[r-1]]+a[q[r]]);
            r--;
        }
        q[++r]=i;
        if(l<r) s.insert(Max[q[r-1]]+a[q[r]]);
        while(q[l]<pre)
        {
            if(l<r)s.erase(Max[q[l]]+a[q[l+1]]);
            l++;
        }
        Max[i]=Max[pre-1]+a[q[l]];
        __int64 ans=*s.begin();
        if(l<r&&Max[i]>ans) Max[i]=ans;
    }
    if(flag) printf("-1\n");
    else
    {
        printf("%I64d\n",Max[n]);
    }
    return 0;
}



