#include<cstdio>
using namespace std;
#define M 37
#define MAX 900000000
int g[M][M];
int main()
{
    int T,n,i,j,u,v,p,m,k;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=n;j++)
            {
                g[i][j]=MAX;
            }
        }
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&u,&v);
            g[0][u]=v-1;
        }
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&p);
            g[u][v]=p;
        }

        for(i=1;i<n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                if(g[0][i]==g[0][j])  //At begine v[i]==v[j],but final v[i] may become smaller.
                {
                    g[i][j]=g[j][i]=0;
                }
            }
        }

        //最短路
        bool bbc;
        do
        {
            bbc=false;
            for(i=0;i<=n;i++)
            {
                for(j=0;j<=n;j++)
                {
                    for(k=0;k<=n;k++)
                    {
                        if(g[i][j]+g[j][k] < g[i][k])
                        {
                            g[i][k] = g[i][j] + g[j][k];
                            bbc=true;
                        }
                    }
                }
            }
        }while(bbc);

        for(i=1;i<=n;i++)
        {
            printf("%d %d\n",i,g[0][i]);
        }
        int ans=0;
        for(i=1;i<=n;i++)
        {
            bool bans=true;
            for(j=1;j<=n&&bans;j++)
            {
                for(k=1;k<=n&&bans;k++)
                {
                    if( i!=j && j!=k && i!=k && g[0][i] == g[0][j] + g[0][k])
                    {
                        ans++;
                        bans=false;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}



