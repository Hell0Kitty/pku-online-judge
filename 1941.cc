#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char st[2][15] =
{ " /\\ ", "/__\\" };
int n;

char cal(int x, int y, int r)
{
    if (r == 2)
        return st[y][x];
    if (x < r / 2 && y < r / 2)
        return ' ';
    if (x >= r / 2 + r && y < r / 2)
        return ' ';
    if (y < r / 2)
        return cal(x - r / 2, y, r / 2);
    if (x < r)
        return cal(x, y - r / 2, r / 2);
    return cal(x - r, y - r / 2, r / 2);
}

int main()
{
    while (scanf("%d", &n), n)
    {
        int m = 1 << n;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m + i + 1; j++)
                putchar(cal(j, i, m));
            putchar('\n');
        }
        putchar('\n');
    }
    return 0;
}


