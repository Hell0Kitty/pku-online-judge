#include <stdio.h>
#include <string.h>
#define M 305
int w,l;
char meg[M],word[605][M];

int min (int a,int b)
{
    return a > b ? b : a;
}
void DP ()
{
    int dp[M];
    int i,j,pm,pw;
    dp[l] = 0;
    for (i = l-1; i >= 0; i --)
    {
        dp[i] = dp[i+1] +  1;
        for (j = 0; j < w; j ++)
        {
            int len = strlen (word[j]);
            if (word[j][0] == meg[i] && l - i >= len)
            {
                pm = i;
                pw = 0;
                while (pm < l)
                {
                    if (word[j][pw] == meg[pm++])
                        pw ++;
                    if (pw == len)
                    {
                        dp[i] = min (dp[i],dp[pm] + (pm-i-len));
                        break;
                    }
                }
            }
        }
    }
    printf ("%d\n",dp[0]);
}
int main ()
{
    while (~scanf ("%d%d",&w,&l))
    {
        getchar ();
        gets (meg);
        for (int i = 0; i < w; i ++)
            gets (word[i]);
        DP();
    }
    return 0;
}
