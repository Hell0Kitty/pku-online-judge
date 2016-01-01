#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=6000,M=1000000;
const int inff=1<<29;
int head[N],nc;
struct edge
{
    int x,y,next;
    int cap;
} edge[M*3];
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
int num[N],h[N],S,T,n;
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
    while(h[S]!=n)
        ans+=findpath(S,inff);
    return ans;
}
int cow[3000][2];
int main()
{
    int c,l;
    while(scanf("%d%d",&c,&l)!=EOF)
    {
        nc=0;
        memset(head,-1,sizeof(head));
        n=c+l+2;
        S=0,T=n-1;
        for(int i=1;i<=c;i++)
            scanf("%d%d",&cow[i][0],&cow[i][1]),add(S,i,1);
        for(int i=1;i<=l;i++)
        {
            int sp,co;
            scanf("%d%d",&sp,&co);
            add(i+c,T,co);
            for(int j=1;j<=c;j++)
                if(cow[j][0]<=sp&&cow[j][1]>=sp)
                    add(j,i+c,1);
        }
        printf("%d\n",Sap());
    }
    return 0;
}



