#include <iostream>
#include <queue>
using namespace std;

struct node
{
	__int64 a,b;

	node(){}
	node(__int64 _a,__int64 _b)
	{
		a=_a;
		b=_b;
	}
};

queue<node> Q;
__int64 p[100005],h,a,b,c;

int main()
{
	while(scanf("%I64d",&h)!=-1)
	{
		scanf("%I64d%I64d%I64d",&a,&b,&c);
		if(a>b) swap(a,b);
		node top,next;
		while(!Q.empty()) Q.pop();
		memset(p,-1,sizeof(p));
		p[0]=0;
		Q.push(node(0,0));
		while(!Q.empty())
		{
			top=Q.front();
			Q.pop();
			next=node((top.a+a)%c,top.b+a);
			if(p[next.a]==-1||p[next.a]>next.b)
			{
				p[next.a]=next.b;
				Q.push(next);
			}
			next=node((top.a+b)%c,top.b+b);
			if(p[next.a]==-1||p[next.a]>next.b)
			{
				p[next.a]=next.b;
				Q.push(next);
			}
		}
		__int64 ans=0,i;
		for(i=0;i<c&&i<h;i++) if(p[i]!=-1&&p[i]<h)
			ans+=(h-1-p[i])/c+1;
		printf("%I64d\n",ans);
	}
	return 0;
}


