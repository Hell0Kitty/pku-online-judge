#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<queue>
#include<vector>
#include<map>
#include<set>
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int maxd=200000+5;

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1 | 1
typedef long long ll;
typedef pair<int,int> pii;
//---------------------------
int n,res[maxd<<2],p[maxd],v[maxd],ans[maxd];

void pushup(int rt)
{
    res[rt]=res[rt<<1]+res[rt<<1|1];
}

void build(int l,int r,int rt)
{
    if(l==r)
    {
        res[rt]=1;
        return;
    }
    int m=(l+r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}

void query(int pos,int val,int l,int r,int rt)
{
    //res[rt]--;
    if(l==r)
    {
        ans[l]=val;
        res[rt]--;
      // pushup(rt);
        return;
    }
    int m=(l+r)>>1;
    if(pos<=res[rt<<1]) query(pos,val,lson);
    else query(pos-res[rt<<1],val,rson);
    pushup(rt);
}

int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        build(1,n,1);

        for(int i=0; i<n; ++i)
            scanf("%d%d",&p[i],&v[i]);

        for(int i=n-1; i>=0; --i)
            query(p[i]+1,v[i],1,n,1);

        for(int i=1; i<=n; ++i)
            printf("%d%c",ans[i],i<n?' ':'\n');
    }

    return 0;
}


