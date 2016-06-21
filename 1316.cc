#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxn 10001

bool is_self[maxn];

int generate(int a)
{
    int ret = a;
    while (a)
    {
        ret += a % 10;
        a /= 10;
    }
    return ret;
}

int main()
{
    for (int i = 1; i < maxn; i++)
        is_self[i] = true;
    for (int i = 1; i < maxn; i++)
    {
        if (is_self[i])
            printf("%d\n", i);
        int temp = generate(i);
        if (temp < maxn)
            is_self[temp] = false;
    }
    return 0;
}


