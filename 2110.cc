#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
bool mark[105][105];
int map[105][105];
int n;
bool dfs(int x,int y,int mmin,int len)
{
    mark[x][y]=true;
    if(x==n&&y==n)
        return true;
    bool flag=false;
    if(x<n&&!mark[x+1][y]&&map[x+1][y]<=mmin+len&&map[x+1][y]>=mmin)
        flag|=dfs(x+1,y,mmin,len);
    if(x>1&&!mark[x-1][y]&&map[x-1][y]<=mmin+len&&map[x-1][y]>=mmin)
        flag|=dfs(x-1,y,mmin,len);
    if(y>1&&!mark[x][y-1]&&map[x][y-1]<=mmin+len&&map[x][y-1]>=mmin)
        flag|=dfs(x,y-1,mmin,len);
    if(y<n&&!mark[x][y+1]&&map[x][y+1]<=mmin+len&&map[x][y+1]>=mmin)
        flag|=dfs(x,y+1,mmin,len);
    return flag;
}
bool solve(int mid)
{
    int t=map[1][1];
    for(int i=max(t-mid,0);i<=t;i++)
    {
        memset(mark,false,sizeof(mark));
        if(dfs(1,1,i,mid))
            return true;
    }
    return false;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&map[i][j]);
        int ans=0,ll,rr,mid;
        for(ll=0,rr=110;ll<=rr;)
        {
            mid=(ll+rr)>>1;
            if(solve(mid))
            {
                ans=mid;
                rr=mid-1;
            }
            else
            {
                ll=mid+1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}


