#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<iomanip>
#include<string>
#include<algorithm>
#include<ctime>
#include<stack>
#include<queue>
#include<vector>
#define N 105
using namespace std;
int m,n,ans,d;
int map[N][N],dir[4][2]={1,0,-1,0,0,1,0,-1};
bool legal(int x,int y)
{if(x>=1&&x<=m&&y>=1&&y<=n) return true;return false;}
void DFS(int x,int y)
{
	int i,sx,sy;
	map[x][y]=1;
	d++;
	for(i=0;i<4;i++)
	{
		sx=x+dir[i][0];sy=y+dir[i][1];
		if(legal(sx,sy)&&(!map[sx][sy]))
			DFS(sx,sy);
	}
	if(d>ans) ans=d;
}
int main()
{
       int i,j,x,y,k;
	   while(cin>>m>>n>>k)
		{
			memset(map,1,sizeof(map));
			while(k--)
			{
                  cin>>x>>y;
                  map[x][y]=0;         
             }
            ans=0;
			for(i=1;i<=m;i++)
			{
				for(j=1;j<=n;j++)
				{
					if(!map[i][j])
					{
						d=0;
                        DFS(i,j);
					}
				}
			}
			cout<<ans<<endl;
		}
		return 0;
}



