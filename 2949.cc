#include <iostream>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define mmst(a, b) memset(a, b, sizeof(a))

typedef long long LL;

const int maxn = 26*26+5, maxm = 2*100005;
const double eps = 1e-2;

int n, eu[maxm], ev[maxm], len[maxm], edge[maxn][maxn];
int N, head[maxn], check[maxn], o[maxn];
bool vis[maxn];
double dis[maxn];
char s[1005];

struct Edge
{
	int v, ne; double w;
	Edge(int _v = 0, double _w = 0, int _ne = 0) : v(_v), w(_w), ne(_ne) {}
}e[maxm];

void Insert(int u, int v, double w)
{
	e[++N] = Edge(v, w, head[u]);
	head[u] = N;
}

bool SPFA()
{
	int h, t, i, u, v;

	for (i = 0; i < 26*26; i++) o[i] = i, dis[i] = 0, vis[i] = true, check[i] = 1;
	for (h = 0, t = 26*26-1; h <= t; h++)
	{
		if (dis[ o[t%maxn] ] < dis[ o[h%maxn] ]) swap(o[h%maxn], o[t%maxn]);
		u = o[h%maxn];
		vis[u] = false;
		for (i = head[u]; i != -1; i = e[i].ne)
		{
			v = e[i].v;
			if (dis[v] <= dis[u] + e[i].w) continue;
			dis[v] = dis[u] + e[i].w;
			if (vis[v]) continue;
			vis[v] = true;
			check[v]++;
			if (check[v] > 10) return true;
			t++;
			o[t%maxn] = v;
		}
	}
	return false;
}

bool Check(double ans)
{
	int i;

	N = -1; mmst(head, -1);
	for (i = 1; i <= n; i++)
		Insert(eu[i], ev[i], ans-len[i]);
	return SPFA();
}

int ju[100000+15],jv[100000+15];
bool boo[26*26+15][26*26+15];
int tjfuc;
void Solve()
{
	int i, j, u, v; double l, r, mid;

	scanf("%d", &n);
	mmst(edge, -1);
	for (i = 1; i <= n; i++)
	{
		scanf("%s", s);
		len[i] = strlen(s);
		u = 26*(s[0]-'a') + s[1] - 'a';
		v = 26*(s[len[i]-2]-'a') + s[len[i]-1] - 'a';
		ju[i]=u;
		jv[i]=v;
		if (edge[u][v] != -1) edge[u][v] = max(edge[u][v], len[i]);
			else edge[u][v] = len[i];
	}
	int nn = 0;
	tjfuc++;
//	for (i = 0; i < 26*26; i++)
//		for (j = 0; j < 26*26; j++) 
	int ll,rr;
	ll=1001;rr=-1;
	for (i=1;i<=n;i++)
	if (boo[ju[i]][jv[i]]!=tjfuc)
	{
			boo[ju[i]][jv[i]]=tjfuc;
			eu[++nn] = ju[i], ev[nn] = jv[i], len[nn] = edge[ju[i]][jv[i]];
			ll=min(ll,edge[ju[i]][jv[i]]);
			rr=max(rr,edge[ju[i]][jv[i]]);
	}
	if (!Check(0)) 
	{printf("No solution.\n");return ;}
	n=nn;
	l=ll;r=rr;
	while (l+eps < r)
	{
		mid = (l+r) / 2;
		if (Check(mid)) l = mid;
			else r = mid;
	}
	printf("%.2lf\n", l);

}

int main()
{
	while (true)
	{
		scanf("%d", &n);
		if (n == 0) break;
		Solve();
	}	

	return 0;
}



