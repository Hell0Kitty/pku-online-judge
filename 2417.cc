#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<time.h>
#include<string>
#define cl(a,b)	memset(a,b,sizeof(a))
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define REP2(i,a,b) for(int i=a;i>=b;--i)
#define MP make_pair
#define LL long long
#define ULL unsigned long long
#define X first
#define Y second
#define MAXN 100050
using namespace std;
int p,b,n;
struct node
{
	int a,id;
}q[MAXN];
bool cmp(node a,node b)
{
	return a.a<b.a||(a.a==b.a&&a.id<b.id);
}
int qmod(int a,int b,int c)
{
	int res=1;
	while(b)
	{
		if(b&1)
			res=((LL)res*a)%c;
		a=((LL)a*a)%c;
		b>>=1;
	}
	return res;
}
int main()
{
	while(scanf("%d%d%d",&p,&b,&n)!=EOF){
		int m=sqrt(p*1.0);
		while(m*m<p)m++;
		int res=1;
		int tail=0;
		int a=qmod(b,m,p);
		for(int i=0;i<=m;++i)
		{
			q[tail].id=i;
			q[tail++].a=res;
			res=((LL)res*b)%p;
		}
		sort(q,q+tail,cmp);
		int h=0;
		for(int i=0;i<tail;++i)
		{
			if(i==0||q[i].a!=q[i-1].a)
			{
				q[h++]=q[i];
			}
		}

		int flag=0,ans;
		res=n;
		int ra=qmod(a,p-2,p);
		for(int i=0;i<=m;++i)
		{
			int l=0,r=h-1;
			while(r-l>1)
			{
				int mid=(l+r)>>1;
				if(q[mid].a>res)r=mid;
				else l=mid;
			}
			int pos=-1;
			if(q[l].a==res)pos=l;
			if(q[r].a==res)pos=r;
			if(pos!=-1){
				ans=i*m+q[pos].id;
				flag=1;
				break;
			}
			res=((LL)res*ra)%p;
		}
		if(flag==0)puts("no solution");
		else
			printf("%d\n",ans);
	}

}



