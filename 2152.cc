#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define N 1010
#define M (1<<30)
struct City{
    int d,w;
}city[N];
struct lianjie{
    int child,d;
    lianjie(int x,int y)
    {
        child=x;d=y;
    }
};
vector <lianjie> tree[N];
int num,dist[N],best[N],dp[N][N];
void init()
{
    scanf("%d",&num);
    int i,u,v,l;
    for(i=1;i<=num;i++) tree[i].clear();
    for(i=1;i<=num;i++) scanf("%d",&city[i].w);
    for(i=1;i<=num;i++) scanf("%d",&city[i].d);
    for(i=1;i<num;i++)
    {
        scanf("%d%d%d",&u,&v,&l);
        tree[u].push_back(lianjie(v,l));
        tree[v].push_back(lianjie(u,l));
    }
}
void dis(int key)
{
    int length=tree[key].size();
    for(int i=0;i<length;i++)
    {
        int v=tree[key][i].child;
        if(dist[v]!=-1) continue;
        dist[v]=dist[key]+tree[key][i].d;
        dis(v);
    }
}
void dfs(int key,int parent)
{
    int i,j,v,length=tree[key].size();

    for(i=0;i<length;i++)
    {
        v=tree[key][i].child;
        if(v!=parent)        dfs(v,key);
    }
    memset(dist,-1,sizeof(dist));
    dist[key]=0;    best[key]=M;    dis(key);
    for(i=1;i<=num;i++)
    {
        if(dist[i]>city[key].d) dp[key][i]=M;
        else
        {
            dp[key][i]=city[i].w;
            for(j=0;j<length;j++)
            {
                v=tree[key][j].child;
                if(v!=parent)
                dp[key][i]+=min(best[v],dp[v][i]-city[i].w);
            }
            best[key]=min(best[key],dp[key][i]);
        }
    }
}
int main()
{
    int T;cin>>T;
    while(T--)
    {
        init();        dfs(1,0);
        cout<<best[1]<<endl;
    }
    return 0;
}



