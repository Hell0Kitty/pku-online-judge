#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <utility>
#define M0(x) memset(x, 0, sizeof(x))
#define Inf 0x7fffffff
#define PB push_back
#define SZ(v) ((int)(v).size())
using namespace std;
int a[100010];

int main() {
  long long n;
  while (cin >> n && n) {
    if (n == 2) {
      puts("Impossible");
      continue;
    }
    M0(a);
    for (long long i = 1; i < n; ++i) a[i * i % n] = 1;
    for (int i = 1; i < n; ++i) cout << 1 - a[i];
    cout << endl;
  }
  return 0;
}
