#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxn 30

struct Matrix
{
    int x, y;
} matrix[maxn];

int n, ans;
bool error;

void input()
{
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        char ch = getchar();
        int a, b;
        scanf("%d%d", &a, &b);
        int c = ch - 'A';
        matrix[c].x = a;
        matrix[c].y = b;
        getchar();
    }
}

Matrix cal(char *st, char * &end)
{
    char *p;
    Matrix a, b, ret;
    if (st[0] != '(')
    {
        end = st + 1;
        return matrix[st[0] - 'A'];
    }
    a = cal(st + 1, p);
    b = cal(p, p);
    end = p + 1;
    if (a.y != b.x)
        error = true;
    ans += a.x * b.x * b.y;
    ret.x = a.x;
    ret.y = b.y;
    return ret;
}

int main()
{
    input();
    char st[maxn * 100], *p;
    while (scanf("%s", st) != EOF)
    {
        ans = 0;
        error = false;
        cal(st, p);
        if (error)
            puts("error");
        else
            printf("%d\n", ans);
    }
    return 0;
}


