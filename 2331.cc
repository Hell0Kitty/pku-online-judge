#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>

using namespace std;

const int maxn = 1000 + 10;
const int inf = (-1u) >> 1;

int xa, ya, xb, yb, k, c[4], l[4], ans;
int len1, len2;

void dfs2(int x, int cur, int len) {
    if (len == 0) ans = min(cur, ans);
    if (x == k) return ;
    dfs2(x + 1, cur, len);
    for (int i = 1; i <= c[x]; ++i) {
        dfs2(x + 1, cur + i, len + i * l[x]);
        dfs2(x + 1, cur + i, len - i * l[x]);
    }
}

void dfs(int x, int cur, int len) {
    if (len == 0) dfs2(0, cur, len2);
    if (x == k) return ;
    dfs(x + 1, cur, len);
    for (int i = 1; i <= c[x]; ++i) {
        c[x] -= i;
        dfs(x + 1, cur + i, len + i * l[x]);
        dfs(x + 1, cur + i, len - i * l[x]);
        c[x] += i;
    }
}

int main() {
    scanf ("%d%d%d%d%d", &xa, &ya, &xb, &yb, &k);
    for (int i = 0; i < k; ++i)
        scanf ("%d", &l[i]);
    for (int i = 0; i < k; ++i)
        scanf ("%d", &c[i]);
    len1 = abs(xa - xb), len2 = abs(ya - yb);
    ans = inf;
    dfs(0, 0, len1);
    if (ans == inf) ans = -1;
    printf ("%d\n", ans);
    return 0;
}



