#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 11000
struct node
{
    int num;
    node *next;
};
node *graph[MAXN],memo[2*MAXN];
int top=0,n;
int Q[MAXN],father[MAXN];
int dp[MAXN][3];
void add(int x,int y)
{
    node *p=&memo[top++];
    p->num=y; p->next=graph[x]; graph[x]=p;
    p=&memo[top++];
    p->num=x; p->next=graph[y]; graph[y]=p;
}

void solve()
{
    int left,right,u,v,i;
    Q[left=right=1]=1;
    father[1]=0;
    while(left<=right)
    {
        u=Q[left++];
        for(node *p=graph[u];p;p=p->next)
            if(p->num!=father[u])
                Q[++right]=p->num,father[p->num]=u;
    }
    int s1,s2,s0,MIN;
    for(i=right;i>0;i--)
    {
        s0=1; s1=s2=0; MIN=MAXN;
        u=Q[i];
        for(node *p=graph[u];p;p=p->next)
        if(p->num!=father[u])
        {
            v=p->num;
            s0+=min(dp[v][0],min(dp[v][1],dp[v][2]));
            s1+=min(dp[v][0],dp[v][2]);
            s2+=min(dp[v][0],dp[v][2]);
            MIN=min(MIN,dp[v][0]-dp[v][2]);
        }
        if(MIN>0) s2+=MIN;
        dp[u][0]=s0; dp[u][1]=s1; dp[u][2]=s2;
    }
    printf("%d\n",min(dp[1][0],dp[1][2]));
}

int main()
{
    memset(dp,0,sizeof(dp));
    memset(graph,0,sizeof(graph));
    int x,y;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        add(x,y);
    }
    solve();
    return 0;
}



