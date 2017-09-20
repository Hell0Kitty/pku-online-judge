#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 105

int n, m;
int f[maxn][maxn];
int last_equal1[maxn][maxn], last_equal2[maxn][maxn];
int chain1[maxn], chain2[maxn];

void input()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &chain1[i]);
    for (int i = 1; i <= m; i++)
        scanf("%d", &chain2[i]);
}

void make(int n, int chain[], int last_equal[][maxn])
{
    memset(last_equal, 0, sizeof(last_equal));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 100; j++)
            if (chain[i] == j)
                last_equal[i][j] = i;
            else
                last_equal[i][j] = last_equal[i - 1][j];
}

int work()
{
    make(n, chain1, last_equal1);
    make(m, chain2, last_equal2);
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            int a = chain1[i];
            int b = chain2[j];
            int pos1 = last_equal1[i][b];
            int pos2 = last_equal2[j][a];
            if (a != b && pos1 != 0 && pos2 != 0)
                f[i][j] = max(f[i][j], f[pos1 - 1][pos2 - 1] + 1);
        }
    return f[n][m] * 2;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        input();
        printf("%d\n", work());
    }
    return 0;
}



