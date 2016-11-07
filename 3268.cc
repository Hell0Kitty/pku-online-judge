#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

const int N = 1005;
int edge[N][N];
int n, e, x;
int mindis1[N];
int mindis2[N];
bool vis1[N];
bool vis2[N];

void init()
{
	for (int i = 0; i < n; ++i) 
	{
		for (int j = 0; j < n; ++j)
		{
			edge[i][j] = -1;
		}
	}
}

void dijkstra(int s)
{
	int pos1, pos2, te1, te2, tm1, tm2;
	for (int i = 0; i < n; ++i) 
	{
		vis1[i] = false;
		vis2[i] = false;
		mindis1[i] = 999999;
		mindis2[i] = 999999;
	}
	mindis1[s] = 0;
	mindis2[s] = 0;
	vis1[s] = true;
	vis2[s] = true;
	pos1 = s;
	pos2 = s;
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (!vis1[j] && edge[pos1][j] != -1 &&  mindis1[pos1] + edge[pos1][j] < mindis1[j])
			{
				mindis1[j] = mindis1[pos1] +edge[pos1][j];
			}
			if (!vis2[j] && edge[j][pos2] != -1 && mindis2[pos2] + edge[j][pos2] < mindis2[j])
			{
				mindis2[j] = mindis2[pos2] + edge[j][pos2];
			}
		}
		tm1 = 999999;
		tm2 = 999999;
		for (int j = 0; j < n; ++j)
		{
			if (!vis1[j] && mindis1[j] < tm1)
			{
				tm1 = mindis1[j];
				te1 = j;
			}
			if (!vis2[j] && mindis2[j] < tm2)
			{
				tm2 = mindis2[j];
				te2 = j;
			}
		}
		vis1[te1] = true;
		pos1 = te1;
		vis2[te2] = true;
		pos2 = te2;
	}
}

int main()
{
	int beg, end, dis;
	scanf("%d%d%d", &n, &e, &x);
	init();
	for (int i = 0; i < e; ++i)
	{
		scanf("%d%d%d", &beg, &end, &dis);
		--beg;
		--end;
		edge[beg][end] = dis;
	}
	dijkstra(--x);
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if (i == x) continue;
		if (mindis1[i] + mindis2[i] > ans) ans = mindis1[i] + mindis2[i];
	}
	printf("%d\n", ans);
	return 0;
}



