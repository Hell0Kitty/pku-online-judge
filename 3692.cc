#include <iostream>

using namespace std;

#define MAXN 205
#define _clr(x) memset(x,0xff,sizeof(int)*MAXN)

int map[MAXN][MAXN];
int match1[MAXN], match2[MAXN];

int hungary(int m, int n, int mat[][MAXN], int* match1, int* match2)
{
    int s[MAXN], t[MAXN], p, q, ret = 0, i, j, k;
    for (_clr(match1), _clr(match2), i = 1; i <= m; ret += (match1[i++] >= 0))
    for (_clr(t), s[p = q = 0] = i; p <= q&&match1[i] < 0; p++)
    for (k = s[p], j = 1; j <= n&&match1[i] < 0; j++)
    if (mat[k][j] && t[j] < 0)
    {
        s[++q] = match2[j], t[j] = k;
        if (s[q] < 0)
        for (p = j; p >= 0; j = p)
            match2[j] = k = t[j], p = match1[k], match1[k] = j;
    }
    return ret;
}

int main()
{
    int g, b, m;
    int countt = 1;
    while (cin >> g >> b >> m && (g || b || m))
    {
        memset(map, 1, sizeof(map));
        while (m--)
        {
            int a, b;
            cin >> a >> b;
            map[a][b] = 0;
        }
        cout << "Case " << countt++ << ": " << g + b - hungary(g, b, map, match1, match2) << endl;
    }
    return 0;
}



