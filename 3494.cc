#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef __int64 int64;
typedef long long ll;
#define M 50005
#define N 1000005
#define max_inf 0x7f7f7f7f
#define min_inf 0x80808080
#define mod 1000000007

int m , n , top;
int q[2005] , lef[2005] , rig[2005];

int main()
{
	int h[2005];
	int ans;
	while (~scanf("%d%d",&m,&n))
	{
		int i , j;
		ans = 0;
		memset(h , 0 , sizeof h);
		for (i = 0 ; i < m ; i++)
		{
			top = 0;
			for (j = 0 ; j < n ; j++)
			{
				int x;
				scanf("%d",&x);
				h[j]++;
				h[j] = x ? h[j] : 0;
				while (top > 0 && h[q[top-1]] > h[j])
				{
					rig[q[top-1]] = j-1;
					top--;
				}
				if (top <= 0)lef[j] = 0;
				else lef[j] = q[top-1]+1;
				q[top++] = j;
			}
			while (top)rig[q[top-1]] = n-1,top--;

			for (j = 0 ; j < n ; j++)
			{
				int temp = (rig[j]-lef[j]+1)*h[j];
				ans = max(ans,temp);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}



