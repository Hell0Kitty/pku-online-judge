#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define MAXN 140000
#define MOD 1000000009
#define INF 100000000000000
#define cleararr(a, b) memset(a, b, sizeof(a));

int offset[5][2] = {{-1, 0}, {0, -1}, {1, -1}, {1, 0}, {0, 1}};

pair<int, int> maja[MAXN];
int main() {
  for (int i = 1, j = 1, k = 0; k <= 190; i += j, j += 6, k++) {
    maja[i] = make_pair(0, k);
    for (int m = 0; m < k; m++) maja[i - m] = make_pair(m, k - m);
    int c = i;
    for (int m = 0; m < 5; m++) {
      for (int n = 0; n < k; n++) {
        int x = maja[c].first + offset[m][0];
        int y = maja[c].second + offset[m][1];
        maja[++c] = make_pair(x, y);
      }
    }
  }
  int n;
  while (cin >> n) {
    cout << maja[n].first << " " << maja[n].second << endl;
  }
  return 0;
}
