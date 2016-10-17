#include <stdio.h>
#include <string.h>

char G[20][20],g[20][20];

int dir[8][2] = {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
int n;

int main()
{
    int i,j,k,ca = 0;
    while(scanf("%d",&n) == 1)
    {
        if(ca)
            printf("\n");
        ca = 1;
        for(i=0; i<n; i++)
            scanf("%s",g[i]);

        for(i=0; i<n; i++)
            scanf("%s",G[i]);

       bool flag=false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(g[i][j]=='*' && G[i][j]=='x')
                flag=true;
                if(g[i][j]!='*' && G[i][j]=='x')
                {
                    int ans=0;
                    for(int k=0;k<8;k++)
                    {
                        int x=i+dir[k][0];
                        int y=j+dir[k][1];
                        if(x>=0&&x<n&&y>=0&&y<n)
                        {
                            if(g[x][y]=='*') ans++;
                        }
                    }
                    G[i][j]=ans+48;
                }
            }
        }
     if(flag)
        {
            for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                if(g[i][j]=='*')
                G[i][j]='*';
            }
        }
        for(int i=0;i<n;i++)
        printf("%s\n",G[i]);
    }
    return 0;
}


