#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=500,M=10000;
const int inf=10000000;
int head[N],nc;
struct Edge
{
    int x,y,next,cap;
} edge[M*4],sav[M*4];
void add(int x,int y,int cap)
{
    edge[nc].x=x;
    edge[nc].y=y;
    edge[nc].cap=cap;
    edge[nc].next=head[x];
    head[x]=nc++;
    edge[nc].x=y;
    edge[nc].y=x;
    edge[nc].cap=0;
    edge[nc].next=head[y];
    head[y]=nc++;
}
int num[N],h[N],S,T,n,nn,m;
int findpath(int x,int flow)
{
    if(x==T)
        return flow;
    int res=flow,pos=n-1;
    for(int i=head[x]; i!=-1; i=edge[i].next)
    {
        int y=edge[i].y;
        if(h[x]==h[y]+1&&edge[i].cap>0)
        {
            int tp=findpath(y,min(edge[i].cap,res));
            res-=tp;
            edge[i].cap-=tp;
            edge[i^1].cap+=tp;
            if(!res||h[S]==n)
                return flow-res;
        }
        if(edge[i].cap>0&&h[y]<pos)
            pos=h[y];
    }
    if(res==flow)
    {
        num[h[x]]--;
        if(num[h[x]]==0)
        {
            h[S]=n;
            return flow-res;
        }
        h[x]=pos+1;
        num[h[x]]++;
    }
    return flow-res;
}
int Sap()
{
    memset(h,0,sizeof(h));
    memset(num,0,sizeof(num));
    int ans=0;
    num[0]=n;
    while(h[S]!=n)
        ans+=findpath(S,inf);
    return ans;
}
int g[205][205];
void rdfs(int x)
{
    for(int i=head[x];i!=-1;i=edge[i].next)
    {
        if((i&1)&&(edge[i].cap))
        {
            edge[i].cap--;
            edge[i^1].cap++;
            rdfs(edge[i].y);
        }
    }
}
void dfs(int x)
{
    for(int i=head[x];i!=-1;i=edge[i].next)
    {
        if((!(i&1)))
        {
            if(edge[i].y==x+nn&&edge[i].cap==0)
            {
                edge[i].cap++;
                edge[i^1].cap--;
                dfs(edge[i].y);
            }
            else if(edge[i].cap<inf)
            {
                edge[i].cap++;
                edge[i^1].cap--;
                dfs(edge[i].y);
            }
        }
    }
}
int main()
{
    while(scanf("%d%d%d",&n,&S,&T)!=EOF)
    {
        bool flag=false;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&g[i][j]);
                if(g[i][j]&&i==S&&j==T)
                    flag=true;
            }
        }
        if(flag)
        {
            printf("NO ANSWER!\n");
            continue;
        }
        memset(head,-1,sizeof(head));
        nc=0;
        for(int i=1;i<=n;i++)
        {
            if(i!=S&&i!=T)
                add(i,i+n,1);
            for(int j=1;j<=n;j++)
            {
                if(g[i][j]&&i!=j)
                {
                    if(i==S)
                        add(i,j,inf);
                    else if(i!=T)
                        add(i+n,j,inf);
                }
            }
        }
        memcpy(sav,edge,sizeof(Edge)*nc);
        nn=n;
        n=n*2-2;
        int ans=Sap();
        printf("%d\n",ans);
        for(int i=1;i<=nn;i++)
        {
            if(i!=S&&i!=T)
                for(int j=head[i];j!=-1;j=edge[j].next)
                {
                    if(edge[j].cap==0&&edge[j].y==i+nn)
                    {
                        sav[j].cap=sav[j^1].cap=0;
                        memcpy(edge,sav,sizeof(Edge)*nc);
                        if(Sap()!=ans-1)
                        {
                            sav[j].cap=1;
                            sav[j^1].cap=0;
                            continue;
                        }
                        if(flag)
                            printf(" ");
                        else
                            flag=true;
                        printf("%d",i);
                        ans--;
                        break;
                    }
                }
        }
        printf("\n");
    }
    return 0;
}



