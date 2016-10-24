#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=5e3+9;
int n,m;
int a[maxn];
struct
{
    struct
    {
        int next,to;
    }e[maxn*10];
    int head[maxn],lon;
    void clear()
    {
        memset(head,-1,sizeof(head));
        lon=-1;
    }
    void add(int from,int to)
    {
        e[++lon].to=to;
        e[lon].next=head[from];
        head[from]=lon;
    }
}edge;

struct
{
    int head[111111],lon;
    struct
    {
        int t,dist,next,sum;
    }data[1111111];
    void clear()
    {
        memset(head,-1,sizeof(head));
        lon=-1;
    }
    bool push(int t,int dist,int sum)
    {
        int key=(t+abs(dist)%360*n)%111111;
        for(int k=head[key];k!=-1;k=data[k].next)
        {
            if(t==data[k].t&&dist==data[k].dist)
            return false;
        }
        data[++lon].t=t;
        data[lon].dist=dist;
        data[lon].next=head[key];
        data[lon].sum=sum;
        head[key]=lon;
        return true;
    }
}hash;

struct
{
    int t,dist,sum;
}que[1111111];
int bfs()
{
    hash.clear();
    int front=1,end=0;
    que[++end].t=1;
    que[end].sum=que[end].dist=0;
    hash.push(1,0,0);

    while(front<=end)
    {
        int t=que[front].t;
        int dist=que[front].dist;
        int sum=que[front++].sum;
        for(int k=edge.head[t];k!=-1;k=edge.e[k].next)
        {
            int u=edge.e[k].to;
            int c=(a[u]+360-a[t])%360;
            int uc=(a[t]+360-a[u])%360;
            int tmp;
            if(c<uc) tmp=c;
            else tmp=-uc;
            if(u==1&&dist+tmp!=0) return sum+1;
            if(hash.push(u,dist+tmp,sum+1))
            {
                que[++end].t=u;
                que[end].dist=dist+tmp;
                que[end].sum=sum+1;
            }
        }
    }
    return -1;
}

int main()
{
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        edge.clear();
        for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
        for(int i=1,from,to;i<=m;i++)
        {
            scanf("%d %d",&from,&to);
            edge.add(from,to);
            edge.add(to,from);
        }
        cout<<bfs()<<endl;
    }
    return 0;
}


