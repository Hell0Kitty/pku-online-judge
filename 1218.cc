#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{
	int T,n,m;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		m=(int)sqrt(n);
		printf("%d\n",m);

	}
	return 0;
}


