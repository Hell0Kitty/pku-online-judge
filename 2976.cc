#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1000+200;
int N,K;
int a[maxn],b[maxn];
double d[maxn];
int main()
{
	while(scanf("%d%d",&N,&K)==2)
	{
		if(N==0 && K==0) return 0;
		for(int i=0;i!=N;++i)
			scanf("%d",a+i);
		for(int i=0;i!=N;++i)
			scanf("%d",b+i);
		double L=0,R=1e10;
		while(R-L>1e-6)
		{
			double  ans=0;
			double mid=(L+R)/2.0;
			for(int i=0;i!=N;++i)
			d[i]=a[i]-(mid*b[i]);
			sort(d,d+N,greater<double>());
			for(int i=0;i!=N-K;++i)
				ans+=d[i];
			if(ans>=0) L=mid;
			else R=mid;
		}
		printf("%d\n",int(L*100+0.5));
	}
	return 0;
}



