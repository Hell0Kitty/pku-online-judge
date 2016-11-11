#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

const double eps = 1e-8 ;
const double PI = acos(-1) ;
int sgn(double x) { return (x < -eps) ? -1 : (x > eps) ; }

//2D PT
struct PT {
	double x, y;
	PT () {}
	PT (double x, double y) : x(x), y(y) {}
	void rd() { scanf("%lf %lf", &x, &y) ; }
	PT operator - (const PT o) { return PT(x - o.x, y - o.y) ; }
	PT operator + (const PT o) { return PT(x + o.x, y + o.y) ; }
	PT operator * (double s) { return PT(x * s, y * s) ; }
	PT operator / (double s) { return PT(x / s, y / s) ; }
	bool operator < (const PT &o) const { return y < o.y-eps || (y < o.y + eps && x < o.x - eps) ; }
	bool operator == (const PT &o) const { return !sgn(y - o.y) && !sgn(x - o.x) ; }
	bool operator != (const PT &o) const { return sgn(y - o.y) || sgn(x - o.x) ; }
}	;

double cpr(PT a, PT b) { return a.x * b.y - a.y * b.x ; }
double dpr(PT a, PT b) { return a.x * b.x + a.y * b.y ; }

double cpr(PT a, PT b, PT c) { return cpr(b - a, c - a) ; }
double dpr(PT a, PT b, PT c) { return dpr(b - a, c - a) ; }

double vlen(PT a) { return sqrt(a.x * a.x + a.y * a.y) ; }
double dist(PT a, PT b) { return vlen(a - b) ; }

struct CLE {
	PT c;
	double r;
	CLE () {}
	CLE (PT c, double r) : c(c), r(r) {}
	void rd() { c.rd(); scanf("%lf", &r); }
	PT pt(double kk) { return c + PT(cos(kk), sin(kk)) * r; }
	double ang(PT a) { return atan2(a.y - c.y, a.x - c.x) ; }
	double sector0(double k1, double k2)
	{
		if (k1 > k2 + eps) return sector0(k1, PI) + sector0(-PI, k2);
		return (k2 - k1) * r * r / 2;
	}
	double sector1(double k1, double k2) { return adjust(k2 - k1) * r * r / 2; }
	double adjust(double kk) 
	{
		if (kk < -PI) kk += PI * 2;
		if (kk > PI) kk -= PI * 2;
		return kk;
	}
	bool operator == (const CLE &o) { return c == o.c && !sgn(r - o.r) ; }
	bool operator != (const CLE &o) { return c != o.c || sgn(r - o.r) ; }
}	;

int plside(PT a, PT b, PT c, PT d) { return sgn(cpr(c, a, d) * cpr(c, b, d)); }

PT ints(PT a, PT b, PT c, PT d)
{
	double v1 = cpr(a, b, c), v2 = cpr(b, a, d);
	return (c * v2 + d * v1) / (v2 + v1);
}

double disptoline(PT p, PT a, PT b) { return fabs(cpr(p, a, b)) / dist(a, b); }

double disptoseg(PT p, PT a, PT b)
{
	PT t = p + PT(a.y - b.y, b.x - a.x) ;
	if (plside(a, b, p, t) == 1) return min(dist(p, a),  dist(p, b));
	return disptoline(p, a, b);
}

void ints_line_circle(PT c, double r, PT a, PT b, PT &p1, PT &p2)
{
	PT p = c + PT(b.y - a.y, a.x - b.x);
	p = ints(p, c, a, b);
	double d = dist(p, c), t = sqrt(r * r - d * d) / dist(a, b);
	p1 = p + (a - b) * t;
	p2 = p - (a - b) * t;
}

double delaunay(PT a, PT b, PT o, double r)
{
	int d1 = (dist(a, o) > r - eps);
	int d2 = (dist(b, o) > r - eps);
	int dd = (disptoseg(o, a, b) < r - eps);

	CLE oo = CLE(o, r);
	double ka = oo.ang(a);
	double kb = oo.ang(b);

	if (dd)
	{
		if (d1 == 0 && d2 == 0) return cpr(o, a, b) / 2;

		PT p1, p2;
		ints_line_circle(o, r, a, b, p1, p2);
		double k1 = oo.ang(p1);
		double k2 = oo.ang(p2);

		if (d1 == 1 && d2 == 1)
		{
			if (dist(p1, a) > dist(p2, a)) swap(p1, p2), swap(k1, k2);
			double ans = oo.sector1(ka, k1) + oo.sector1(k2, kb);
			return ans + cpr(o, p1, p2) / 2;
		}

		if (disptoseg(p1, a, b) > eps) swap(p1, p2), swap(k1, k2);

		if (d1 == 1 && d2 == 0) return oo.sector1(ka, k1) + cpr(o, p1, b) / 2;

		if (d1 == 0 && d2 == 1) return oo.sector1(k1, kb) + cpr(o, a, p1) / 2;
	}

	return oo.sector1(ka, kb);
}

void make_ch_jm_ex(PT p[], PT o[], int n, int &top)
{
	top = 0;
	sort(p, p + n);
	for (int i = 0, j, k = 1; i < 2 * n - 1; i++)
	{
		j = (i < n) ? i : 2 * (n - 1) - i;
		if (i == n) k = top;
		while (top > k && cpr(o[top - 2], o[top - 1], p[j]) < eps) top--;
		o[top++] = p[j];
	}
	top -- ;
}

PT pt[10], p0[10];

int main()
{
	double x, y;

	while (~scanf("%lf %lf", &x, &y))
	{
		pt[0] = PT(x, y);
		pt[1].rd();
		pt[2].rd();

		PT o;
		double rr;
		o.rd();
		scanf("%lf", &rr);

		double ans = 0;
		for (int i = 0; i < 3; i++)
			ans += delaunay(pt[i], pt[(i+1) % 3], o, rr);

		printf("%.2f\n", fabs(ans));
	}
	return 0;
}




