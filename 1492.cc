#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 32

int f[maxn];
int g[maxn];

int main()
{
//    freopen("t.txt", "r", stdin);
    while (1)
    {
        int n = 0;
        int a;
        while (scanf("%d", &a), a)
            f[n++] = a;
        if (!n)
                break;
        int temp = 1;
        while (temp < n && f[temp] == f[temp - 1])
            temp++;
        if (temp >= n)
        {
            printf("Nr values = %d:  %.6f %.6f\n", n, 0.0, 0.0);
            continue;
        }
        int head = temp;
        for (int i = temp; i < n; i++)
            g[i - temp] = f[i] - f[i - 1];
        int m = n - temp;
        int cnt1 = 0, len1 = 0, cnt2 = 0, len2 = 0;
        bool positive = false;
        if (g[0] > 0)
        {
            len1 += head;    
            positive = true;
        }else
        {
            len2 += head;
            positive = false;
        }
        int i = 1;
        while (i < m)
        {
            if (positive)
            {
                while (i < m && g[i] >= 0)
                    len1++, i++;
                cnt1++;
                positive = false;
            }else
            {
                while (i < m && g[i] <= 0)
                    len2++, i++;
                cnt2++;
                positive = true;
            }
        }    
        double ans1 = len1;
        double ans2 = len2;
        if (cnt1)
            ans1 /= cnt1;
        if (cnt2)
            ans2 /= cnt2;
        printf("Nr values = %d:  %.6f %.6f\n", n, ans1, ans2);
    }
    return 0;
}


