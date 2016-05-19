#include <iostream>
#include <cstdio>
#include <sstream>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <functional>

#define sz(v) ((int)(v).size())
#define rep(i, n) for(int i = 0; i < n; i++)
#define repf(i, a, b) for(int i = a; i <= b; i++)
#define repd(i, a, b) for(int i = a; i >= b; i--)
#define out(n) printf("%d\n", n)
#define mset(a, b) memset(a, b, sizeof(a)

using namespace std;

typedef long long lint;
const int INF = 1 << 30;
const int MaxN = 100005;

int c[22][22];
double f[2][22];
int n;
double p;

void get_c()
{
    repf(i, 1, 21) {
        c[i][0] = 1;
        repf(j, 1, i - 1) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
        c[i][i] = 1;
    }
}

double mypow(double x, int y)
{
    double res = 1.0;
    repf(i, 1, y) res *= x;
    return res;
}

int main()
{
    get_c();

    while(2 == scanf("%d%lf", &n, &p)) {
        repf(i, 1, n) {
            f[0][i] = 0.0;
            repf(j, 1, i - 1) {
                f[0][i] += c[i - 1][i - j] * f[1][j] * mypow(mypow((1 - p), j), i - j);
            }
            f[1][i] = 1 - f[0][i];
        }
        printf("%.8lf", f[1][n]);
    }
    return 0;
}


