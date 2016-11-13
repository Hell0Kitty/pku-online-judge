#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int n, m;

int main()
{
    int x, y;
    scanf("%d%d", &n, &m);
    x = 0;
    y = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int a;
        scanf("%d", &a);
        x += a;
    }
    for (int i = 0; i < m - 1; i++)
    {
        int a;
        scanf("%d", &a);
        y += a;
    }
    printf("%d\n", (int)ceil(sqrt(x * x + y * y)));
    return 0;
}



