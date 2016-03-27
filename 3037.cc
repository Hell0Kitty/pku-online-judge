#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#define INF 100000000
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
struct Edge
{
    int from,to;
    double d;
    int pre;
}e[40005];
int h[10005]={0},cou=0;
void Addedge(int from,int to,double ds)
{
    cou++;
    e[cou]=((Edge){from,to,ds,h[from]});
    h[from]=cou;
}
int n,m;
inline int bh(int i,int j)
{
    return (i-1)*m+j;
}
int hi[10005],inq[10005];
double dis[10005];
int main()
{
    double v0,v;
    int i,j,x,u;
    cin>>v0>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            x=bh(i,j);
            //printf("i=%d j=%d\n",i,j);
            //cout<<x<<endl;
            scanf("%d",&hi[x]);
            v=pow(2.0,double(hi[x]-hi[1]));
            //cout<<double(hi[x]-hi[1])<<' '<<v<<endl;
            if(i!=1)
                Addedge(x,x-m,v);
            if(i!=n)
                Addedge(x,x+m,v);
            if(j!=1)
                Addedge(x,x-1,v);
            if(j!=m)
                Addedge(x,x+1,v);
            dis[x]=1e50;
        }
    queue<int> q;
    dis[1]=0;
    q.push(1);
    inq[1]=1;
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        inq[x]=0;
        for(i=h[x];i;i=e[i].pre)
        {
            u=e[i].to;
            if(dis[u]>e[i].d+dis[x])
            {
                dis[u]=e[i].d+dis[x];
                if(!inq[u])
                {
                    q.push(u);
                    inq[u]=1;
                }
            }
        }
    }
    printf("%.2f\n",dis[n*m]/v0);
    return 0;
}




