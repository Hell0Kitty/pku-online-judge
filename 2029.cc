#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

#define maxn 105

int n;
int map[maxn][maxn];
int row, col;
int sx, sy;
int f[maxn][maxn];

void input()
{
    memset(map, 0, sizeof(map));
    scanf("%d%d", &row, &col);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        map[a][b] = 1;
    }
    scanf("%d%d", &sx, &sy);
}

void work()
{
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= col; i++)
    {
        int temp = 0;
        for (int j = 1; j < sx; j++)
            temp += map[j][i];
        for (int j = sx; j <= row; j++)
        {
            temp -= map[j - sx][i];
            temp += map[j][i];
            f[j][i] = temp;
        }    
    }

    int ans = 0;
    for (int i = sx; i <= row; i++)
    {
        int temp = 0;
        for (int j = 1; j < sy; j++)
            temp += f[i][j];
        for (int j = sy; j <= col; j++)
        {
            temp -= f[i][j - sy];
            temp += f[i][j];
            ans = max(ans, temp);
        }    
    }
    printf("%d\n", ans);
}

int main()
{
    while (scanf("%d", &n), n)
    {
        input();
        work();
    }
    return 0;
}



