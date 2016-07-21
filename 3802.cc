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

bool mp[15][15];
int lim[2][15];
bool vis[2][15];
int cur[2], goal[2];

struct NODE
{
	int flag;
	int ind;
	int h;
	friend bool operator < (const NODE &op1, const NODE &op2)
	{
		return op1.h < op2.h;
	}
};

NODE node[30];

int main()
{
	int w, h;
	while(scanf("%d%d", &w, &h), w && h)
	{
		memset(mp, 0, sizeof(mp));
		memset(vis, 0, sizeof(vis));
		lim[0][0] = w;            
		lim[1][0] = h;	
		int count = 0;
		for(int i = 1; i <= w; ++i)
		{
			scanf("%d", lim[0]+i);
			node[++count].flag = 0;
			node[count].ind = i;
			node[count].h = lim[0][i];
		}

		for(int i = 1; i <= h; ++i)
		{
			scanf("%d", lim[1]+i);
			node[++count].flag = 1;
			node[count].ind = i;
			node[count].h = lim[1][i];
		}

		sort(node+1, node+1+count);
		int ans = 0;
		for(int i = count; i >= 1; --i)
			if(!vis[node[i].flag][node[i].ind])
			{
				int tf = node[i].flag, ti = node[i].ind, th = node[i].h;
				int tlim = lim[tf^1][0];
				cur[tf] = ti;
				goal[tf] = ti;
				int mh = INFI;
				for(int j = 1; j <= tlim; ++j)
					{
						cur[tf^1] = j;
						if(!mp[cur[0]][cur[1]] && th <= lim[tf^1][j]) 
						{
							if(lim[tf^1][j] == th && !vis[tf^1][j])    
							{
								goal[tf^1] = j;
								mh = th;
							}
							else
								if(lim[tf^1][j] < mh)   
								{
									goal[tf^1] = j;
									mh = th;
								}
						}					
					}
				vis[tf^1][goal[tf^1]] = true;
				vis[tf][ti] = true;
				mp[goal[0]][goal[1]] = true;                    
				ans += th;
			}
		printf("%d\n", ans);
	}
	return 0;
}



