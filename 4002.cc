#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;

struct node
{
    int time, num;
}cus[2504];

int n, m;
int t, s;

//计算时间
char month[13][5] = { "123", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov" ,"Dec"};
int find(char s[])
{
    int i;
    for(i = 1; i <= 12; i++)
        if(strcmp(s, month[i]) == 0) return i;
}
int run(int x)
{
    return x % 400 == 0 || x % 4 == 0 && x % 100 ;
}

int day[2][13] = { { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
                 , { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };

int solve(int x, int y, int z, int w)//x, y, z, w 年，月，日，时
{
    bool flag;
    int ret = 0;
    int i;
    for(i = 2000; i < x ; i++)
    {
        flag = run(i);
        ret += 365 * 24;
        if(flag) ret += 24;
    }
    flag = run(x);
    for(i = 1; i < y; i++)
        ret += day[flag][i] * 24;
    ret +=  (z - 1) * 24 + w;
    return ret;
}

struct DEQUE
{
    int pos, val;
}que[2504];

int main()
{
    int i, j;
    int x, y, z, w;
    char buf[5];
    while( ~scanf("%d%d", &n, &m))
    {
        if(!n && !m) break;
        for(i = 0; i < n; i++)
        {
            scanf("%s%d%d%d%d", buf, &z, &x, &w, &cus[i].num);
            cus[i].time = solve(x, find(buf), z, w);
        }
        scanf("%d%d", &t, &s);
        int tail = -1, head = 0;
        int k = 0;
        __int64 ans = 0;
        for(i = 0; i < m; i++)
        {
            scanf("%d", &x);
            while(head <= tail && que[tail].val + (i - que[tail].pos ) * s >= x)
                tail--;
            que[++tail].pos = i;
            que[tail].val = x;

            while(k < n && cus[k].time == i)
            {
                while(head <= tail && i - que[head].pos > t) head++;
                ans += ( que[head].val  + (i - que[head].pos) * s )* cus[k].num;
                k++;
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}


