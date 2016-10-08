#include <iostream>
#include <math.h>
#include <stdio.h>

#define pi acos(-1.0)

struct point{ double x, y; };
struct line{ point a, b; };

double xmult(point p1, point p2, point p0)
{
	return (p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p1.y - p0.y);
}

char sign(double a)
{
	return a > 0 ? '-' : '+';
}
char sign2(double a)
{
	return a > 0 ? '+' : '-';
}

double distance(point p1, point p2){
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

point intersection(line u, line v){
	point ret = u.a;
	double t = ((u.a.x - v.a.x)*(v.a.y - v.b.y) - (u.a.y - v.a.y)*(v.a.x - v.b.x))
		/ ((u.a.x - u.b.x)*(v.a.y - v.b.y) - (u.a.y - u.b.y)*(v.a.x - v.b.x));
	ret.x += (u.b.x - u.a.x)*t;
	ret.y += (u.b.y - u.a.y)*t;
	return ret;
}

//外心
point circumcenter(point a, point b, point c){
	line u, v;
	u.a.x = (a.x + b.x) / 2;
	u.a.y = (a.y + b.y) / 2;
	u.b.x = u.a.x - a.y + b.y;
	u.b.y = u.a.y + a.x - b.x;
	v.a.x = (a.x + c.x) / 2;
	v.a.y = (a.y + c.y) / 2;
	v.b.x = v.a.x - a.y + c.y;
	v.b.y = v.a.y + a.x - c.x;
	return intersection(u, v);
}

double area_triangle(point p1, point p2, point p3)
{
	return fabs(xmult(p1, p2, p3)) / 2;
}

int main()
{
	point a, b, c;
	while (std::cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y)
	{
		point center = circumcenter(a, b, c);
		double p = distance(a, b) * distance(a, c) * distance(b, c);
		double r = 1.0 * p / (4.0*area_triangle(a, b, c));
		printf("(x %c %.3f)^2 + (y %c %.3f)^2 = %.3f^2\n", sign(center.x), fabs(center.x), sign(center.y), fabs(center.y),r);
		printf("x^2 + y^2 %c %.3fx %c %.3fy %c %.3f = 0\n", sign(center.x), 2 * fabs(center.x), sign(center.y), 2 * fabs(center.y), sign2(center.x * center.x + center.y * center.y - r * r), fabs(center.x * center.x + center.y * center.y - r * r));
		puts("");
	}
}


