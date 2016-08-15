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
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MEM(a, b) memset((a), (b), sizeof(a))
const int N = 1001;
vector<int> v[N];
int flag[N];
int np[N];
int n, k;

int getans(int x) {
  flag[x] = 1;
  if (np[x] != -1) return np[x];
  int f = 0;
  for (int i = 0; i < v[x].size(); i++) {
    if (!flag[v[x][i]]) {
      if (!getans(v[x][i])) {
        f = 1;
      }
    }
  }
  return np[x] = f;
}
int main() {
  while (cin >> n >> k) {
    int x, y;
    for (int i = 1; i <= n; i++) {
      v[i].clear();
    }
    for (int i = 1; i < n; i++) {
      cin >> x >> y;
      v[x].push_back(y);
      v[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
      sort(v[i].begin(), v[i].end());
    }
    MEM(flag, 0);
    MEM(np, -1);
    if (getans(k)) {
      for (int i = 0; i < v[k].size(); i++) {
        if (np[v[k][i]] == 0) {
          cout << "First player wins flying to airport " << v[k][i] << endl;
          break;
        }
      }
    } else
      cout << "First player loses" << endl;
  }
  return 0;
}
