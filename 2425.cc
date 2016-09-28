#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>

#define rep(i, l, r) for(int i = l; i <= r; i++)
#define down(i, l, r) for(int i = l; i >= r; i--)
#define maxn 1234
#define MAX 1<<30

using namespace std;

struct e{int y, n;} e[1234567]; int f[maxn];
int n, m, k, a, ans, sg[maxn];

int Cal(int x)
{
	if (sg[x]>=0) return sg[x]; else sg[x] = 0;
	bool b[maxn]; rep(i, 0, n) b[i] = false;
	int o = f[x];
	while (o) 
	{
		b[Cal(e[o].y)] = true;
		o = e[o].n;
	}
	while (b[sg[x]]) sg[x]++;
	return sg[x];
}

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		rep(i, 0, n-1) f[i] = 0, sg[i] = -1;
		rep(x, 0, n-1) 
		{
			int y;
			scanf("%d", &k);
			rep(i, 1, k)
			{
				scanf("%d", &y);
				e[++m].y = y, e[m].n = f[x], f[x] = m;
			}
		}
		rep(i, 0, n-1) if (sg[i] < 0) sg[i] = Cal(i);
		scanf("%d", &k);
		while (k)
		{
			ans = 0;
			rep(i, 1, k) { scanf("%d", &a); ans^=sg[a]; }
			if (ans) printf("WIN\n"); else printf("LOSE\n");
			scanf("%d", &k);
		}
	}
	return 0;
}



