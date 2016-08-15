#include <stdio.h>
#include <algorithm>
using namespace std;

struct rectangle
{
	int x;
	int y;
}r[1008];

int cmp(const rectangle &a, const rectangle &b)
{
	if(a.y != b.y)
	{
		return a.y >b.y;
	}
	else
	{
		return a.x > b.x;
	}
}

void solve()
{
	int t;
	int x;
	int y;
	int sum;
	while(scanf("%d",&t)!=EOF)
	{
		sum = 0;
		if(t == -1)
		{
			break;
		}
		memset(r,0,sizeof(r));
		for(int i = 0 ;i < t; i++)
		{
			scanf("%d%d",&r[i].x,&r[i].y);
			if(r[i].x > r[i].y)
			{
				swap(r[i].x,r[i].y);
			}
		}
		sort(r,r+t,cmp);
		int dx = min(r[0].x,r[1].y);
		int dy = min(r[1].x,r[0].y);
		sum = dx*dy+(r[1].y-dx)*dy+(r[0].y - dy)*dx;
		for(int i = 2; i< t ;i ++)
		{
			if(r[i].x > dx && r[i].y >dy)
			{
				sum+=(r[i].x-dx)*(r[i].y-dy);
				dx = r[i].x;
			}
			else if(r[i].x > dy && r[i].y >dx)
			{
				sum+=(r[i].x-dy)*(r[i].y-dx);
				dy = r[i].x;
			}
		}
		printf("%d\n",sum);
	}
}

int main()
{
	solve();
	return 0;
}



