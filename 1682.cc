#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=105,inf=0x1f1f1f1f;
int dpa[N][N],dpb[N][N],dpc[N][N],x[N],y[N],z[N];
int getmin(int i,int j,int t)
{
    int ans=min(dpa[i][j]+dpb[i][t]+dpc[t][j],dpa[i][j]+dpb[i][t]+dpc[t][j-1]);
    ans=min(ans,min(dpa[i][j]+dpb[i][t]+dpc[t+1][j],dpa[i][j]+dpb[i][t]+dpc[t+1][j-1]));
    ans=min(ans,min(dpa[i][j]+dpb[i+1][t]+dpc[t+1][j],dpa[i][j]+dpb[i+1][t]+dpc[t+1][j-1]));
    return min(ans,min(dpa[i][j]+dpb[i+1][t]+dpc[t][j],dpa[i][j]+dpb[i+1][t]+dpc[t][j-1]));
}
int main()
{
    int T,n,m,k;
    for(scanf("%d",&T);T;T--)
    {
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=n;i++)
            scanf("%d",x+i);
        for(int i=1;i<=m;i++)
            scanf("%d",y+i);
        for(int i=1;i<=k;i++)
            scanf("%d",z+i);
        memset(dpa,0x1f,sizeof(dpa));
        memset(dpb,0x1f,sizeof(dpb));
        memset(dpc,0x1f,sizeof(dpc));
        dpa[0][k+1]=dpb[n+1][0]=dpc[m+1][0]=0;
        for(int i=1;i<=n;i++)
            for(int j=k;j>=1;j--)
            {
                int tp=inf,cc=0;
                for(int t=j;t<=k;t++)
                    cc+=abs(x[i]-z[t]),tp=min(tp,cc+min(dpa[i-1][t+1],dpa[i-1][t]));
                dpa[i][j]=tp;
            }
        for(int i=n;i>=1;i--)
            for(int j=1;j<=m;j++)
            {
                int tp=inf,cc=0;
                for(int t=j;t>=1;t--)
                    cc+=abs(x[i]-y[t]),tp=min(tp,cc+min(dpb[i+1][t],dpb[i+1][t-1]));
                dpb[i][j]=tp;
            }
        for(int i=m;i>=1;i--)
            for(int j=1;j<=k;j++)
            {
                int tp=inf,cc=0;
                for(int t=j;t>=1;t--)
                    cc+=abs(y[i]-z[t]),tp=min(tp,cc+min(dpc[i+1][t],dpc[i+1][t-1]));
                dpc[i][j]=tp;
            }
        int ans=inf;
        for(int i=0;i<=n+1;i++)
            for(int j=k+1;j>=0;j--)
                for(int t=0;t<=m+1;t++)
                    ans=min(ans,getmin(i,j,t));
        printf("%d\n",ans);
    }
    return 0;
}



