#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e4+9;
int head[maxn],lon;
bool use[maxn];
int a[maxn],d[maxn],top,son[maxn];
int ans,n,m,mm;
struct
{
    int next,to,w;
}e[maxn<<1];

void edgeini()
{
    memset(head,-1,sizeof(head));
    lon=-1;
}
void edgemake(int from,int to,int w)
{
    e[++lon].to=to;
    e[lon].w=w;
    e[lon].next=head[from];
    head[from]=lon;
}
int maxson[maxn];
int dp(int t,int from)
{
    int now,tmp=1e5,ans;
    son[t]=maxson[t]=0;
    for(int k=head[t];k!=-1;k=e[k].next)
    {
        int u=e[k].to;
        if(use[u]||u==from) continue;
        now=dp(u,t);
        if(maxson[now]<tmp)
        {
            tmp=maxson[now];
            ans=now;
        }
        son[t]+=son[u];
        maxson[t]=max(maxson[t],son[u]);
    }
    son[t]++;
    maxson[t]=max(maxson[t],mm-son[t]);
    if(maxson[t]<tmp) ans=t;
    return ans;
}

void dfs(int t,int from)
{
    a[++top]=d[t];
    son[t]=0;
    for(int k=head[t],u;k!=-1;k=e[k].next)
    {
        u=e[k].to;
        if(use[u]||u==from) continue;
        d[u]=d[t]+e[k].w;
        dfs(u,t);
        son[t]+=son[u];
    }
    son[t]++;
}

int cal(int l,int r)
{
    int ret=0,now=r;
    for(int i=l;i<=now;i++)
    {
        while(now>i&&a[i]+a[now]>m) now--;
        ret+=now-i;
    }
    return ret;
}

void solve(int t)
{
    int now=dp(t,0);
    d[now]=top=0;
    use[now]=1;
    dfs(now,0);
    int ret=0,tmp=2;
    for(int k=head[now];k!=-1;k=e[k].next)
    {
        int u=e[k].to;
        if(use[u]) continue;
        sort(a+tmp,a+tmp+son[u]);
        ret+=cal(tmp,tmp+son[u]-1);
        tmp+=son[u];
    }
    sort(a+1,a+tmp);
    ans+=cal(1,tmp-1)-ret;
//    printf("%d %d\n",now,ans);
    for(int k=head[now];k!=-1;k=e[k].next)
    {
        int u=e[k].to;
        if(use[u]||son[u]==1) continue;
        mm=son[u];
        solve(u);
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
    while(scanf("%d %d",&n,&m),n&&m)
    {
        edgeini();
        for(int i=1,from,to,w;i<n;i++)
        {
            scanf("%d %d %d",&from,&to,&w);
            edgemake(from,to,w);
            edgemake(to,from,w);
        }
        memset(use,0,sizeof(use));
        ans=0;
        mm=n;
        solve(1);
        cout<<ans<<endl;
    }
    return 0;
}
