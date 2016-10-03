#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 105
#define maxq 10005

int n, ans[maxn][maxn];
int len[maxn];
int seq[maxn];
int d;

void dfs(int a)
{
    if (a > d)
        return;
    for (int i = 0; i < a; i++)
        for (int j = i; j < a; j++)
        {
            seq[a] = seq[i] + seq[j];
            if (seq[a] > 100 || seq[a] <= seq[a - 1])
                continue;
            if (len[seq[a]] == -1 || len[seq[a]] > a + 1)
            {
                len[seq[a]] = a + 1;
                for (int k = 0; k <= a; k++)
                    ans[seq[a]][k] = seq[k];
            }
            dfs(a + 1);
        }
}

int main()
{
    memset(ans, 0, sizeof(ans));
    memset(len, -1, sizeof(len));
    seq[0] = 1;
    seq[1] = 2;
    len[1] = 1;
    len[2] = 2;
    ans[1][0] = 1;
    ans[2][0] = 1;
    ans[2][1] = 2;
    for (d = 2; d < 10; d++)
        dfs(2);
    while (scanf("%d", &n), n != 0)
    {
        for (int i = 0; i < len[n] - 1; i++)
            printf("%d ", ans[n][i]);
        printf("%d\n", ans[n][len[n] - 1]);
    }
    return 0;
}



