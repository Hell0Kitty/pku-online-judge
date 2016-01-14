#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
double dp[102][42][42];
struct _cow
{
    int num;
    double x[42],y[42];
} cow[102];
inline double getdist(int i,int ii,int j,int jj)
{
    double x1=cow[i].x[ii],y1=cow[i].y[ii];
    double x2=cow[j].x[jj],y2=cow[j].y[jj];
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1; i<=n; i++)
        {
            int num;
            scanf("%d",&num);
            cow[i].num=num;
            for(int j=0; j<num; j++)
                scanf("%lf%lf",&cow[i].x[j],&cow[i].y[j]);
        }
        int cnt=cow[1].num,cc=cow[2].num;
        for(int i=0; i<cc; i++)
            for(int j=0; j<cnt; j++)
                dp[2][i][j]=getdist(1,j,2,i);
        for(int i=3; i<=n; i++)
        {
            int ln=cow[i-1].num,nn=cow[i].num;
            for(int j=0; j<nn; j++)
            {
                for(int k=0; k<cnt; k++)
                {
                    dp[i][j][k]=1e50;
                    for(int t=0; t<ln; t++)
                    {
                        dp[i][j][k]=min(dp[i][j][k],dp[i-1][t][k]+getdist(i-1,t,i,j));
                    }
                }
            }
        }
        double ans=1e50;
        int num=cow[n].num;
        for(int i=0; i<cnt; i++)
        {
            for(int j=0; j<num; j++)
                ans=min(ans,dp[n][j][i]+getdist(n,j,1,i));
        }
        printf("%d\n",(int)floor(ans*100.0));
    }
    return 0;
}



