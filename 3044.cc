#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <queue>
#define r 500005
using namespace std;
struct data
{
	int y;
	bool operator <(const data &A)const
	{
		return A.y>y;
	}
};
priority_queue<data> q;
int n,w,ok[r];
int main()
{
	scanf("%d%d",&n,&w);
	for (int i=1;i<=500000;i++)
	   ok[i]=1;
	int ans=n;
	for (int i=1;i<=n;i++)
	{
	   int x,y; 
	   scanf("%d%d",&x,&y);
	   if (!q.empty())
	   {
		   data p=q.top();
	       while (p.y>y)
	       {
			   ok[p.y]=1;
	   	       q.pop();
		       if (q.empty()) break;
	   	       p=q.top();
		   }
	   }
	   data e;
	   e.y=y;
	   if (ok[y]) q.push(e),ok[y]=0;
	   else ans--;
    }
    cout<<ans<<endl;
	return 0;
}


