#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int cos[50][50],dp[2][33][33][33];
struct data
{
    int x,y,z;
    data() {}
    data(int _x,int _y,int _z)
    {
        x=_x;
        y=_y;
        z=_z;
    }
}Q[200000];
int main()
{
    int T;
    for(scanf("%d",&T); T; T--)
    {
        int n;
        scanf("%d",&n);
        memset(cos,-1,sizeof(cos));
        for(int i=1; i<n; i++)
        {
            cos[i][i]=0;
            for(int j=i+1; j<=n; j++)
            {
                scanf("%d",&cos[i][j]);
                cos[j][i]=cos[i][j];
            }
        }
        cos[n][n]=0;
        memset(dp,-1,sizeof(dp));
        dp[0][1][1][1]=0;
        int st,ed;
        st=ed=0;
        Q[ed++]=data(1,1,1);
        for(int t=2; t<=n; t++)
        {
            int x=t&1,y=x^1;
            int i=ed;
            while(st!=i)
            {
                data a=Q[st++];
                if(st==200000)
                    st=0;
                int tp=dp[x][a.x][a.y][a.z];
                int fp=dp[y][t][a.y][a.z];
                if(fp==-1||fp>tp+cos[a.x][t])
                {
                    dp[y][t][a.y][a.z]=tp+cos[a.x][t];
                    if(fp==-1)
                    {
                        Q[ed++]=data(t,a.y,a.z);
                        if(ed==200000)
                            ed=0;
                    }
                }
                fp=dp[y][a.x][t][a.z];
                if(fp==-1||fp>tp+cos[a.y][t])
                {
                    dp[y][a.x][t][a.z]=tp+cos[a.y][t];
                    if(fp==-1)
                    {
                        Q[ed++]=data(a.x,t,a.z);
                        if(ed==200000)
                            ed=0;
                    }
                }
                fp=dp[y][a.x][a.y][t];
                if(fp==-1||fp>tp+cos[a.z][t])
                {
                    dp[y][a.x][a.y][t]=tp+cos[a.z][t];
                    if(fp==-1)
                    {
                        Q[ed++]=data(a.x,a.y,t);
                        if(ed==200000)
                            ed=0;
                    }
                }
            }
            memset(dp[x],-1,sizeof(dp[x]));
        }
        int ans=1<<30,t=(n+1)&1;
        while(st!=ed)
        {
            data tmp=Q[st++];
            if(st==200000)
                st=0;
            ans=min(ans,dp[t][tmp.x][tmp.y][tmp.z]);
        }
        printf("%d\n",ans);
    }
    return 0;
}




