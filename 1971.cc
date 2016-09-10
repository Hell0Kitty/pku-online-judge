#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

typedef struct _point
{
    int x;
    int y;
}_Point;

_Point p[1000100];
_Point temp[1010];

bool cmp(const _Point& point1, const _Point& point2)
{
    if (point1.x == point2.x)
    {
        return point1.y > point2.y;
    }
    else
    {
        return point1.x > point2.x;
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    while(N--)
    {
        int n;
        scanf("%d", &n);
        int nCount = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &temp[i].x, &temp[i].y);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                p[nCount].x = temp[i].x + temp[j].x;
                p[nCount++].y = temp[i].y + temp[j].y;
            }
        }
        sort(p, p + nCount, cmp);
        int k = 1;
        int sum = 0;
        for (int i = 0; i < nCount; i++)
        {
            if (p[i].x == p[i + 1].x && p[i].y == p[i + 1].y)
            {
                k++;
            }
            else
            {
                sum += (k - 1) * k / 2;
                k = 1;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}



