#include <iostream>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define mmst(a, b) memset(a, b, sizeof(a))

typedef long long LL;

const int maxn = 3005;

int n;
double c[maxn], mat[maxn][5];

int main()
{
	int i; double tmp;

	scanf("%d", &n);
	scanf("%lf%lf", &c[0], &c[n+1]);
	for (i = 1; i <= n; i++) scanf("%lf", &c[i]);
	mat[0][2] = mat[n+1][2] = 1; 
	mat[0][4] = c[0]; mat[n+1][4] = c[n+1];
	for (i = 1; i <= n; i++)
	{
		mat[i][1] = mat[i][3] = -1.0/2;
		mat[i][2] = 1;
		mat[i][4] = -c[i];
	}
	for (i = 0; i <= n; i++)
	{
		tmp = mat[i+1][1] / mat[i][2];
		mat[i+1][1] -= tmp * mat[i][2];
		mat[i+1][2] -= tmp * mat[i][3];
		mat[i+1][4] -= tmp * mat[i][4];
	}
	for (i = n+1; i > 1; i--)
	{
		tmp = mat[i-1][3] / mat[i][2];
		mat[i-1][3] -= tmp * mat[i][2];
		mat[i-1][4] -= tmp * mat[i][4];
	}
	printf("%.2lf\n", mat[1][4] / mat[1][2]);

	return 0;
}


