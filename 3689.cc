#include<iostream>
#include <cmath>
#include <algorithm>
#include<vector>
using namespace std;

#define MAX_N 100000 * 2
typedef long long  LL;

inline int compare_to_zero(long double x)
{
    if (fabs(x) < 1e-12)return 0;
    return x < 0 ? -1 : 1;
}

struct Line
{
    LL a, b, c;
} 
ls[MAX_N], 
st[MAX_N]; 

long double ans[MAX_N];
bool impossible[MAX_N];

inline bool cmp(const Line &a, const Line &b)
{
    LL t = a.a*b.b - a.b*b.a;
    if (t != 0)return t > 0;
    t = a.c*b.b - a.b*b.c;
    return t > 0;
}
struct Point
{
    long double x, y;
};
int stack[MAX_N];
Point p[MAX_N];

inline Point intersection(const Line &la, const Line &lb)
{
    LL a = la.a, b = la.b, c = la.c;
    LL d = lb.a, e = lb.b, f = lb.c;
    LL der = a*e - b*d;
    Point ret;
    ret.x = c*e - b*f;
    ret.y = a*f - c*d;
    ret.x /= der;
    ret.y /= der;
    return ret;
}

inline bool is_point_fit_line(const Line &l, const Point &p)
{
    return compare_to_zero(l.a * p.x + l.b * p.y - l.c) >= 0;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d%d", &ls[i].a, &ls[i].b, &ls[i].c);
        }
        sort(ls, ls + n, cmp);
        int size = 1;
        for (int i = 1; i < n; i++)
        {
            if (ls[i].a* ls[i - 1].b == ls[i - 1].a* ls[i].b)  continue;  
            ls[size++] = ls[i];
        }
        n = size;
        LL S, T;
        if (n == 1)
        {
            while (m--)
            {
                scanf("%lld%lld", &S, &T);
                if (S* ls[0].b != T* ls[0].a)  puts("IMPOSSIBLE"); 
                else printf("%.5f\n", ls[0].c*S*1.0 / ls[0].a);
            }
        }
        else
        {

            stack[0] = 0; 
            p[0].x = 0;       
            p[0].y = ls[0].c / (double)ls[0].b;
            stack[1] = 1;
            p[1] = intersection(ls[0], ls[1]);  
            int stack_size = 2;
            int ls_index;
            for (ls_index = 2; ls_index < n; ls_index++)
            {
                while (stack_size > 1)
                {
                    int prev = stack[stack_size - 2];
                    int top = stack[stack_size - 1];
                    if (is_point_fit_line(ls[top], intersection(ls[ls_index], ls[prev]))) --stack_size;
                    else
                    {
                        break;
                    }
                }
                p[stack_size] = intersection(ls[ls_index], ls[stack[stack_size - 1]]);
                stack[stack_size++] = ls_index;
            }

            for (int i = 0; i < m; i++)
            {
                scanf("%d%d", &st[i].a, &st[i].b);
                st[i].c = i;  
                impossible[i] = false;
            }

            sort(st, st + m, cmp);
            int st_index;
            for (st_index = 0; st_index < m; st_index++)
            {
                if (st[st_index].a * ls[0].b > st[st_index].b * ls[0].a) impossible[st[st_index].c] = true;    
                else break;
            }
            int cur = 0;
            while (cur < stack_size && st_index < m)
            {
                ls_index = stack[stack_size - 1];
                if (st[st_index].a * ls[ls_index].b < st[st_index].b * ls[ls_index].a) 
                {
                    break;
                }

                while (cur < stack_size)
                {
                    ls_index = stack[cur];
                    LL det = st[st_index].a * ls[ls_index].b - st[st_index].b * ls[ls_index].a;    
                    if (det >= 0) 
                    {
                        ans[st[st_index].c] = st[st_index].a * p[cur].x + st[st_index].b * p[cur].y;
                        break;
                    }
                    else
                    {
                        cur++;
                        continue;
                    }
                }
                st_index++;
            }
            while (st_index < m)
            {
                impossible[st[st_index].c] = true;
                st_index++;
            }
            for (st_index = 0; st_index < m; st_index++)
            {
                if (impossible[st_index])
                {
                    puts("IMPOSSIBLE");
                }
                else
                {
                    printf("%.5f\n", ans[st_index]);
                }
            }
        }
    }
    return 0;
}



