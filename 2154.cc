#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#define EPS 1e-8
#define MAXN 32000
using namespace std;
vector<int> fac;
vector<int> g;
vector<int> prime;
int P;
bool p[MAXN];
void Init() {
    int i, j;
    memset(p, true, sizeof(p));
    for (i = 2; i < 180; i++) {
        if (p[i]) {
            for (j = i * i; j < MAXN; j += i)
                p[j] = false;
        }
    }
    prime.clear();
    for (i = 2; i < MAXN; i++) {
        if (p[i])
            prime.push_back(i);
    }
}
void Factor(int n) {
    int i, tmp;
    fac.clear();
    tmp = (int) (sqrt((double) n) + EPS);
    for (i = 1; i <= tmp; i++) {
        if (n % i == 0) {
            fac.push_back(i);
            if (i == tmp && i * i == n)
                continue;
            fac.push_back(n / i);
        }
    }
}
int PowMod(int a, int b, int c) {
    int res;
    a %= c;
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
void Prime(int x) {
    int i, tmp;
    g.clear();
    tmp = (int) (sqrt((double) x) + EPS);
    for (i = 0; prime[i] <= tmp; i++) {
        if (x % prime[i] == 0) {
            g.push_back(prime[i]);
            while (x % prime[i] == 0)
                x /= prime[i];
        }
    }
    if (x > 1)
        g.push_back(x);
}
int Mul(int x, int &k) {
    int i, ans = 1;
    for (i = k = 0; x; x >>= 1, i++) {
        if (x & 1) {
            ans *= g[i];
            k++;
        }
    }
    return ans;
}
int Count(int x) {
    int i, j, t, tmp, ans;
    Prime(x);
    ans = 0;
    t = (int) g.size();
    for (i = 1; i < (1 << t); i++) {
        tmp = Mul(i, j);
        if (j & 1)
            ans += x / tmp;
        else
            ans -= x / tmp;
    }
    return (x - ans) % P;
}
int main() {
    int c;
    int n, ans, i;
    Init();
    scanf("%d", &c);
    while (c--) {
        scanf("%d%d", &n, &P);
        Factor(n);
        ans = 0;
        for (i = 0; i < (int) fac.size(); i++) {
            ans += PowMod(n, fac[i] - 1, P) * Count(n / fac[i]);
            ans %= P;
        }
        printf("%d\n", ans);
    }
    return 0;
}



