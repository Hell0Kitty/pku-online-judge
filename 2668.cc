#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
	int d,n;
	while (scanf("%d%d",&d,&n)>0,d||n)
	{
		long long sum=0;
		int tmp=(int)ceil(d/(n*1.0));
		int tmp1=n-(int)ceil(d/(tmp*1.0))+1;
		if (tmp1>=1) sum+=tmp1*tmp;
		int last=(int)ceil(d/(tmp*1.0));

		while (true)
		{
			if (last-1<=0) break;
			tmp=(int)ceil(d/((last-1)*1.0));

			tmp1=(last-(int)ceil(d/(tmp*1.0)));
			if (tmp1>=1) sum+=tmp*tmp1;
			last=ceil(d/(tmp*1.0));
			if (tmp>=d) break;
		}
		printf("%lld\n",sum);
	}
}



