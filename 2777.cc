#include<cstdio>
#include<cstring>
#include<algorithm>
#define _Clr(x, y) memset(x, y, sizeof(x))
#define lson rt<<1, l, m
#define rson rt<<1|1, m+1, r
#define lch rt<<1
#define rch rt<<1|1
#define INF 0x3f3f3f3f
using namespace std;

typedef long long LL;
const int N = 1e5+10;
int col[N<<2];
bool have[35];
int cnt;

inline void push_up(int rt)
{
	col[rt] = col[lch] + col[rch];
}

inline void push_down(int rt)
{
	if(col[rt])
	{
		col[lch] = col[rch] = col[rt];
		col[rt] = 0;
	}
}

void build(int rt, int l, int r)
{
	col[rt] = 1;
	if(l==r) return;
	else
	{
		int m = (l+r) >> 1;
		build(lson);
		build(rson);
	}
}

void update(int rt, int l, int r, int L, int R, int val)
{
	if(L<=l && r<=R)
		col[rt] = val;
	else
	{
		push_down(rt);
		int m = (l+r) >> 1;
		if(L <= m) update(lson, L, R, val);
		if(R > m) update(rson, L, R, val);
	}
}

void query(int rt, int l, int r, int L, int R)
{
	if(col[rt])
	{
		if(col[rt] && !have[col[rt]])
			cnt++;
		have[col[rt]] = true;
	}
	else
	{
		push_down(rt);
		int m = (l+r) >> 1;
		if(L <= m) query(lson, L, R);
		if(R > m) query(rson, L, R);
	}
}

int main()
{
	int L, n, m;
	int a, b, c;
	char cmd;
	while(~scanf("%d%d%d", &L, &n, &m))
	{
		build(1, 1, L);
		while(m--)
		{
			scanf(" %c%d%d", &cmd, &a, &b);
			if(cmd=='C')
			{
				scanf("%d", &c);
				update(1, 1, L, a, b, c);
			}
			else
			{
				cnt=0;
				_Clr(have, 0);
				query(1, 1, L, a, b);
				printf("%d\n", cnt);
			}
		}
	}
	return 0;
}



