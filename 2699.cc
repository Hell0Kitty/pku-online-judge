#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<sstream>
#include<string>
using namespace std;

const int MAXN = 210;
const int MAXM = 41000;
const int INF = 0x3f3f3f3f;

struct Edge
{
	int from, to, cap, next;
};

Edge edge[MAXM];
int level[MAXN];
int head[MAXN];
int score[MAXN];
int bigger[MAXN];
int src, des, cnt;

void addedge( int from, int to, int cap )
{
	edge[cnt].from = from;
	edge[cnt].to = to;
	edge[cnt].cap = cap;
	edge[cnt].next = head[from];
	head[from] = cnt++;

	swap( from, to );

	edge[cnt].from = from;
	edge[cnt].to = to;
	edge[cnt].cap = cap;
	edge[cnt].next = head[from];
	head[from] = cnt++;
}

int bfs()
{
	memset( level, -1, sizeof level );
	queue<int> q;
	while (!q.empty())
		q.pop();
	level[src] = 0;
	q.push( src );

	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = head[u]; i != -1; i = edge[i].next)
		{
			int v = edge[i].to;
			if (edge[i].cap&&level[v] == -1)
			{
				level[v] = level[u] + 1;
				q.push( v );
			}
		}
	}
	return level[des] != -1;
}

int dfs( int u, int f )
{
	if (u == des) return f;

	int tem;
	for (int i = head[u]; i != -1; i = edge[i].next)
	{
		int v = edge[i].to;
		if (edge[i].cap&&level[v] == level[u] + 1)
		{
			tem = dfs( v, min( f, edge[i].cap ) );
			if (tem > 0)
			{
				edge[i].cap -= tem;
				edge[i ^ 1].cap += tem;
				return tem;
			}
		}
	}
	level[u] = -1;
	return 0;
}

int Dinic()
{
	int ans = 0, tem;

	while (bfs())
	{
		while (tem = dfs( src, INF ))
		{
			ans += tem;

		}
	}
	return ans;
}

int main()
{
	int kase;
	cin >> kase;
	getchar();
	src = 0; des = 105;

	while (kase--)
	{
		int n = 0;
		string str;
		getline( cin, str );
		stringstream ss( str );
		int sc;

		while (ss >> sc)
		{
			score[++n] = sc;
		}
		bigger[n] = 0;
		for (int i = n - 1; i >= 1; i--)
		{
			if (score[i] == score[i + 1]) bigger[i] = bigger[i + 1];
			else bigger[i] = n - i;
		}

		int start;
		for ( start = 1; start <= n; start++)
		{
			if (score[start] >= bigger[start])break;
		}

		int low = start, high = n;
		int ans = start;
		while(low<=high)
		{
			int mid = (low + high) / 2;
			memset( head, -1, sizeof head );
			cnt = 0;
			int match = 0;
			for (int i = 1; i <= n; i++)
			{
				addedge( src, i, score[i] );
			}

			for (int i = 1; i <= n; i++)
			{
				for (int j = i+1; j <= n; j++)
				{
					if (i >= mid&&score[j] > score[i])
						addedge( i, (++match) + 50, 1 );
					else
					{
						addedge( i, (++match) + 50, 1 );
						addedge( j, match + 50, 1 );
					}
				}
			}

			for (int i = 1; i <= match; i++)
			{
				addedge( i + 50, des, 1 );
			}

			if (Dinic() < (n*(n-1))/2) low = mid + 1;
			else
			{
				ans = mid;
				high = mid - 1;
			}
		}

		cout << n - ans + 1 << endl;
	}
	return 0;
}



