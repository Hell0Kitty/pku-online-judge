#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <set>
using namespace std;
#define CL(x, v) memset(x, v, sizeof(x));

int n, k, m;

int main() {
  while (~scanf("%d%d%d", &n, &k, &m)) {
    if (n == 0) break;
    int x = 0, i = 2;
    for (; i < n; i++) x = (x + k) % i;
    x = (x + m) % i + 1;
    printf("%d\n", x);
  }
  return 0;
}
