#include <cstring>
#include <cstdio>
#include <cmath>

double cost[5][4] = {
	0.02, 0.10, 0.06, 0.02,
	0.05, 0.25, 0.15, 0.05,
	0.13, 0.53, 0.33, 0.13,
	0.17, 0.87, 0.47, 0.17,
	0.30, 1.44, 0.80, 0.30};

int used[1440];
int	sums[5];
int cut[5] = {0,480,1080,1320,1440};

int main()
{
	char ch,str[10];
	int  a,b,c,d;
	while (~scanf("%c",&ch) && ch != '#') {
		scanf("%s%d%d%d%d",str,&a,&b,&c,&d);
		getchar();
		memset(used, 0, sizeof(used));
		if (c*60+d <= a*60+b) {//0小时代表24小时 
			for (int i = 0 ; i < c*60+d ; ++ i)
				used[i] = 1;
			for (int i = a*60+b ; i < 1440 ; ++ i)
				used[i] = 1;
		}else
			for (int i = a*60+b ; i < c*60+d ; ++ i)
				used[i] = 1;

		for (int i = 0 ; i < 4 ; ++ i) {
			sums[i] = 0;
			for (int j = cut[i] ; j < cut[i+1] ; ++ j)
				sums[i] += used[j];
		}
		sums[3] += sums[0];
		double sum = sums[1]*cost[ch-'A'][1]+sums[2]*cost[ch-'A'][2]+sums[3]*cost[ch-'A'][3];

		printf("%10s%6d%6d%6d%3c%8.2lf\n",str,sums[1],sums[2],sums[3],ch,sum);
	}
    return 0;
}


