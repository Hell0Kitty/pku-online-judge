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
const LL INF = 1e9;
const int N = 2e5;
LL check(int n, int b1, int b2)
{
	LL ret = 0;
	LL t = 1;
	int x = n;
	while (x)
	{
		ret += x%b1*t;
		x /= b1;
		t *= b2;
	}
	return ret%n == 0;
}
int main()
{
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int b1, b2;
		int r1, r2;
		cin >> b1 >> b2 >> r1 >> r2;
		int ans = r1;
		for (int i = r1 + 1; i < r2; i++)
		{
			if (check(i, b1, b2))
			{
				ans = i;
			}
		}
		if (ans == r1) cout << "Non-existent." << endl;
		else cout << ans << endl;
	}
	return 0;

}



