#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    int n, t;
    while (scanf("%d%d", &t, &n) != EOF && !(t == 0 && n == 0))
    {
        int sum = 0;
        getchar();
        for (int i = 0; i < t; i++)
        {
            string st;
            int a;
            cin >> st;
            scanf("%d", &a);
            sum += a;
            getchar();
        }
        printf("%d\n", 3 * n - sum);
    }
    return 0;
}


