#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <cmath>
#include <algorithm>

#define CL(arr, val)    memset(arr, val, sizeof(arr))
#define REP(i, n)       for(i = 0; i < n; ++i)
#define FOR(i, l, h)    for(i = l; i <= h; ++i)
#define FORD(i, h, l)   for(i = h; i >= l; --i)
#define L(x)    x << 1
#define R(x)    x << 1 | 1
#define MID(l, r)  (l + r) >> 1
typedef long long LL;

using namespace std;

const int N = 10010;
const int M = 510;

int dp[N][M];
short num[N];

int main() {
    int i, j, n, m;

    scanf("%d%d", &n, &m);
    FOR(i, 1, n)   scanf("%hd", num + i);

    CL(dp, 0);
    FOR(i, 1, n) {
        dp[i][0] = dp[i-1][0];
        FOR(j, 1, m) {
            if(i - j >= 0) {
                dp[i][0] = max(dp[i][0],  dp[i - j][j]);
            }
            dp[i][j] = dp[i-1][j-1] + num[i];
        }
    }
    printf("%d\n", dp[n][0]);
    return 0;
}


