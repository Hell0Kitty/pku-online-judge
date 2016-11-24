#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 1005
struct ele
{
	int a,b;
	bool operator < (const ele &c) const
	{
		if(a==c.a)
		{
			if(abs(b)==abs(c.b))
				return b>c.b;
			else
				return abs(b)<abs(c.b);
		}
		else
			return a<c.a;
	}
}e[MAXN];
int up;
void get(int p)
{
	if((p-3)%4==0) e[up].a=p,e[up++].b=0;
	else
	{
		for(int i=1;i*i<=p;i++)
		{
			int j=sqrt(1.0*(p-i*i));
			if(i*i+j*j==p)
			{
				e[up].a=i,e[up++].b=j;
				e[up].a=i,e[up++].b=-j;
				break;
			}
		}
	}
}
int main()
{
	int cas=1,n;
	while(scanf("%d",&n)!=EOF)
	{
		up=0;
		for(int i=2;i*i<=n;i++)
			if(n%i==0)
			{
				get(i);
				while(n%i==0) n/=i;
			}
		if(n>1) get(n);
		sort(e,e+up);
		printf("Case #%d:",cas++);
		for(int i=0;i<up;i++)
		{
			printf(" %d",e[i].a);
			if(e[i].b<0)
			{
				if(e[i].b==-1) printf("-j");
				else printf("%dj",e[i].b);
			}
			else if(e[i].b>0)
			{
				if(e[i].b==1) printf("+j");
				else printf("+%dj",e[i].b);
			}
			if(i<up-1) printf(",");
		}
		printf("\n");
	}
	return 0;
}


