#include<stdio.h>
#include<stdlib.h>
int d[103][103][103][2];
int main(void)
{
    int i,j,u,v,p,q,m,n,maxp;
    while(scanf("%d%d",&n,&m)==2)
    {
        d[0][0][0][0]=d[0][0][0][1]=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=i;j++)
            {
                p=i-j;
                for(u=0;u<=p;u++)
                {
                    q=i-j-u;
                    maxp=0;
                    for(v=1;v<=m;v++)
                    {
                        if(v>j)
                        {
                            break;
                        }
                        else if(v==j)
                        {
                            if(i-d[i-u-v][i-u-v][0][1]>maxp)
                            {
                                maxp=i-d[i-u-v][i-u-v][0][1];
                            }
                        }
                        else
                        {
                            if(i-d[i][j-v][u+v][1]>maxp)
                            {
                                maxp=i-d[i][j-v][u+v][1];
                            }
                        }
                    }
                    d[i][j][u][0]=maxp;
                    maxp=0;
                    for(v=1;v<=m;v++)
                    {
                        if(v>j)
                        {
                            break;
                        }
                        else if(v==j)
                        {
                            if(i-d[i-q-v][i-q-v][0][0]>maxp)
                            {
                                maxp=i-d[i-q-v][i-q-v][0][0];
                            }
                        }
                        else
                        {
                            if(i-d[i][j-v][u][0]>maxp)
                            {
                                maxp=i-d[i][j-v][u][0];
                            }
                        }
                    }
                    d[i][j][u][1]=maxp;
                }
            }
        }
        printf("%d\n",d[n][n][0][0]);
    }
    return 0;
}


