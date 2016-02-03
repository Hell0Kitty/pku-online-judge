#include <stdio.h>
#include <math.h>
#define MAXN 1000
typedef struct nDate
{
	double x, y;
}nNode;
nNode nP[MAXN];
int nNum;
double ans;
double funcSolve();
double procGetArea(int i, int j, int k);
int main()
{
	int i;
	while (1 == scanf("%d", &nNum), nNum)
	{
		for (i = 0; i != nNum; ++i)
		{
			scanf("%lf %lf", &nP[i].x, &nP[i].y);
		}
		printf("%.lf\n", funcSolve() / 2);
	}
	return 0;
}
double funcSolve()
{
	int i;
	double nArea = 0;
	if (nNum < 3) return 0;
	nNum -= 2;
	for (i = 0; i != nNum; ++i)
	{
		nArea += procGetArea(0, i + 1, i + 2);
	}
	if (nArea < 0) nArea = - nArea;
	return nArea;
}
double procGetArea(int i, int j, int k)
{
	double s = (nP[k].y - nP[i].y) * (nP[j].x - nP[i].x) - (nP[j].y - nP[i].y) * (nP[k].x - nP[i].x);   
    return s;  
}


