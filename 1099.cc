#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define N 100
char square[N][N];

//初始化框架
void init(int n, int m)
{
    int i, j, k;
    for(i=0; i<=m; i++)
    {
        if(i % 4 == 0)
        {
            for(j=0, k=0; k < n; k++)
            {
                square[i][j++] = 'H';
                square[i][j++] = ' ';
                square[i][j++] = 'O';
                square[i][j++] = ' ';
            }
            square[i][j++] = 'H';
        }
        else if(i % 4 == 1 || i % 4 == 3)
        {
            for(j=0; j<4*n+1; j++)
            {
                square[i][j] = ' ';
            }
        }
        else
        {
            for(j=0; j<4*n+1; j++)
            {
                if(j % 4 == 2)
                {
                    square[i][j] = 'H';
                }
                else
                {
                    square[i][j] = ' ';
                }
            }
        }
    }

}
int main()
{
    int i, j, t; 
    int aasm[N][N], markh[N][N], marko[N][N];
    int n, m;

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    t = 0;
    while(scanf("%d", &n) && n)
    {
        memset(aasm, 0, sizeof(aasm));
        memset(marko, 0, sizeof(marko));
        memset(markh, 0, sizeof(markh));
        init(n, 4*n);
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                scanf("%d", &aasm[i][j]);
//把 1 和-1能确定的确定下来
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(aasm[i][j] == 1)
                {
                    markh[4*i][4*j] = 1;
                    square[4*i][1+4*j] = '-';
                    marko[4*i][2+4*j] = 2;
                    square[4*i][3+4*j] = '-';                    
                    markh[4*i][4+4*j] = 1;
                }
                else if(aasm[i][j] == -1)
                {
                    square[4*i-1][2+4*j] = '|';
                    square[4*i+1][2+4*j] = '|';
                    marko[4*i][2+4*j] = 2;
                    markh[4*i-2][2+4*j] = 1;
                    markh[4*i+2][2+4*j] = 1;
                }
            }
        }
//处理其他的
        for(i=0; i<4*(n-1)+1; i=i+4)
        {
            for(j=2; j<4*n+1; j=j+4)
            {

                if(square[i][j] == 'O' && marko[i][j] < 2)
                {   
                    if(markh[i][j-2] == 0)
                    {
                        square[i][j-1] = '-';
                        markh[i][j-2] = 1;
                        if(i> 0 && markh[i-2][j] == 0)
                        {
                            square[i-1][j] = '|';
                            markh[i-2][j] = 1;
                        }
                        else if(i < 4*(n-1) && markh[i+2][j] == 0)
                        {
                            square [i+1][j] = '|';
                            markh[i+2][j] = 1;
                        }
                    }
                    else if(markh[i][j+2] == 0)
                    {
                        square[i][j+1] = '-';
                        markh[i][j+2] = 1;
                        if(i> 0 && markh[i-2][j] == 0)
                        {
                            square[i-1][j] = '|';
                            markh[i-2][j] = 1;
                        }
                        else if(i < 4*(n-1) && markh[i+2][j] == 0)
                        {
                            square[i+1][j] = '|';
                            markh[i+2][j] = 1;
                        }
                    }
                }

            }
        }
        t++;
        printf("Case %d:\n\n", t);
        for(j=1; j<=4*n+3; j++)
            printf("*");
        printf("\n");
        for(i=0; i<4*(n-1)+1; i++)
        {
            printf("*");
            for(j=0; j<4*n+1; j++)
                printf("%c", square[i][j]);
            printf("*\n");
        }
        for(j=1; j<=4*n+3; j++)
            printf("*");
        printf("\n\n");    
    }
    return 0;
}


