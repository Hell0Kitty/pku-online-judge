#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

const int maxn = 1010;

int t, n, m;
int height[maxn], l[maxn], r[maxn];

int dp();

int main()
{

    scanf("%d", &t);

    while(t-- != 0)
    {
        memset(height, 0, sizeof(height));
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));
        scanf("%d %d", &n, &m);
        int maxv = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                char s[3];
                scanf("%s", s);
                if(s[0] == 'F')
                    height[j]++;
                else
                    height[j] = 0;
            }

            int tmp = dp();
            maxv = max(maxv, tmp);
        }
        printf("%d\n", maxv * 3);
    }

    return 0;
}

int dp()
{
    l[0] = l[m+1] = r[0] = r[m+1] = -1;
    for(int i = 1; i <= m; i++)
    {
        if(height[i] > 0)
        {
            for(int j = i - 1; ; j = l[j])
            {
                if(height[j] < height[i])
                {
                    l[i] = j;
                    break;
                }
            }
        }

    }

    for(int i = m; i >= 1; i--)
    {
        if(height[i] > 0)
        {
            for(int j = i + 1; ; j = r[j])
            {
                if(height[j] < height[i])
                {
                    r[i] = j;
                    break;
                }
            }
        }
    }

    int maxv = 0;
    for(int i = 1; i <= m; i++)
    {
        if(height[i] > 0)
            maxv = max(maxv, (r[i] - l[i] - 1) * height[i]);
    }
    return maxv;
}



