#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAXD 210
struct Point
{
    int x, y;
    bool operator < (const Point &t) const
    {
        if(x == t.x) return y < t.y;
        return x < t.x;
    }
}p[MAXD];
struct Vector
{
    int x, y;
    bool operator < (const Vector &t) const
    {
        return y * t.x < x * t.y;
    }
    bool operator != (const Vector &t) const
    {
        return y * t.x != x * t.y;
    }
}a[MAXD * MAXD];
int N;
void init()
{
    int i;
    for(i = 0; i < N; i ++) scanf("%d%d", &p[i].x, &p[i].y);
}
void solve()
{
    int i, j, n = 0, cnt;
    std::sort(p, p + N);
    for(i = 0; i < N; i ++)
        for(j = i + 1; j < N; j ++)
            a[n].x = p[j].x - p[i].x, a[n].y = p[j].y - p[i].y, ++ n;
    std::sort(a, a + n);
    for(i = cnt = 1; i < n; i ++)
        if(a[i] != a[i - 1]) ++ cnt;
    printf("%d\n", cnt);
}
int main()
{
    while(scanf("%d", &N) == 1)
    {
        init();
        solve();
    }
    return 0;
}



