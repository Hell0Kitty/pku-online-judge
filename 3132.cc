#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

#define maxn 1200
#define maxr 20

bool is[maxn];
int prm[maxn];
int n, r, tot;
int f[maxr][maxn][maxn];
int w[maxn];

int getprm(int n)
{
    int i, j, k = 0;
    int s, e = (int) (sqrt(0.0 + n) + 1);
    memset(is, 1, sizeof(is));
    prm[k++] = 2;
    is[0] = is[1] = 0;
    for (i = 4; i < n; i += 2)
        is[i] = 0;
    for (i = 3; i < e; i += 2)
        if (is[i])
        {
            prm[k++] = i;
            for (s = i * 2, j = i * i; j < n; j += s)
                is[j] = 0;
        }
    for (; i < n; i += 2)
        if (is[i])
            prm[k++] = i;
    return k;
}

int work()
{
    int i = 0;
    while (i < tot && prm[i] <= n)
        i++;
    int m = i;
    memset(w, 0, sizeof(w));
    for (int i = 0; i < m; i++)
        w[i + 1] = prm[i];
    for (int i = 0; i <= m; i++)
        f[0][i][0] = 1;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= m; j++)
            for (int k = 0; k <= n; k++)
            {
                f[i][j][k] = f[i][j - 1][k];
                if (k - w[j] >= 0)
                    f[i][j][k] +=  f[i - 1][j - 1][k - w[j]];
            }
    }
    return f[r][m][n];
}

int main()
{
    tot = getprm(1120);
    while (scanf("%d%d", &n, &r), n | r)
        printf("%d\n", work());
    return 0;
}



