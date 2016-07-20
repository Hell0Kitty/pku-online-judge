#include <cstdio>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Point
{
    int x, y;
    Point() {}
    Point(int _x, int _y) : x(_x), y(_y) {}
    inline Point operator + (const Point &o)
    {
        return Point(x + o.x, y + o.y);
    }
    inline Point operator - (const Point &o)
    {
        return Point(x - o.x, y - o.y);
    }
    inline int operator * (const Point &o)
    {
        return x * o.y - y * o.x;
    }
    inline void input()
    {
        scanf("%d%d", &x, &y);
    }
    inline int norm()
    {
        return x * x + y * y;
    }
};
const int MAXN = 107;
int n;
Point src[MAXN];
Point dat[MAXN]; 

inline bool sort_cmp(Point a, Point b)
{
    return a * b > 0 || a * b == 0 && a.norm() < b.norm();
}
int f[MAXN][MAXN];

int Scan(int n)
{
    int result = 0;
    memset(f, 0, sizeof(f));
    for (int i = 1; i < n; i ++)
    {
        int j = i - 1;
        while (j >= 0 && dat[i] * dat[j] == 0) j --;
        bool flag = j == i - 1; 
        while (j >= 0)
        {
            int k = j - 1;
            while (k >= 0 && (dat[j] - dat[i]) * (dat[k] - dat[j]) > 0) k --;
            int area = dat[j] * dat[i];
            if (k >= 0) area += f[j][k];
            if (flag) f[i][j] = area;
            result = max(result, area);
            j = k;
        }

        if (flag)
            for (int j = 1; j < i; j ++)
                f[i][j] = max(f[i][j], f[i][j - 1]);
    }
    return result;
}
int Solve()
{
    int result = 0;
    for (int i = 0; i < n; i ++)
    {

        int m = 0;

        for (int j = 0; j < n; j ++)
            if (src[j].y > src[i].y || (src[j].y == src[i].y && src[j].x > src[i].x))
                dat[m ++] = src[j] - src[i];
        sort(dat, dat + m, sort_cmp);
        result = max(result, Scan(m));
    }
    return result;
}
int main()
{
    int T;
    scanf("%d", &T);
    cout << fixed << setprecision(1);
    while (T --)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i ++) src[i].input();

        double ans = (double) Solve() / 2.;
        cout << ans << endl;
    }
    return 0;
}



