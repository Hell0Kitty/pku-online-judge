#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Edge
{
    int a,b,next;
}edge[100];
int head[100],nc,ans,pos;
bool mark[100];
void add(int a,int b)
{
    edge[nc].a=a;edge[nc].b=b;edge[nc].next=head[a];head[a]=nc++;
}
void dfs(int now,int len)
{
    if(len>ans)
        ans=len,pos=now;
    for(int i=head[now];i!=-1;i=edge[i].next)
    {
        if(mark[i>>1])
            continue;
        int t=i>>1;
        mark[t]=true;
        dfs(edge[i].b,len+1);
        mark[t]=false;
    }
}
int main()
{
    int n,m,a,b;
    while(scanf("%d%d",&n,&m),n||m)
    {
        nc=ans=pos=0;
        memset(head,-1,sizeof(head));
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            add(a,b);add(b,a);
        }
        memset(mark,false,sizeof(mark));
        dfs(0,0);
        dfs(pos,0);
        printf("%d\n",ans);
    }
    return 0;
}



