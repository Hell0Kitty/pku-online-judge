#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define inf 0x3f3f3f3f
#define maxn 70

struct Point
{
	int x, y;
} king, knight[maxn];

char st[256];
int dist[10][10][10][10];
int n;

void floyd()
{
	for (int i =0; i <8; i++)
	for (int j =0; j <8; j++)
	for (int k =0; k <8; k++)
	for (int l =0; l <8; l++)
	if ((abs(i - k) ==1&& abs(j - l) ==2) || (abs(i - k)
		==2&& abs(j - l) ==1))
		dist[i][j][k][l] =1;
	else
		dist[i][j][k][l] = inf;
	for (int i =0; i <8; i++)
		for (int j =0; j <8; j++)
			dist[i][j][i][j] =0;
	for (int i =0; i <64; i++)
		for (int j =0; j <64; j++)
			for (int k =0; k <64; k++)
			{
				int x1, x2, x3, y1, y2, y3;
				x1 = i /8;
				x2 = j /8;
				x3 = k /8;
				y1 = i %8;
				y2 = j %8;
				y3 = k %8;
				dist[x2][y2][x3][y3] = min(dist[x2][y2][x3][y3],
				dist[x2][y2][x1][y1] + dist[x1][y1][x3][y3]);
			}
}

void make()
{
	king.x = st[0] -'A';
	king.y = st[1] -'1';
	for (int i =2; i < strlen(st); i +=2)
	{
		int d = i /2-1;
		knight[d].x = st[i] -'A';
		knight[d].y = st[i +1] -'1';
	}
	n = strlen(st) /2-1;
}

void work()
{
	if (n ==0)
	{
		printf("0\n");
		return;
	}
	int ans = inf;
	for (int i =0; i <64; i++)
	{
		int x = i /8;
		int y = i %8;
		int sum =0;
		for (int j =0; j < n; j++)
			sum += dist[x][y][knight[j].x][knight[j].y];
		for (int j =0; j <64; j++)
		{
			Point cross;
			cross.x = j /8;
			cross.y = j %8;
			int temp1 = max(abs(king.x - cross.x), abs(king.y - cross.y));
			int temp2 = inf;
			for (int k =0; k < n; k++)
				temp2 = min(temp2, dist[x][y][cross.x][cross.y]
			+ dist[cross.x][cross.y][knight[k].x][knight[k].y]
			- dist[x][y][knight[k].x][knight[k].y]);
			ans = min(ans, temp1 + temp2 + sum);
		}
	}
	printf("%d\n", ans);
}

int main()
{
	scanf("%s", st);
	floyd();
	make();
	work();
	return 0;
}


