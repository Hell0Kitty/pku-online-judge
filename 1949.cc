#include <cstdio>
#include <cstdlib>
#include <list>
#include <cstring>
using namespace std;
const int MAX = 10010;
int			weight[ MAX ];
int			n,stacki;
int		main()
{
	int		mid,max,value,single;
	max = -1;
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; ++i )
	{
		scanf("%d%d",&value,&mid);
		weight[i] = value;
		for( int j = 0 ; j != mid ; ++j )
		{
			scanf("%d",&single);
			if( weight[i] < weight[single] + value )
				weight[i] = weight[single] + value;
		}
		if( weight[i] > max )
			max = weight[i];
	}
	printf("%d\n",max);
	return 0;
}



