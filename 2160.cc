#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Pallet
{
    int a, b;
} pallet[10];

bool operator <(const Pallet &p1, const Pallet &p2)
{
    if (p1.a != p2.a)
        return p1.a < p2.a;
    return p1.b < p2.b;
}

bool ok()
{
    for (int i = 0; i < 6; i += 2)
        if (pallet[i].a != pallet[i + 1].a || pallet[i].b != pallet[i + 1].b)
            return false;
    if (pallet[0].b != pallet[2].a)
        swap(pallet[2].a, pallet[2].b);
    if (pallet[2].b != pallet[4].a)
        swap(pallet[4].a, pallet[4].b);
    if (pallet[0].b == pallet[2].a && pallet[2].b == pallet[4].a && pallet[4].b == pallet[0].a)
        return true;
    swap(pallet[0].a, pallet[0].b);
    if (pallet[0].b != pallet[2].a)
        swap(pallet[2].a, pallet[2].b);
    if (pallet[2].b != pallet[4].a)
        swap(pallet[4].a, pallet[4].b);
    if (pallet[0].b == pallet[2].a && pallet[2].b == pallet[4].a && pallet[4].b == pallet[0].a)
        return true;
    return false;
}

int main()
{
    for (int i = 0; i < 6; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a > b)
            swap(a, b);
        pallet[i].a = a;
        pallet[i].b = b;
    }
    sort(pallet, pallet + 6);
    if (ok())
        printf("POSSIBLE\n");
    else
        printf("IMPOSSIBLE\n");
    return 0;
}



