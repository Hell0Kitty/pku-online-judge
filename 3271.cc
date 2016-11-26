#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=30+9;
int dist[maxn][maxn],a[maxn][maxn];
int n,m;
bool d[maxn][maxn][maxn][maxn];
int quex[maxn*maxn],quey[maxn*maxn];
long long ans[maxn][maxn];
bool text[maxn][maxn];
void bfs2(int t,int s)
{
    int front=1,end=0;
    quex[++end]=t;
    quey[end]=s;
    memset(dist,50,sizeof(dist));
    memset(ans,0,sizeof(ans));
    dist[t][s]=0;
    ans[t][s]=1;
    while(front<=end)
    {
        int x=quex[front],y=quey[front++];
        if(a[x][y]==2) continue;
        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        if(d[x][y][i][j])
        {
            if(dist[i][j]==dist[x][y]+1)
            ans[i][j]+=ans[x][y];
            else if(dist[i][j]>dist[x][y]+1)
            {
                dist[i][j]=dist[x][y]+1;
                ans[i][j]=ans[x][y];
                quex[++end]=i;
                quey[end]=j;
            }
        }
    }
}

void bfs(int t,int s)
{
    memset(text,0,sizeof(text));
    int front=1,end=0;
    quex[++end]=t;
    quey[end]=s;
    text[t][s]=1;
    while(front<=end)
    {
        int x=quex[front],y=quey[front++];
        for(int i=-1;i<=1;i+=2)
        for(int j=-1;j<=1;j+=2)
        for(int k=1;k<=2;k++)
        {
            int tmp=1;
            if(k==1) tmp=2;
            int tox=x+i*k,toy=j*tmp+y;
            if(tox>=1&&tox<=n&&toy>=1&&toy<=m)
            if(!text[tox][toy])
            {
                text[tox][toy]=1;
                if(a[tox][toy]==1)
                {
                    quex[++end]=tox;
                    quey[end]=toy;
                }
                else
                {
                    d[t][s][tox][toy]=1;
                }
            }
        }
    }
}

int main()
{
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        int t,s,tox,toy;
        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]==3)
            {
                t=i;
                s=j;
            }
            else if(a[i][j]==4)
            {
                tox=i;
                toy=j;
            }
        }
        memset(d,0,sizeof(d));
        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        bfs(i,j);
        bfs2(t,s);
        if(dist[tox][toy]>1e3)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n%lld\n",dist[tox][toy]-1,ans[tox][toy]);
        }
    }
    return 0;
}



