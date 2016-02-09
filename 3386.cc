#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    int a1, a2, b1, b2, p;
    scanf("%d%d%d%d%d", &a1, &a2, &b1, &b2, &p);
    if ((a1 <= b2 && b1 <= p) || (b1 <= a2 && a1 <= p) || a1 + b1 <= p)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}


