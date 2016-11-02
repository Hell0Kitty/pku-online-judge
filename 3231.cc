#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 105

struct Elem
{
    double size, speed, max_speed;
} elem[maxn];

int n, m;
double time_left[maxn];
bool finished[maxn];
double ans[maxn];
double reached[maxn];
int task_left;

void input()
{
    scanf("%d", &m);
    for (int i = 0; i < n; i++)
        scanf("%lf%lf%lf", &elem[i].size, &elem[i].speed, &elem[i].max_speed);
}

void cal_time()
{
    for (int i = 0; i < n; i++)
        if (!finished[i])
            time_left[i] = elem[i].size / elem[i].speed;
}

void size_reduce(double min_time)
{
    for (int i = 0; i < n; i++)
        if (!finished[i])
            elem[i].size -= min_time * elem[i].speed;
}

int get_min()
{
    int ret = 0;
    while (finished[ret])
        ret++;
    for (int i = ret + 1; i < n; i++)
        if (!finished[i] && time_left[i] < time_left[ret])
            ret = i;
    return ret;
}

void distribute(double bandwidth)
{
    double band_left = bandwidth;
    int num = 0;
    for (int i = 0; i < n; i++)
        if (!finished[i] && !reached[i])
            num++;
    if (num == 0)
        return;
    double average;
    while (band_left > 0)
    {
        average = band_left / num;
        bool did = false;
        for (int i = 0; i < n; i++)
        {
            if (finished[i] || reached[i])
                continue;
            did = true;
            if (elem[i].max_speed - elem[i].speed < average)
            {
                band_left -= elem[i].max_speed - elem[i].speed;
                elem[i].speed = elem[i].max_speed;
                reached[i] = true;
                num--;
            }else
            {
                band_left -= average;
                elem[i].speed += average;
            }
        }
        if (!did)
            break;
    }
}

void work()
{
    memset(finished, 0, sizeof(finished));
    memset(reached, 0, sizeof(reached));
    double now_time = 0;
    task_left = n;
    while (task_left > 0)
    {
        cal_time();
        int next_task = get_min();
        finished[next_task] = true;
        task_left--;
        double bandwidth = elem[next_task].speed;
        double min_time = time_left[next_task];
        size_reduce(min_time);
        now_time += min_time;
        ans[next_task] = now_time;
        distribute(bandwidth);
    }
}

int main()
{
    int t = 0;
    while (scanf("%d", &n), n)
    {
        t++;
        printf("Case %d:\n", t);
        input();
        work();
        for (int i = 0; i < n; i++)
            printf("NO%d:%.3fs\n", i + 1, ans[i]);
    }
    return 0;
}



