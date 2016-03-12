#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <math.h>  
  
#define nMax 1050  
#define inf 0x7fffffff  
static double eps = 1e-4;  
int vis[nMax],x[nMax],y[nMax],z[nMax],pre[nMax];  
double dis[nMax],cost[nMax][nMax],dist[nMax][nMax];  
int n;  
double prim(double x)//普利姆算法求最小生成树  
{  
    double totalcost = 0, totaldist = 0;  
    double sum = 0.0;  
    for (int i = 1; i <= n; ++ i)  
    {  
        pre[i] = 1;  
    }  
    dis[1] = 0;  
    memset(vis, 0, sizeof(vis));  
    vis[1] = 1;  
    for (int i = 2; i <= n; ++ i)  
    {  
        dis[i] = cost[1][i] - dist[1][i] * x;  
    }  
    int k;  
    for (int i = 2; i <= n; ++ i)  
    {  
        double minCost = inf;  
        for (int j = 2; j <= n; ++ j)  
        {  
            if (!vis[j] && dis[j] < minCost)  
            {  
                minCost = dis[j];  
                k = j;  
            }  
        }  
        vis[k] = 1;  
        sum += minCost;//for 二分  
        totalcost += cost[pre[k]][k];  
        totaldist += dist[pre[k]][k];  
        for (int j = 1; j <= n; ++ j)  
        {  
            if (!vis[j] && dis[j] > cost[k][j] - dist[k][j] * x)  
            {  
                dis[j] = cost[k][j] - dist[k][j] * x;  
                pre[j] = k;  
            }  
        }  
    }  
#if 0//0 for 二分， 1 for 迭代  
    return totalcost / totaldist;  
#else  
    return sum;  
#endif  
      
}  
int main()  
{  
    while (scanf("%d", &n), n)  
    {  
        for (int i = 1; i <= n; ++ i)  
        {  
            scanf("%d%d%d", &x[i], &y[i], &z[i]);  
            for (int j = 1; j < i; ++ j)  
            {  
                double tmp = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);  
                cost[i][j] = cost[j][i] = abs(z[i] - z[j]);//海拔  
                dist[i][j] = dist[j][i] = sqrt(tmp);//欧式距离  
            }  
        }  
        double a = 0;  
#if 0//1为迭代，0为二分  
        while (1)//迭代求最大值  
        {  
            double b = prim(a);  
            if (abs(a - b) < eps)  
            {  
                printf("%.3f\n", a);  
                break;  
            }  
            else  
                a = b;  
        }  
#else  
        double head = 0,tail = 100000.0;  
        while (tail - head > 1e-5)  
        {  
            double mid = (head + tail) / 2.0;  
            a = prim(mid);  
            if (a >= 0)  
            {  
                head = mid;  
            }  
            else  
                tail = mid;  
        }  
        printf("%.3f\n", tail);  
#endif  
    }  
    return 0;  
}  

