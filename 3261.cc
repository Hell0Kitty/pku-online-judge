#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXD 20010
int N, K, r[MAXD], sa[MAXD], rank[MAXD], height[MAXD], wa[MAXD], wb[MAXD], ws[MAXD], wv[MAXD];
void init()
{
    int i, j, k;
    for(i = 0; i < N; i ++)
    {
        scanf("%d", &r[i]);
        ++ r[i];
    }
    r[N] = 0;
}
int cmp1(const void *_p, const void *_q)
{
    int *p = (int *)_p;
    int *q = (int *)_q;
    if(r[*p] == r[*q])
        return *p - *q;
    else
        return r[*p] - r[*q];
}
int cmp2(const void *_p, const void *_q)
{
    int *p = (int *)_p;
    int *q = (int *)_q;
    if(wv[*p] == wv[*q])
        return *p - *q;
    else
        return wv[*p] - wv[*q];
}
int cmp(int *p ,int x, int y, int l)
{
    return p[x] == p[y] && p[x + l] == p[y + l];
}
void da(int n, int m)
{
    int i, j, p, *x = wa, *y = wb, *t;
    for(i = 0; i < n; i ++)
        ws[i] = i, x[i] = r[i];
    qsort(ws, n, sizeof(ws[0]), cmp1);
    for(i = 0; i < n; i ++)
        sa[i] = ws[i];
    for(p = 1, j = 1; p < n; j *= 2, m = p)
    {
        for(p = 0, i = n - j; i < n; i ++)
            y[p ++] = i;
        for(i = 0; i < n; i ++)
            if(sa[i] >= j)
                y[p ++] = sa[i] - j;
        for(i = 0; i < n; i ++)
            wv[i] = x[y[i]];
        if(m > 1000000)
        {
            for(i = 0; i < n; i ++)
                ws[i] = i;
            qsort(ws, n, sizeof(ws[0]), cmp2);
            for(i = 0; i < n; i ++)
                sa[i] = y[ws[i]];
        }
        else
        {
            for(i = 0; i < m; i ++)
                ws[i] = 0;
            for(i = 0; i < n; i ++)
                ++ ws[wv[i]];
            for(i = 0; i < m; i ++)
                ws[i] += ws[i - 1];
            for(i = n - 1; i >= 0; i --)
                sa[-- ws[wv[i]]] = y[i];
        }
        for(t = x, x = y, y = t, x[sa[0]] = 0, p = 1, i = 0; i < n; i ++)
            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1: p ++;
    }
}
void calheight(int n)
{
    int i, j, k = 0;
    for(i = 1; i <= n; i ++)
        rank[sa[i]] = i;
    for(i = 0; i < n; height[rank[i ++]] = k)
        for(k ? -- k : 0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; k ++);
}
void solve()
{
    int i, j, k, cnt, ans, mid, min, max;
    da(N + 1, 1000002);
    calheight(N);
    min = 1, max = N;
    for(;;)
    {
        mid = (max + min) / 2;
        if(mid == min)
            break;
        ans = cnt = 0;
        for(i = 1; i <= N; i ++)
        {
            if(height[i] < mid)
            {
                if(cnt > ans)
                ans = cnt;
                cnt = 0;
            }
            else
            {
                if(!cnt)
                    cnt = 2;
                else
                    ++ cnt;
            }
        }
        if(cnt > ans)
            ans = cnt;
        if(ans >= K)
            min = mid;
        else
            max = mid;
    }
    printf("%d\n", mid);
}
int main()
{
    while(scanf("%d%d", &N, &K) == 2)
    {
        init();
        solve();
    }
    return 0;
}



