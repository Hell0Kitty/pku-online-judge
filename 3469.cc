#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define N 20005
#define M 500005
#define typec int
const typec inf = 0x3f3f3f3f;

struct edge
{
    int x, y, nxt;
    typec c;
} bf[M];
int ne, head[N], cur[N], ps[N], dep[N];

void addedge(int x, int y, typec c)
{
    bf[ne].x = x;
    bf[ne].y = y;
    bf[ne].c = c;
    bf[ne].nxt = head[x];
    head[x] = ne++;
    bf[ne].x = y;
    bf[ne].y = x;
    bf[ne].c = 0;
    bf[ne].nxt = head[y];
    head[y] = ne++;
}
void addedge1(int x, int y, typec c)
{
    bf[ne].x = x;
    bf[ne].y = y;
    bf[ne].c = c;
    bf[ne].nxt = head[x];
    head[x] = ne++;
    bf[ne].x = y;
    bf[ne].y = x;
    bf[ne].c = c;
    bf[ne].nxt = head[y];
    head[y] = ne++;
}

typec flow(int n, int s, int t)
{
    typec tr, res = 0;
    int i, j, k, f, r, top;
    while (1)
    {
        memset(dep, -1, n * sizeof(int));
        for (f = dep[ps[0] = s] = 0, r = 1; f != r;)
        {
            for (i = ps[f++], j = head[i]; j; j = bf[j].nxt)
            {
                if (bf[j].c && -1 == dep[k = bf[j].y])
                {
                    dep[k] = dep[i] + 1;
                    ps[r++] = k;
                    if (k == t)
                    {
                        f = r;
                        break;
                    }
                }
            }
        }
        if (-1 == dep[t])
            break;

        memcpy(cur, head, n * sizeof(int));
        for (i = s, top = 0;;)
        {
            if (i == t)
            {
                for (k = 0, tr = inf; k < top; ++k)
                    if (bf[ps[k]].c < tr)
                        tr = bf[ps[f = k]].c;
                for (k = 0; k < top; ++k)
                    bf[ps[k]].c -= tr, bf[ps[k] ^ 1].c += tr;
                res += tr;
                i = bf[ps[top = f]].x;
            }
            for (j = cur[i]; cur[i]; j = cur[i] = bf[cur[i]].nxt)
                if (bf[j].c && dep[i] + 1 == dep[bf[j].y])
                    break;
            if (cur[i])
            {
                ps[top++] = cur[i];
                i = bf[cur[i]].y;
            }
            else
            {
                if (0 == top)
                    break;
                dep[i] = -1;
                i = bf[ps[--top]].x;
            }
        }
    }
    return res;
}
int main()
{
    //freopen("D:\\t.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    ne = 2;
    memset(head, 0, sizeof(head));
    n += 2;
    int s = 0;
    int t = 1;
    for (int i = 2; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        addedge(s, i, a);
        addedge(i, t, b);
    }
    for (int i = 0; i < m; i++)
    {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        addedge1(x + 1, y + 1, c);
    }
    printf("%d\n", flow(n, s, t));
    return 0;
}



