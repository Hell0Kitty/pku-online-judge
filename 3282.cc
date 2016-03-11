#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int main()
{
    int cas, lcnt, rcnt, on,n,m,l;
    char s[10];
    scanf ("%d", &cas);
    while (cas--)
    {
        queue<int> le, ri;
        scanf ("%d%d", &n, &m);
        n *= 100;
        while (m--)
        {
            scanf ("%d%s", &l, s);
            if (s[0] == 'l') le.push (l);
            else ri.push (l);
        }
        lcnt = on = 0;
        while (!le.empty())
        {
            while (!le.empty() && on + le.front() < n)
                on += le.front(), le.pop();
            ++lcnt, on = 0;
        }
        rcnt = on = 0;
        while (!ri.empty())
        {
            while (!ri.empty() && on + ri.front() < n)
                on += ri.front(), ri.pop();
            ++rcnt, on = 0;
        }
        if (lcnt > rcnt) printf ("%d\n", 2 * lcnt - 1);
        else printf ("%d\n",2 * rcnt);
    }
    return 0;
}




