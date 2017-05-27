#include <stdio.h>
#include<string.h>
#define MAXN 200
int flag[MAXN][MAXN];
int c[MAXN][MAXN];
int lowbit(int i)
{
    return i & -i;
}
void update(int x, int y, int color)
{
    if (color == flag[x][y])
        return ;
    flag[x][y] = color;
    int i, j;
    for (i = x; i <= MAXN; i += lowbit(i))
        for (j = y; j <= MAXN; j+= lowbit(j))
            c[i][j] += color;
}

int getsum(int x, int y)
{
    int sum = 0, i, j;
    for (i = x; i > 0; i -= lowbit(i))
        for (j = y; j > 0; j -= lowbit(j))
            sum += c[i][j];
    return sum;
}

int main()
{
    int t, k, i, j, x, y, l;
    char s[10];

    scanf("%d", &t);
    memset(c, 0, sizeof(c));
    memset(flag, -1, sizeof(flag));
    for (k = 1; k <= t; k++)
    {
        scanf("%s%d%d%d", &s, &x, &y, &l);
        if (s[0] =='B')
        {
            for (i = x; i <= x+l-1; i++)
                for (j = y; j <= y+l-1; j++)
                    update(i, j, 1);
        }
        else if (s[0] == 'W')
        {
            for (i = x; i <= x+l-1; i++)
                for (j = y; j <= y+l-1; j++)
                    update(i, j ,-1);
        }
        else
            printf("%d\n", getsum(x+l-1, y+l-1) - getsum(x+l-1,y-1) - getsum(x-1, y+l-1) + getsum(x-1, y-1));
    }
    return 0;
}



