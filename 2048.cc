#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>

const double eps = 1e-10;

using namespace std;

struct point
{
	double x, y;
	point( double _x = 0., double _y = 0. ) : x(_x), y(_y) {}
	point nor()
	{
		double L = sqrt(x*x+y*y);
		return point(x/L, y/L);
	}
} L[200][2], p[1000];

int dcmp( double x )
{
	if( x < -eps )	return -1;
	return x > eps;
}

double cross( point k, point a, point b )
{
	return (a.x-k.x)*(b.y-k.y) - (a.y-k.y)*(b.x-k.x);
}

double dot( point k, point a, point b )
{
	return (a.x-k.x)*(b.x-k.x) + (a.y-k.y)*(b.y-k.y);
}

bool segCross( point a, point b, point c, point d )
{
	int d1, d2, d3, d4;
	d1 = dcmp(cross(a, b, c));
	d2 = dcmp(cross(a, b, d));
	d3 = dcmp(cross(c, d, a));
	d4 = dcmp(cross(c, d, b));
	if( (d1^d2) == -2 && (d3^d4) == -2 )
		return 1;
	return 0;
}

queue<int> Q;
bool vis[1000];
bool bfs( int S, int T, int np, int nl )
{
	memset(vis, 0, sizeof(vis));
	vis[S] = 1;
	Q.push(S);
	while( !Q.empty() )
	{
		int u = Q.front();	Q.pop();
		for( int i = 0; i < np; ++i )	if( !vis[i] )
		{
			bool ok = 1;
			for( int j = 0; ok && j < nl; ++j )
				if( segCross(p[u], p[i], L[j][0], L[j][1]) )
					ok = 0;
			if( ok )
			{
				vis[i] = 1;
				Q.push(i);
			}
		}
	}
	return vis[T];
}

bool chk( point p, int nl )
{
	for( int i = 0; i < nl; ++i )
		if( dcmp(cross(p, L[i][0], L[i][1])) == 0 && dcmp(dot(p, L[i][0], L[i][1])) < 0 )
			return 0;
	return 1;
}

int main()
{

	int N, e;
	double d = 0.00001;

	while( scanf("%d", &N), N )
	{
		e = 0;
		p[e++] = point(0., 0.);
		p[e++] = point(1000., 1000.);
		for( int i = 0; i < N; ++i )
		{
			scanf("%lf %lf %lf %lf", &L[i][0].x, &L[i][0].y, &L[i][1].x, &L[i][1].y);
			point v = point(L[i][1].x-L[i][0].x, L[i][1].y-L[i][0].y).nor();
			L[i][0] = point(L[i][0].x - v.x*d, L[i][0].y - v.y*d);
			L[i][1] = point(L[i][1].x + v.x*d, L[i][1].y + v.y*d);
		}

		for( int i = 0; i < N; ++i )
		{
			if( chk(L[i][0], N) )	p[e++] = L[i][0];
		   	if( chk(L[i][1], N) )	p[e++] = L[i][1];
		}

		if( bfs(0, 1, e, N) )
			puts("no");
		else
			puts("yes");
	}

	return 0;
}



