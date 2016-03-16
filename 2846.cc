#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef struct node
{
    int y,m,d;
} node;

node fir,sec;

int cnt[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int is (int y)
{
    return (!(y%400) || (!(y%4) && (y%100)));
}

node pre (const node a)
{
    node e;
    e.y = a.y;
    e.m =a.m;
    e.d = a.d;
    if (e.d == 1)
    {
        e.m--;
        if (e.m == 0)
        {
            e.m = 12;
            e.y--;
            e.d = cnt[e.m];
        }
        if (e.m == 2)
        {
            e.d = cnt[2] + is (e.y);
        }
        else
        {
            e.d = cnt[e.m];
        }
    }
    else
        e.d--;
    return e;
}

node next (const node & a)
{
    node e;
    e.y = a.y;
    e.m = a.m;
    e.d = a.d;
    if (e.m == 2 && (e.d+1 > cnt[2] + is(e.y)))
    {
        e.m =3;
        e.d = 1;
    }
    else if  (e.d+1 > cnt[e.m])
    {
        e.m++;
        e.d = 1;
        if (e.m == 13)
        {
            e.m = 1;
            e.y++;
        }
    }
    else
        e.d++;
    return e;
}

void print (const node & a)
{
    cout << a.y << " " << a.m << " " << a.d << endl;
}

int main()
{
    int t;
    int cas = 0;
    scanf("%d",&t);
    int y,m,d;
    while (cas++<t)
    {
        scanf("%d/%d/%d", &m,&d,&y);
        fir.y = y;
        fir.m = m;
        fir.d = d;
        scanf("%d/%d", &m,&d);
        sec.m = m;
        sec.d = d;
        int i;
        node cur = fir;
        if (cur.m == sec.m && cur.d == sec.d)
        {
            printf("%d SAME DAY\n",cas);
            continue;
        }

        int f = 0;
        for (i = 0; i < 7; i++)
        {
            cur = pre (cur);
            if (cur .m == sec.m  && cur.d == sec.d)
            {
                if (i)
                {
                    printf("%d %d/%d/%d IS %d DAYS PRIOR\n",cas,cur.m,cur.d,cur.y,i+1);
                    f = 1;
                    break;
                }
                else
                {
                    printf("%d %d/%d/%d IS %d DAY PRIOR\n",cas,cur.m,cur.d,cur.y,i+1);
                    f = 1;
                    break;
                }
            }
        }
        cur = fir;
        for (i = 0; i < 7; i++)
        {
            cur = next (cur);
         //   print(cur);
            if (cur .m == sec.m  && cur.d == sec.d)
            {
                if (i)
                {
                    printf("%d %d/%d/%d IS %d DAYS AFTER\n",cas,cur.m,cur.d,cur.y,i+1);
                    f = 1;
                    break;
                }
                else
                {
                    printf("%d %d/%d/%d IS %d DAY AFTER\n",cas,cur.m,cur.d,cur.y,i+1);
                    f = 1;
                    break;
                }
            }
        }
        if (!f)
        {
            printf("%d OUT OF RANGE\n",cas);
        }
    }
    return 0;
}



