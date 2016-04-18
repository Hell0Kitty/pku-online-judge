#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;
#define SZ(v) ((int)(v).size())
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPF(i, a, b) for (int i = (a); i <= (b); ++i)
#define REPD(i, a, b) for (int i = (a); i >= (b); --i)
const int maxint = -1u>>1;
double f[1000010], g[1000010];
int sum, n, req;
char ss[100];

int main() {
        n = 0;
        scanf("%s", ss);
        if (ss[0] == 's') n ++; 
        scanf("%s", ss);
        if (ss[0] == 's') n ++;
        scanf("%s", ss);
        if (ss[0] == 's') n ++;
        scanf("%s", ss);
        if (ss[1] == 'a') req = 1; else req = 0; 
        scanf("%d", &sum);

        f[2] = cos((double)0.0);
        g[2] = cos((double)0.0);
        double z, y;
        for (int i = 4; i <= sum; i += 2) {
                y = ((double)i / 2) - 1;
                z = cos(y);
                f[i] = max(f[i - 2], z);
                g[i] = min(g[i - 2], z);
        }
        f[3] = cos((double)0.5);
        g[3] = cos((double)0.5);
        for (int i = 5; i <= sum; i += 2) {
                y = ((double)i / 2) - 1;
                z = cos(y);
                f[i] = max(f[i - 2], z);
                g[i] = min(g[i - 2], z);
        }

        double ans, tmp, t, tt; 
        for (int i = 1; i <= sum - 2; i ++) {
                if (n == 0 || n == 2) tmp = cos((double)i); else tmp = sin((double)i);

                y = (double) (sum - i) / 2;
                if (n == 0 || n == 1) t = 2 * cos(y); else t = 2 * sin(y);
                if (req)
                        tt = max(t * f[sum - i], t * g[sum - i]);
                else
                        tt = min(t * f[sum - i], t * g[sum - i]);

                if (i == 1) ans = tt + tmp; 
                if (req)
                        ans = max(ans, tt + tmp);
                else
                        ans = min(ans, tt + tmp);                
        }       

        printf("%.12f\n", ans);

        return 0;
}


