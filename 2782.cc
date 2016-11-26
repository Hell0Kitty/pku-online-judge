#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int w[100010];
bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	int n, m;
	while (cin>>n>>m)
	{
		int ans=0;
		//scanf("%d%d", &n,&m);
		for (int i = 0; i < n; i++)
			scanf("%d", &w[i]);
		sort(w, w + n,cmp);
		int i = 0, j = n - 1;
		while (i <= j)
		{
			if (i == j)
			{
				ans++;
				break;
			}
			if (w[i] + w[j] <= m)
				j--;
			i++;
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}


