#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>

using namespace std;

const double pi = acos(-1.0);
const double eps = 1E-7;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
#define sqr(x) ((x)*(x))
#define Abs(x) ((x) < 0 ? (-(x)) : (x))
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define ME(a) memset((a), 0, sizeof((a)))
#define MM(a, b) memcpy((a), (b), sizeof((a)))
#define FOR(i,n) for (int (i) = 0; (i) < (n); ++(i))
#define REP(i,a,b) for (int (i) = (a); (i) < (b); ++(i))

int64 n;

int main()
{
 int Tests;
 for (scanf("%d", &Tests); Tests--; ) {
 scanf("%I64d", &n);
 if (!(n % 5)) n /= 5; else n = n / 5 + 1;

 int64 ans = n * 1000, ax, ay, tans = ans;
 for (int64 o = 1; o * o <= n; ++o)
 {
 int64 x = o;
 int64 y = n / x; if (n % x) ++y;
 int64 tmp = (x * 8 + (x + 1) * 2) * (y * 40 + (y + 1) * 4);
 int64 ww = Abs((x * 8 + (x + 1) * 2) - (y * 40 + (y + 1) * 4));
 if (tmp < ans || tmp == ans && ww < tans) {
 ans = tmp;
 tans = ww;
 ax = y * 40 + (y + 1) * 4; ay = x * 8 + (x + 1) * 2;
 }
 swap(x, y);
 tmp = (x * 8 + (x + 1) * 2) * (y * 40 + (y + 1) * 4);
 ww = Abs((x * 8 + (x + 1) * 2) - (y * 40 + (y + 1) * 4));
 if (tmp < ans || tmp == ans && ww < tans) {
 ans = tmp;
 tans = ww;
 ax = y * 40 + (y + 1) * 4; ay = x * 8 + (x + 1) * 2;
 }
 }
 if (ax < ay) swap(ax, ay);
 printf("%I64d X %I64d = %I64d\n", ax, ay, ans);
 }
 return 0;
}


