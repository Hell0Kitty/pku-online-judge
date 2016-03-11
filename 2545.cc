#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <deque>
#include <list>

using namespace std;

typedef long long LL;
const int N = 100860;
LL arr[N];
LL H(int a, int b, int c, int t)
{
    int c1, c2, c3, cnt;
    c1 = c2 = c3 = cnt = arr[1] = 1;
    LL ans;
    while (cnt++ <= t)
    {
        ans = min(a * arr[c1], min(b * arr[c2], c * arr[c3]));
        arr[cnt] = ans;
        if (ans == a * arr[c1]) ++c1;
        if (ans == b * arr[c2]) ++c2;
        if (ans == c * arr[c3]) ++c3;
    }
    return ans;
}

int main ()
{
    int p1, p2, p3, i;
    scanf("%d%d%d%d", &p1, &p2, &p3, &i);
    printf("%lld\n", H(p1, p2, p3, i));
    return 0;
}




