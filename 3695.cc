#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#define MAXN 111111
#define MAXM 555555
#define INF 100000011
#define lch(x) x<<1
#define rch(x) x<<1|1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define eps 1e-7
using namespace std;
int ask[MAXN];
int st[1111111];
struct Rec
{
    int x1, x2, y1, y2;
}p[22];
int n, m;
void dfs(int xa, int ya, int xb, int yb, int deep, int flag, int sta)
{
    if(xa >= xb || ya >= yb) return;
    if(deep == n)
    {
        if(sta)
        {
            for(int i = 1; i <= m; i++)
                if((ask[i] | sta) == ask[i])
                    st[ask[i]] += flag * (xb - xa) * (yb - ya);
        }
        return;
    }
    dfs(xa, ya, xb, yb, deep + 1, flag, sta);
    dfs(max(xa, p[deep + 1].x1), max(ya, p[deep + 1].y1), min(xb, p[deep + 1].x2), min(yb, p[deep + 1].y2), deep + 1, -flag, sta |(1 << deep));
}
int in()
{
    char ch;
    int a = 0;
    while((ch = getchar()) == ' ' || ch == '\n');
    a += ch - '0';
    while((ch = getchar()) != ' ' && ch != '\n')
    {
        a *= 10;
        a += ch - '0';
    }
    return a;
}
int main()
{
    int cas = 0;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        if(!n && !m) break;
        memset(st, 0, sizeof(st));
        memset(ask, 0, sizeof(ask));
        for(int i = 1; i <= n; i++) scanf("%d%d%d%d", &p[i].x1, &p[i].y1, &p[i].x2, &p[i].y2);
        int t, x;
        for(int i = 1; i <= m; i++)
        {
            t = in();
            while(t--)
            {
                x = in();
                ask[i] |= (1 << (x - 1));
            }
        }
        dfs(0, 0, INF, INF, 0, -1, 0);
        printf("Case %d:\n", ++cas);
        for(int i = 1; i <= m; i++)
            printf("Query %d: %d\n", i, st[ask[i]]);
        printf("\n");
    }
    return 0;
}


