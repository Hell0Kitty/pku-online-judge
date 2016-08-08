#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <bitset>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
const int maxn = 111111;
const int N = 1111;
const double eps = 1e-8;
bitset<maxn + 100> vis;
int p[maxn], size;
void init() {
	int i, j;
	for (i = 2; i * i <= maxn; ++i)
		if (!vis[i])
			for (j = i * i; j <= maxn; vis[j] = 1, j += i)
				;

	p[size++] = 2;
	for (i = 3; i <= maxn; i += 2)
		if (!vis[i])
			p[size++] = i;
}
int f[N], c[N], cnt;
int X[maxn][15];
void split(int n) {
	int i, t = n;
	memset(c, 0, sizeof(c));
	cnt = 0;
	for (i = 0; p[i] * p[i] <= n && i < size; ++i) {
		if (t % p[i] == 0) {
			f[cnt] = p[i];
			while (t % p[i] == 0)
				t /= p[i], c[cnt]++;
			++cnt;
		}
	}
	if (t > 1) {
		f[cnt] = t;
		c[cnt]++;
		++cnt;
	}
}
int cal(int n, int p) {
	LL k = 1;
	int cnt = 0;
	while (n >= k) {
		k *= p;
		cnt += (int) n / k;
	}
	return cnt;
}
int ans[maxn], k;
int main() {
	ios::sync_with_stdio(false);
	init();
	int n, m;
	int i, j;
	while (~scanf("%d%d", &n, &m)) {
		split(m);
		for (i = 0; i < n; ++i) {
			for (j = 0; j < cnt; ++j) {
				X[i][j] = cal(i, f[j]);
			}
		}
		k = 0;
		int mi;
		for (i = 0; i < n; ++i) {
			mi = 1000000;
			for (j = 0; j < cnt; ++j) {
				mi = min(mi, (X[n - 1][j] - X[i][j] - X[n - i - 1][j]) / c[j]);
				if (mi<1)
					break;
			}
			if (mi>0)
				ans[k++] = i + 1;
		}
		printf("%d\n",k);
		for (i = 0; i < k; ++i) {
			printf("%d%c", ans[i], i == k - 1 ? '\n' : ' ');
		}
	}
	return 0;
}



