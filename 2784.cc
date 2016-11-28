#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
#define INF 999999999
int q;
int cost[10];
vector<int>mm[10];
int p[1100*1100];
struct edge
{
    int u;
    int v;
    int w;
}r[1100*1100];
int n,m;
int cmp(struct edge a,struct edge b) {return a.w<b.w;}
int find(int x) {return p[x]==x?x:p[x]=find(p[x]);}
bool merge(int a,int b)
{
    int x=find(a);
    int y=find(b);
    if(x==y)
        return false;
    p[x]=y;
    return true;
}

int kruskal()
{
    int ans=0;
    for(int i=0;i<m;i++)
    {
            int x=find(r[i].u);
            int y=find(r[i].v);
            if(x!=y)
            {
                ans+=r[i].w;
                p[x]=y;
            }

    }
    return ans;

}

void solve()
{
    int ans;
    int tt;
    for(int i=1;i<=n;i++) p[i]=i;//鍒濆鍖栧苟鏌ラ泦锛屾敞鎰忛鐩粠0杩樻槸1
    ans=kruskal();
    for(int s=1;s<(1<<q);s++)
    {
        tt=0;
        for(int i=1;i<=n;i++) p[i]=i;//鍒濆鍖栧苟鏌ラ泦锛屾敞鎰忛鐩粠0杩樻槸1
        for(int j=0;j<q;j++)
        {

            if(!((1<<j)&s)) continue;

                tt+=cost[j];
                for(int i=1;i<mm[j].size();i++)
                {
                    merge(mm[j][i],mm[j][0]);
                }
        }
        ans=min(tt+kruskal(),ans);
    }
    printf("%d\n",ans);
}
int main()
{
    int n1,p1;
    int x[1005],y[1005];
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        for(int i=0;i<=10;i++)
            mm[i].clear();
        for(int i=0;i<q;i++)
        {
            scanf("%d%d",&n1,&p1);
            cost[i]=p1;
            for(int j=0;j<n1;j++)
            {
                int aa;
                scanf("%d",&aa);
                mm[i].push_back(aa);
            }
        }
        //m=n*(n-1)/2;
        for(int i=1;i<=n;i++)
            scanf("%d%d",&x[i],&y[i]);
        m=0;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
        {
            r[m].u=i;
            r[m].v=j;
            r[m].w=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
            m++;
        }
        sort(r,r+m,cmp);
        solve();
    }
    return 0;
}


