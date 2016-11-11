#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int sg =0, n;
        bool flag =false;
        scanf("%d", &n);
        for (int i =0; i < n; i++)
        {
            int a;
            scanf("%d", &a);
            sg ^= a;
            if (a !=1)
                flag =true;
        }
        if ((flag && sg) || (!flag &&!sg))
            printf("John\n");
        else
            printf("Brother\n");
    }
    return 0;
}



