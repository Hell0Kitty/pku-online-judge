
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct node
{
    int val,pos;
}em[110][110];
bool cmp(node a,node b)
{
    return a.val>b.val;
}
int dp[2][6][6][6][6];
int T,t,n,m,g,fight[300],vis[110],num[10],from,to,day,ans;
void dfs(int pos)
{
    if(pos==-1)
    {
        dp[to][num[1]][num[2]][num[3]][num[4]]=max(dp[to][num[1]][num[2]][num[3]][num[4]],
                    dp[from][num[0]][num[1]][num[2]][num[3]]+em[fight[day]][num[4]].val);
        return;
    }
    for(num[4-pos]=1;num[4-pos]<=5;num[4-pos]++)
    {
        if(vis[em[fight[day-pos]][num[4-pos]].pos]>0)
          continue;
        vis[em[fight[day-pos]][num[4-pos]].pos]++;
        dfs(pos-1);
        vis[em[fight[day-pos]][num[4-pos]].pos]--;
    }
}
int main()
{
    int i,j,k,a,b,c,d;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d%d%d",&n,&m,&g);
        memset(em,0,sizeof(em));
        memset(fight,0,sizeof(fight));
        for(i=1;i<=m;i++)
           for(j=1;j<=n;j++)
           {
               scanf("%d",&em[i][j]);
               em[i][j].pos=j;
           }
        for(i=1;i<=m;i++)
           sort(em[i]+1,em[i]+1+n,cmp);
        n=min(n,5);
        for(i=11;i<=g+20;i++)
           scanf("%d",&fight[i]);
        memset(dp,0,sizeof(dp));
        vis[0]=-100;

        for(day=11;day<=g+20;day++)
        {
            if(day&1)
              from=0;
            else
              from=1;
            to=1^from;
            memset(dp[to],0,sizeof(dp[to]));
            dfs(4);
        }
        ans=0;
        for(a=0;a<=5;a++)
           for(b=0;b<=5;b++)
              for(c=0;c<=5;c++)
                 for(d=0;d<=5;d++)
                    ans=max(ans,dp[to][a][b][c][d]);
        printf("%.2f\n",0.01*ans);
    }
}
