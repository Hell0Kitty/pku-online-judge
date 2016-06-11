#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 110
using namespace std;
char str[MAXN];
int n, p;
int g[MAXN][MAXN], x[MAXN];
int GET(char ch) {
    if (ch == '*')
        return 0;
    return ch - 'a' + 1;
}
int PowMod(int a, int b, int c) {
    int res;
    for (res = 1; b; b >>= 1) {
        if (b & 1) {
            res *= a;
            res %= c;
        }
        a *= a;
        a %= c;
    }
    return res;
}
int EXTGCD(int a, int b, int &x, int &y) {
    int t, d;
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    d = EXTGCD(b, a % b, x, y);
    t = x;
    x = y;
    y = t - a / b * y;
    return d;
}
int Invmod(int a, int n) {
    int x, y;
    EXTGCD(a, n, x, y);
    return (x % n + n) % n;
}
void Gauss() {
    int i, j, k, tmp;
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            if (g[j][i])
                break;
        }
        if (j != i) {
            for (k = i; k <= n; k++)
                swap(g[j][k], g[i][k]);
        }
        for (j = i + 1; j < n; j++) {
            if (g[j][i]) {
                tmp = (g[j][i] * Invmod(g[i][i], p)) % p;
                for (k = i; k <= n; k++) {
                    g[j][k] -= tmp * g[i][k];
                    g[j][k] = (g[j][k] % p + p) % p;
                }
            }
        }
    }
    for (i = n - 1; i >= 0; i--) {
        tmp = 0;
        for (j = i + 1; j < n; j++) {
            tmp += x[j] * g[i][j];
            tmp = (tmp % p + p) % p;
        }
        tmp = g[i][n] - tmp;
        tmp = (tmp % p + p) % p;
        x[i] = tmp * Invmod(g[i][i], p) % p;
    }
}
int main() {
    int c;
    int i, j;
    scanf("%d", &c);
    while (c--) {
        scanf("%d %s", &p, str);
        n = strlen(str);
        for (i = 0; i < n; i++) {
            g[i][n] = GET(str[i]);
            for (j = 0; j < n; j++)
                g[i][j] = PowMod(i + 1, j, p);
        }
        Gauss();
        printf("%d", x[0]);
        for (i = 1; i < n; i++)
            printf(" %d", x[i]);
        putchar('\n');
    }
    return 0;
}



