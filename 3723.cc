#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int N = 52000;
const int M = 55000;
int u[N],v[N],w[N];
int cmp(int x,int y)
{
    return w[x]>w[y];
}
int father[N],p[N];
int find(int x)
{
    if(father[x]==x)
        return x;
    return father[x] = find(father[x]);
}
int kru(int n, int m)
{
    int ans=0, i;
    for(i=0; i<m; i++) p[i]=i;
    for(i=0; i<n; i++) father[i]=i;
    sort(p, p+m, cmp);
    for(i=0; i<m; i++) {
        int e=p[i];
        int x=find(u[e]); int y=find(v[e]);
        if(x!=y) {ans+=w[e]; father[x]=y;}
    }
    return ans;
}
int main()
{
    int n,m,r,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&r);
        for(int i=0;i<r;i++)
        {
            int x;
            scanf("%d%d%d",&u[i],&x,&w[i]);
            v[i] = x+n;
        }
        int css = kru(m+n,r);
        printf("%d\n",(n+m)*10000-css);
    }
    return 0;
}




