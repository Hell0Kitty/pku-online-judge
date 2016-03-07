#include <stdio.h>
#include <cstring>
#define max(a,b) ((a)>(b)?(a):(b))

int n, x, k, queue[5010], add; char elio[5010];

int vali (int person)
{
    int i, j, kase, tail, t;
    memset(elio, 0, sizeof(elio));
    //可以认为：elio[i]=j 表示i最后一次胜利是在倒数第j轮
    elio[person] = 1; tail = person;
    add = 0; queue[add++] = person;
    //总共x轮 （这里kase=i实际上表示倒数第i轮比赛）
    for (kase = 1; kase <= x; kase++)    
    {
        t = add;
        for (i = 0; i < t; i++)      
        {
            for (j = max(1, queue[i] - k); j <= tail; j++)
            {
                if (elio[j] == 0)
                {
                   elio[j] = kase + 1; 
                   queue[add++] = j;   //放入数组，因为下一轮循环（即上一轮比赛）需要为其分配对手
                   break;
                }
            }
        }
    }
    for (i = 1; i <= tail; i++)
        if (elio[i] == 0) return 0;   //之前还有人没分配到，即没有合法方案
    return 1;
}

int main ()
{
    int st, ed, mid, i;
    scanf("%d %d", &n, &k);
    for (x = 0, i = 1; i < n; x++, i *= 2);
    st = 1, ed = n;
    if (vali(ed)) st = ed;
    else while (ed - st > 1)    //二分
    {
         mid = (st + ed) >> 1;
         if (vali(mid)) st = mid;
         else ed = mid;
    }
    printf("%d\n", st);
    return 0;
}



