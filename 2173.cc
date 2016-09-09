#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <cctype>
#include <utility>   
#include <map>
#include <string>  
#include <climits> 
#include <set>
#include <string> 
#include <sstream>
#include <utility>
#include <ctime>

using std::priority_queue;
using std::vector;
using std::swap;
using std::stack;
using std::sort;
using std::max;
using std::min;
using std::pair;
using std::map;
using std::string;
using std::cin;
using std::cout;
using std::set;
using std::queue;
using std::string;
using std::istringstream;
using std::make_pair;
using std::greater;

const int INFI((INT_MAX-1) >> 1);

int x[110], y[110];
int ax[110];
int ta[110];

int main()
{
	int w, h, n;
	while(~scanf("%d%d%d", &n, &w, &h))
	{
		int tn = 0;
		for(int i = 1; i <= n; ++i)
		{
			scanf("%d%d", x+i, y+i);
			ax[++tn] = x[i];
		}
		ax[++tn] = 0;
		ax[++tn] = w;
		sort(ax+1, ax+1+tn);
		ax[0] = -1;
		int count = 0;
		for(int i = 1; i <= tn; ++i)
			if(ax[i] != ax[i-1])
				ax[++count] = ax[i];
		int ans = 0;
		int gx = 0, gy = 0;
		for(int i = 1; i <= count; ++i)
			for(int j = i+1; j <= count; ++j)
			{
				ta[1] = 0;
				ta[2] = h;
				int tc = 2;
				for(int k = 1; k <= tn; ++k)
					if(x[k] > ax[i] && x[k] < ax[j])
						ta[++tc] = y[k];
				sort(ta+1, ta+1+tc);
				int mx = 0;
				int ty1, ty2;
				for(int k = 2; k <= tc; ++k)
				{
					int temp = ta[k]-ta[k-1];
					if(temp > mx)
					{
						mx = temp;
						ty1 = ta[k-1];
						ty2 = ta[k];
					}
				}
				int temp = min(ax[j]-ax[i], mx);
				if(temp > ans)
				{
					ans = temp;
					gx = ax[i];
					gy = ty1;
				}
			}
		printf("%d %d %d\n", gx, gy, ans);
	}
	return 0;
}



