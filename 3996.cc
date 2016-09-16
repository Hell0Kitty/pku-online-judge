#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

const double pi = 3.141;

struct node
{
	double x;
	double y;
	double d1;
	double d2;
	bool operator < ( const node a) const
	{
		if (d1!=a.d1) return d1<a.d1;
		else return d2<a.d2;
	}
}missile[1005],a,b;

struct cmp
{
	bool operator ()(const node &m1, const node &m2)
	{
		return m1.d2<m2.d2;
	}
};

multiset<node, cmp> s;
multiset<node, cmp>::iterator it;

int main()
{
	int n;
	int i;
	double area, left;
	int total;
	int ct;
	int index = 1;
	while(scanf("%d", &n)!=EOF)
	{
		if (n==0) break;
		scanf("%lf %lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y, &area);
		for (i=0; i<n; i++)
		{
			scanf("%lf %lf", &missile[i].x, &missile[i].y);
			missile[i].d1 = ((missile[i].x-a.x)*(missile[i].x-a.x)+(missile[i].y-a.y)*(missile[i].y-a.y))*pi;
			missile[i].d2 = ((missile[i].x-b.x)*(missile[i].x-b.x)+(missile[i].y-b.y)*(missile[i].y-b.y))*pi;
		}
		sort(missile, missile+n);
		s.clear();
		total = 0;
		for (i=n-1; i>=0; i--)
		{
			if (missile[i].d1<=area)
			{
				left = area - missile[i].d1;
				ct = 0;
				for (it=s.begin(); it!=s.end(); it++)
				{
					if ((*it).d2>left) break;
					ct++;
				}
				if (ct+i+1>total)
					total = ct + i + 1;
			}
			s.insert(missile[i]);
		}
		ct = 0;
		for (it=s.begin(); it!=s.end(); it++)
		{
			if ((*it).d2>area) break;
			ct++;
		}
		if (ct>total)
			total = ct;
		printf("%d. %d\n", index, n-total);
		index++;
	}
	return 0;
}
