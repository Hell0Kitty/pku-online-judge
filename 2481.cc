#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 100000 + 10;
int cnt[MAX_N];
int ans[MAX_N];
int maxn = -1;
struct node
{
	int s, e;
	int id;
}cow[MAX_N];

inline int read(void)
{
	int x = 0, f = 1;	char ch = getchar ();
	while (ch < '0' || ch > '9')	{if (ch == '-')	f = -1;	ch = getchar ();}
	while (ch >= '0' && ch <= '9')	{x = x * 10 + ch - '0';	ch = getchar ();}
	return x * f;
}

inline void print(int x)
{
	if (x < 0)	{putchar ('-');	x = -x;}
	if (x > 9)	print (x / 10);
	putchar (x % 10 + '0');
}

bool cmp(node x, node y)		
{
	if (x.e == y.e)
		return x.s < y.s;		
	else
		return x.e > y.e;
}

int lowbit(int t)		
{

	return t & (-t);
}

void plus(int x)
{
	while (x <= maxn)
	{
		ans[x]++;				
		x += lowbit (x);
	}
}

int sum(int x)					
{
	int sum = 0;
	while (x > 0)
	{
		sum += ans[x];
		x -= lowbit(x);
	}
	return sum;
}

int main(void)		
{

	int n;

	while (scanf ("%d", &n) && n)
	{
		for (int i=1; i<=n; ++i)
		{
			cow[i].s = read ();	cow[i].e = read ();

			cow[i].id = i;
			maxn = max (maxn, cow[i].e);
		}
		memset (ans, 0, sizeof (ans));
		sort (cow+1, cow+n+1, cmp);
		for (int i=1; i<=n; ++i)
		{
			if (cow[i].e == cow[i-1].e && cow[i].s == cow[i-1].s)		
				cnt[cow[i].id] = cnt[cow[i-1].id];
			else
			{
				cnt[cow[i].id] = sum (cow[i].s + 1);					
			}
			plus (cow[i].s + 1);
		}
		int j;
		for (j=1; j<n; ++j)
		{
			print (cnt[j]);	putchar (' ');

		}
		printf ("%d\n", cnt[j]);
	}

	return 0;
}



