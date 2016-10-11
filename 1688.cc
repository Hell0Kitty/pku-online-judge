#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
#define MAXN 22
#define PI 3.14159265358979323846
#define eps 1e-8
using namespace std;

//二维点
struct pt
{
	double x, y;
};

double dis(const pt &a, const pt &b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}

//求直线ab和直线cd的交点
pt its(const pt &a, const pt &b, const pt &c, const pt &d)
{
	pt ret = a;
	double t =  ((c.x - a.x)*(d.y - c.y) - (c.y - a.y)*(d.x - c.x))/
				((b.x - a.x)*(d.y - c.y) - (b.y - a.y)*(d.x - c.x));
	ret.x += (b.x - a.x) * t;
	ret.y += (b.y - a.y) * t;
	return ret;
}
void intersection_line_circle(pt c, double r, pt l1, pt l2, pt &p1, pt &p2)
{
	pt p = c;
	p.x += l1.y - l2.y;
	p.y += l2.x - l1.x;
	p = its(p, c, l1, l2);
	double d = dis(p,c), t = sqrt(r*r - d*d) / dis(l1,l2);
	p2.x = p.x + (l2.x-l1.x)*t;
	p2.y = p.y + (l2.y-l1.y)*t;
	p1.x = p.x - (l2.x-l1.x)*t;
	p1.y = p.y - (l2.y-l1.y)*t;
}

void intersection_circle_circle(pt c1, double r1, pt c2, double r2, pt &p1, pt &p2)
{
	pt u, v;
	double t = (1+(r1*r1-r2*r2)/dis(c1,c2)/dis(c1,c2))/2;
	u.x = c1.x + (c2.x-c1.x)*t;
	u.y = c1.y + (c2.y-c1.y)*t;
	v.x = u.x + c1.y - c2.y;
	v.y = u.y - c1.x + c2.x;
	intersection_line_circle(c1, r1, u, v, p1, p2);
}

struct Cut
{
	double vAng;	//极角 
	double rAng;	//转角 
	int del;		//增量 1:进 -1:出
	Cut(double _vAng, double _rAng, int _del)
	{
		vAng = _vAng;
		rAng = _rAng;
		del = _del;
	}
	bool operator < (const Cut c)const{return vAng < c.vAng;}
};

vector<Cut> cut[MAXN]; 
pt p[MAXN];
double r[MAXN];
int n, ccnt[MAXN], pa[MAXN];
int fp(int x){return x == pa[x] ? x : pa[x] = fp(pa[x]);}

double toAng(double s, double t)
{
	double res = t - s;
	while (res < -eps)
		res += 2*PI;
	while (res - 2*PI > -eps)
		res -= 2*PI;
	return res;
}

int solve()
{
	pt A, B;
	double angA1, angA2, angB1, angB2, rAng; 
	for (int i = 0; i < n; i++)
	{
		pa[i] = i;
		cut[i].clear();
		ccnt[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (dis(p[i], p[j]) < r[i] + r[j] - eps)
			{
				pa[fp(i)] = fp(j);
				intersection_circle_circle(p[i], r[i], p[j], r[j], A, B);
				angA1 = atan2(A.y - p[i].y, A.x - p[i].x);
				angA2 = atan2(A.y - p[j].y, A.x - p[j].x);
				angB1 = atan2(B.y - p[i].y, B.x - p[i].x);
				angB2 = atan2(B.y - p[j].y, B.x - p[j].x);
				rAng = toAng(angB1, angB2);
				cut[i].push_back(Cut(angA1, -rAng, 1));
				cut[i].push_back(Cut(angB1, 0, -1));
				if (angA1 > angB1)
					ccnt[i]++;
				cut[j].push_back(Cut(angA2, 0, -1));
				cut[j].push_back(Cut(angB2, -rAng, 1));
				if (angB2 > angA2)
					ccnt[j]++;
			}
		}
	}

	double tAng = 0.0;
	for (int i = 0; i < n; i++)
	{
		if (cut[i].size() == 0)
		{
			tAng += 2 * PI;
			continue;
		}
		sort(cut[i].begin(), cut[i].end());
		double lastAng = cut[i][cut[i].size() - 1].vAng;
		for (int j = 0; j < cut[i].size(); j++)
		{
			if (ccnt[i] == 0)
				tAng += toAng(lastAng, cut[i][j].vAng) + cut[i][j].rAng; 
			ccnt[i] += cut[i][j].del;
			if (ccnt[i] == 0)
				lastAng = cut[i][j].vAng;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (fp(i) == i)
		{
			tAng -= 2 * PI;
		}
	}

	return (int)(-tAng / (2*PI) + 0.5);
}

int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%lf %lf %lf", &p[i].x, &p[i].y, &r[i]);
		}
		printf("%d\n", solve());
	}
	return 0;
}



