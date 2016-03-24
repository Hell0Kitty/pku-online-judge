#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn = 211111;
const double eps = 1e-6;
typedef long long LL;
struct node {
	double w, v, val;
	node() {
	}
	node(double w, double v) :
			w(w), v(v) {
		val = 0;
	}
	bool operator<(const node& t) const {
		return val < t.val;
	}
} f[maxn];
double F;
int main() {
	int n, k, i;
	double w, p, b, v, c;
	scanf("%d%d%lf", &n, &k, &F);
	for (i = 0; i < n; ++i) {
		scanf("%lf%lf%lf", &p, &b, &c);
		v = (p * b) / (p + b);
		f[i] = node(v * c * F, v);
	}
	double rate = 0, pre = -100;
	rate = f[0].w / f[0].v;
	for (i = 0; i < n; ++i)
		f[i].val = f[i].w - f[i].v * rate;
	while (fabs(rate - pre) > eps) {
		pre = rate;
		w = v = 0;
		sort(f, f + n);
		for (i = 0; i < k; ++i)
			w += f[i].w, v += f[i].v;
		rate = w / v;
		for (i = 0; i < n; ++i)
			f[i].val = f[i].w - f[i].v * rate;
	}
	printf("%.4f\n", rate);
	return 0;
}
