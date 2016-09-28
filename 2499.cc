#include<cstdio>
int n, m, tn, l, r, cnt, tcase = 0;
int main()
{
	for (scanf("%d", &tn); tn--; l = r = 0)
	{
		scanf("%d %d", &n, &m);
		while (n>1 || m>1)
			if (n > m)
				l += (n - 1) / m, n -= n - (n - 1) % m, ++n;
			else
				r += (m - 1) / n, m -= m - (m - 1) % n, ++m;
		printf("Scenario #%d:\n%d %d\n\n", ++tcase, l, r);
	}
}


