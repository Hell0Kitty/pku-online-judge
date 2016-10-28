#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 10000 + 10;
typedef long long LL;

LL c[maxn], y[maxn], n, s;

int main()
{
    while(~ scanf("%d%d", &n, &s)) {
        for(int i = 1; i <= n; i++) {
            scanf("%d%d", &c[i], &y[i]);
        }

        LL ans = 0, cost;
        for(int i = 1; i <= n; i++) {
            if(i == 1) {
                cost = c[i];
                ans += cost * y[i];
            }
            else {
                cost = min(cost + s, c[i]);
                ans += cost * y[i];
            }
        }

        printf("%lld\n", ans);
    }
    return 0;
}



