#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

#define maxn 305

struct XPoint
{
	int x, y;
	XPoint()
	{
	}		
	XPoint(int xx, int yy) :
	x(xx), y(yy)
	{
	}
} aa[maxn], bb[maxn];

int n;

int len(XPoint &a, XPoint &b)
{
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool checkedge()
{
	int a1 = len(aa[0], aa[1]);
	int b1 = len(bb[0], bb[1]);
	for (int i =0; i < n; i++)
	for (int j =0; j < n; j++)
	if ((long long) a1 * len(bb[i], bb[j]) != (long long) b1 * len(aa[i],aa[j]))
	return false;
	return true;
}

int main()
{
	while (scanf("%d", &n) != EOF && n !=0)
	{
		bool flag =false;
		for (int i =0; i < n; i++)
			scanf("%d%d", &aa[i].x, &aa[i].y);
		for (int i =0; i < n; i++)
			scanf("%d%d", &bb[i].x, &bb[i].y);
		long long d1 = (aa[1].x - aa[0].x) * (aa[2].y - aa[0].y) - (aa[1].y - aa[0].y) * (aa[2].x - aa[0].x);
		long long d2 = (bb[1].x - bb[0].x) * (bb[2].y - bb[0].y) - (bb[1].y - bb[0].y) * (bb[2].x - bb[0].x);
		if (checkedge()&& d1 * d2 >=0)
			flag =true;
		if (flag)
			printf("similar\n");
		else
			printf("dissimilar\n");
	}
	return 0;
}


