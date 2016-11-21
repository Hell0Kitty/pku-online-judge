#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 35
#define maxt 1005

int n, t, m;
double f[maxt][maxn];
double g[maxt][maxn][maxn];

int main()
{
    while (scanf("%d%d%d", &n, &t, &m), n | t | m)
    {
        double ans =1;
        for (int i =0; i < t; i++)
            for (int j =1; j <= n; j++)
                scanf("%lf", &f[i][j]);
        memset(g, 0, sizeof(g));
        for (int i =0; i < t; i++)
        {
            g[i][0][0] =1;
            for (int j =1; j <= n; j++)
            {
                g[i][j][0] = g[i][j -1][0] * (1- f[i][j]);
                for (int k =1; k <= j; k++)
                    g[i][j][k] = g[i][j -1][k -1] * (f[i][j])
                            + g[i][j -1][k] * (1- f[i][j]);
            }
        }
        for (int i =0; i < t; i++)
            ans *=1- g[i][n][0];
        double temp =1;
        for (int i =0; i < t; i++)
        {
            double sum =0;
            for (int j =1; j < m; j++)
                sum += g[i][n][j];
            temp *= sum;
        }
        ans -= temp;
        printf("%.3f\n", ans);
    }
    return 0;
}



