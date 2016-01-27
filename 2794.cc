#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e4 + 1;
const LL N = 5e4 + 10;
const double eps = 1e-11;
map<vector<int>, double> mv;
vector<string> vs[9];
double dfs(vector<int>& v)
{
	if (mv.count(v))
		return mv[v];
	int cnt = 0;
	double sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == 0) continue;
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[j] == 0) continue;
			if (vs[i][v[i] - 1][0] == vs[j][v[j] - 1][0])
			{
				v[i]--;
				v[j]--;
				sum += dfs(v);
				cnt++;
				v[i]++;
				v[j]++;
			}
		}
	}
	if (cnt == 0) return mv[v] = 0;
	else return mv[v] = sum / cnt;
}

int main()
{
	for (int i = 0; i < 9; i++) vs[i].resize(4);
	while (cin >> vs[0][0] >> vs[0][1] >> vs[0][2] >> vs[0][3])
	{
		for (int i = 1; i < 9; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cin >> vs[i][j];
			}
		}
		mv.clear();
		mv[vector<int>(9,0)] = 1;
		vector<int> v(9, 4);
		printf("%.9f\n", dfs(v));
	}
	return 0;

}



