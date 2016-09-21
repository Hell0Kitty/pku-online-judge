#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double EPS = 1e-7;

inline int dcmp(double d)
{
	if (fabs(d)<EPS) return 0;
	return d>0?1:-1;
}

struct sp
{
	double x, y, z;
	sp() {}
	sp(double a, double b, double c): x(a), y(b), z(c) {}
	void read() {scanf("%lf%lf%lf", &x, &y, &z);}
};
sp operator-(const sp &u, const sp &v)
{return sp(u.x-v.x, u.y-v.y, u.z-v.z);}
sp operator+(const sp &u, const sp &v)
{return sp(u.x+v.x, u.y+v.y, u.z+v.z);}
sp operator*(double d, const sp &v)
{return sp(d*v.x, d*v.y, d*v.z);}

struct ss
{
	sp a, b;
	ss() {}
	ss(sp u, sp v): a(u), b(v) {}
};

double norm(const sp &v)
{return sqrt(v.x*v.x+v.y*v.y+v.z*v.z);}

double normsqr(const sp &v)
{return v.x*v.x+v.y*v.y+v.z*v.z;}

double dis(const sp &u, const sp &v)
{return norm(u-v);}

sp det(const sp &u, const sp &v)
{
	sp res;
	res.x = u.y*v.z-v.y*u.z;
	res.y = u.z*v.x-u.x*v.z;
	res.z = u.x*v.y-u.y*v.x;
	return res;
}

double dot(const sp &u, const sp &v)
{return u.x*v.x+u.y*v.y+u.z*v.z;}

bool online(const sp &p, const ss &s)
{
	return dcmp(norm(det(p-s.a, p-s.b)))==0 &&
		(s.a.x-p.x)*(s.b.x-p.x)<EPS &&
		(s.a.y-p.y)*(s.b.y-p.y)<EPS &&
		(s.a.z-p.z)*(s.b.z-p.z)<EPS;
}

sp ptoline(const sp &p, const ss &s)
{
	sp ab = s.b-s.a;
	double t = -dot(p-s.a, ab)/normsqr(ab);
	ab.x *= t;
	ab.y *= t;
	ab.z *= t;
	return s.a-ab;
}

double dis(const sp &p, const ss &s)
{
	sp q = ptoline(p, s);
	if (online(q, s)) return dis(q, p);
	else return min(dis(s.a, p), dis(s.b, p));
}

sp p[10], org, s, t;
ss seg[2];

double d;

int main()
{
	int i, j, k;
	while (~scanf("%lf%lf%lf", &p[0].x, &p[0].y, &p[0].z))
	{
		for (i = 1; i < 4; ++i)
		   	p[i].read();
		org.read();
		scanf("%lf", &d);
		seg[0] = ss(p[0], p[1]);
		seg[1] = ss(p[2], p[3]);
		sp hmr, mdk;
		if (dis(seg[0].a, org)<d+EPS) s = seg[0].a;
		else
		{
			hmr = (d/norm(seg[0].a-org))*(seg[0].a-org);
			s = org+hmr;
		}
		if (dis(seg[0].b, org)<d+EPS) t = seg[0].b;
		else
		{
			hmr = (d/norm(seg[0].b-org))*(seg[0].b-org);
			t = org+hmr;
		}
		double low = 0, high = 1, l, r;
		hmr = s, mdk = t;
		//int tt = 120;
		while (dis(hmr, mdk)>EPS)
		{
			l = low+(high-low)/4;
			r = high-(high-low)/4;
			hmr = s+(l*(t-s));
			mdk = s+(r*(t-s));
			if (dis(hmr, seg[1])>dis(mdk, seg[1]))
				low = l;
			else 
				high = r;
		}
		hmr = s+(l*(t-s));
		printf("%.3f\n", dis(hmr, seg[1]));
	}
	return 0;
}


