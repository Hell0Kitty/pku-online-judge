#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

#define N 250
#define M 500000
#define INF 1e9

using namespace std;

int head[N],next[M],to[M],pr[M],len[M];
int q[N*M],dis[N],pre[N],im[N];
int map[N][N],hx[N],hy[N],hp[N],sx[N],sy[N],sr[N],sum[N];
int rc[N][N];
bool vis[N];
int n,m,cnt,S,T,rt;

inline void prep()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            map[i][j]=abs(hx[i]-sx[j])+abs(hy[i]-sy[j])+1;
}

inline void add(int u,int v,int r,int w)
{
    to[cnt]=v; len[cnt]=r; pr[cnt]=w; next[cnt]=head[u]; head[u]=cnt++;
}

inline void read()
{
    memset(sum,0,sizeof sum);
    memset(head,-1,sizeof head); cnt=0;
    for(int i=1;i<=n;i++) scanf("%d%d%d",&hx[i],&hy[i],&hp[i]);
    for(int i=1;i<=m;i++) scanf("%d%d%d",&sx[i],&sy[i],&sr[i]);
    prep();
    for(int i=1,a;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&a); rc[i][j]=a;
            add(i,n+j,INF-a,map[i][j]);
            add(n+j,i,a,-map[i][j]);
            sum[j]+=a;
        }
    S=0; T=n+m+1;
    for(int i=1;i<=n;i++) add(S,i,0,0),add(i,S,hp[i],0);
    for(int i=1;i<=m;i++) add(i+n,T,sr[i]-sum[i],0),add(T,i+n,sum[i],0);
}

inline int spfa()
{
    memset(vis,0,sizeof vis);
    memset(dis,0x3f,sizeof dis);
    memset(im,0,sizeof im);
    memset(pre,-1,sizeof pre);
    int h=1,t=2,sta;
    dis[T]=0; vis[T]=true; q[1]=T; im[T]++;
    while(h<t)
    {
        sta=q[h++]; vis[sta]=false;
        for(int i=head[sta];~i;i=next[i])
            if(len[i]&&dis[to[i]]>dis[sta]+pr[i])
            {
                dis[to[i]]=dis[sta]+pr[i];
                pre[to[i]]=sta;
                if(!vis[to[i]])
                {
                    vis[to[i]]=true; q[t++]=to[i]; ++im[to[i]];
                    if(im[to[i]]>n+m+2) return to[i];
                }
            }
    }
    return -1;
}

inline void go()
{
    int rt=spfa();
    int st;
    if(rt==-1) {puts("OPTIMAL");return;}
    puts("SUBOPTIMAL"); 
    memset(vis,0,sizeof vis);
    int sta=rt;
    while(true)
    {
        if(!vis[sta]) vis[sta]=true,sta=pre[sta];
        else {rt=sta;break;}
    }
    do
    {
        int from=pre[sta],to=sta;
        if(from<=n&&to>n) rc[from][to-n]++;
        if(to<=n&&from>n) rc[to][from-n]--;
        sta=pre[sta];
    }while(sta!=rt);
    for(int i=1;i<=n;i++)
    {
        printf("%d",rc[i][1]);
        for(int j=2;j<=m;j++)
            printf(" %d",rc[i][j]);
        puts("");
    }
}

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF) read(),go();
    return 0;
}



