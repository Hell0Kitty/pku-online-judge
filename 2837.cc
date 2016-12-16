#include <stdio.h>
int a[12][600][600];
int main()
{
    a[1][1][1]=1;
    a[1][2][2]=1;
    a[1][1][2]=2;
    a[1][2][1]=3;
    int add=2;
    for (int ii=2;ii<=9;ii++)
    {
        add*=2;
        int maxx=(1<<(ii-1));
        for (int i=1;i<=maxx;i++)
            for (int j=1;j<=maxx;j++)
            {
                a[ii][i][j]=a[ii-1][i][j];
                a[ii][i+maxx][j+maxx]=a[ii-1][i][j];
                a[ii][i+maxx][j]=a[ii-1][i][j]+add;
                a[ii][i][j+maxx]=a[ii-1][i][j]+add;
            }
        for (int i=1;i<=maxx;i++)
            a[ii][i+maxx][i]--;
    }
    int k;
    while (scanf("%d",&k)==1)
    {
        int maxx=(1<<k);
        for (int i=1;i<=maxx;i++)
        {
            for (int j=1;j<maxx;j++)
                printf("%d ",a[k][i][j]);
            printf("%d\n",a[k][i][maxx]);
        }
    }
    return 0;
}


