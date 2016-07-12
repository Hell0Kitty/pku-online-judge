#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;
const double esp = 1e-5;
const int maxn = 505;
struct ppp
{
	int u,v,val;
	friend bool operator <(ppp a,ppp b)
	{
		return a.val < b.val;
	}
}e[505 * 505];
int fa[maxn];
int find(int x)
{
	return fa[x] = (fa[x] == x)? x :find(fa[x]);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N;
		scanf("%d",&N);
		int len = 0;
		for(int i = 1;i <= N;i++)
			for(int j = 1;j <= N;j++)
			{
				int val;
				scanf("%d",&val);
				if(i <= j)continue;
				e[len].u = i;e[len].v = j;e[len++].val = val;
			}
		sort(e,e + len);
		for(int i = 0;i < maxn;i++)fa[i] = i;
		int ans = 0;
		for(int i = 0;i < len;i++)
		{
			int x = find(e[i].u);
			int y = find(e[i].v);
			if(x != y)
			{
				fa[y] = x;
				ans = max(ans,e[i].val);
			}
		}
		printf("%d\n",ans);
	}
}



