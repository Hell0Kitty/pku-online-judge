#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

int n, even, odd;

int main()
{
    scanf("%d", &n);
    if (n == 1)
    {
        int a;
        scanf("%d", &a);
        printf("%d\n", a);
        return 0;
    }
    scanf("%d%d", &odd, &even);
    int a, temp;
    temp = even;
    even = odd - even;
    odd = max(temp, odd);
    for (int i = 2; i < n; i++)
    {
        scanf("%d", &a);
        temp = max(odd, even + a);
        even = max(even, odd - a);
        odd = temp;
    }
    printf("%d\n", max(even, odd));
    return 0;
}



