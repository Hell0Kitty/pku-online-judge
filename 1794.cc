#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#define lowbit(x) (x&(-x))
using namespace std;
int n,m;
struct Node
{
    int x,y;
}pos[60005];
int a[60005];
void modify(int pos,int c)
{
    while(pos<=n+m)
    {
        a[pos]+=c;
        pos+=lowbit(pos);
    }
}
long long query(int pos)
{
    long long ans=0;
    while(pos>0)
    {
        ans+=a[pos];
        pos-=lowbit(pos);
    }
    return ans;
}
bool cmp(Node a,Node b)
{
    if(a.y==b.y)
        return a.x>b.x;
    return a.y<b.y;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        memset(a,0,sizeof(a));
        if(cas!=1)
            printf("\n");
        printf("Scenario #%d:\n",cas);
        int x,y;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%d%d",&pos[i].x,&pos[i].y);
        for(int i=0;i<m;i++)
            scanf("%d%d",&pos[i+n].x,&pos[i+n].y);
        sort(pos,pos+n+m,cmp);
        long long ans=0;
        for(int i=0;i<n+m;i++)
        {
            modify(pos[i].x,1);
            ans+=pos[i].x-query(pos[i].x);
        }
        printf("%lld\n",ans);
    }
}



