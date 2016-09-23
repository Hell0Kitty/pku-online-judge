#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>
#include <ctype.h>
#include <vector>
using namespace std;

const int kMAX=10010;
const double kEPS=10E-6;
vector<int> vec[kMAX];
bool visit[kMAX];
int ans,step[kMAX];

void dfs(const int &x,const int &t)
{
	visit[x]=true;
	step[x]=t;
	for(size_t i=0;i<vec[x].size();++i)
	{
		if(!visit[vec[x][i]])
			dfs(vec[x][i],t+1);
		else
			ans=max(ans,step[vec[x][i]]-step[x]+1);
	}
}

int main(void)
{

  int n,m,ncase=1,u,v;
  scanf("%d",&ncase);

  while(~scanf("%d%d",&n,&m) && n)
  {
    for(int i=1;i<=n;++i)
      vec[i].clear();
		memset(visit,false,sizeof(visit));
		memset(step,0,sizeof(step));
		ans=0;

		while(m--)
		{
			scanf("%d%d",&u,&v);
			vec[u].push_back(v);
			vec[v].push_back(u);
		}

		for(int i=1;i<=n;++i)
			if(!visit[i])
				dfs(i,0);
		printf("%d\n",ans);

  }

  return 0;
}


