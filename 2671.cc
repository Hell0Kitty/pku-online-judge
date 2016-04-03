#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define OO 1000000000

using namespace std;

int n, i, j, k;
int f1[305], f2[305];
int Left[305][305], Right[305][305], w[305][305];
int Time[305], Val[305];

void Work(int n);

int main()
{
	while (1)
	{
		scanf("%d", &n);
		if (n == 0)
			break;
		for (i = 0; i < n; i ++)
			scanf("%d %d", &Val[i], &Time[i]);
		Val[n] = Time[n] = 0, n++;
		Work(n);
		for (k = 1; k < n; k++)
		{
			for (i = 0; i + k < n; i++)
			{
				j = i + k;
				Left[i][j] = min(Left[i + 1][j] + Time[i] * w[i + 1][j], Right[i + 1][j] + (f2[i] + f1[j]) * w[i + 1][j]);
				Right[i][j] = min(Right[i][j - 1] + Time[j - 1] * w[i][j - 1], Left[i][j - 1] + (f2[i] + f1[j]) * w[i][j - 1]);
			}
		}

		printf("%d\n", min(Left[0][n - 1], Right[0][n - 1]));
	}

	return 0;
}

void Work(int n)
{
	int i, j;
	f2[0] = 0;
	for (i = 1; i < 305; i ++)
		f2[i] = f2[i - 1] + Time[i - 1];
	f1[n] = 0;
	for (i = n - 1; i >= 0; i--)
		f1[i] = f1[i+1] + Time[i];
	for (i = 0; i < n; i ++)
	{
		w[i][i] = Val[i];
		for (j = i + 1; j < n; j ++)
			w[i][j] = w[i][j - 1] + Val[j];
	}

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (i == j)
				Left[i][j] = Right[i][j] = 0;
			else
				Left[i][j] = Right[i][j] = OO;
	return;
}
