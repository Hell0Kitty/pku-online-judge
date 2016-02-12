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
#define maxn 12345
#define MAX 1<<30

using namespace std;

int t, n, m, s[123], a, sg[12345], ans;

int main()
{
	scanf("%d", &m);
	while (m)
	{
		rep(i, 1, m) scanf("%d", &s[i]);
		rep(x, 0, 10000) 
		{
			bool b[123]; sg[x] = 0;
			rep(i, 0, 100) b[i] = false; 
			rep(i, 1, m) if (s[i]<=x) b[sg[x-s[i]]] = true;
			while (b[sg[x]]) sg[x]++;
		}
		scanf("%d", &t); 
		rep(i, 1, t)
		{
			scanf("%d", &n); ans = 0;
			rep(i, 1, n) { scanf("%d", &a); ans ^= sg[a]; }
			if (ans) printf("W"); else printf("L");
		}
		printf("\n"); scanf("%d", &m);
	}
	return 0;
}



