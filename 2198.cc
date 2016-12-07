#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <sstream>

using namespace std;

#define REP(i, s, t) for (int i = (s); i < (t); i++)
#define FOREACH(i, v) \
  for (typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
typedef long long ll;

int N;
ll steps;
char line[1000];

vector<int> wanted;

void apply(const vector<int> &v, vector<int> &w, int a) {
  w[0] = w[N - 1] = false;
  REP(i, 1, N - 1) {
    int t = v[i + 1] + 2 * v[i] + 4 * v[i - 1];
    w[i] = (a >> t) & 1;
  }
}

int main() {
  for (int test = 1;; test++) {
    if (scanf("%lld ", &steps) != 1) break;
    scanf("%s ", line);
    bool ok = true;
    N = strlen(line);
    wanted.assign(N, 0);
    REP(i, 0, N) {
      if (line[i] != 'W' && line[i] != 'B') ok = false;
      wanted[i] = line[i] == 'B';
    }
    if (N % 2 == 0) ok = false;
    if (wanted[0] || wanted[N - 1]) ok = false;
    bool found = false;
    printf("LINE %d", test);
    if (ok) {
      REP(a, 0, 256) {
        vector<int> v1(N, false);
        v1[N / 2] = true;
        ll step = 0;
        vector<int> v2 = v1, w = v1;
        while (step + 1 <= steps) {  // TODO
          if (v1 == wanted) {
            printf(" (%d,%lld)", a, step + 1);
            found = true;
            break;
          }
          if (v1 == v2 && step) break;
          apply(v1, w, a);
          v1 = w;
          apply(v2, w, a);
          apply(w, v2, a);
          step++;
        }
      }
    }
    if (!found) printf(" NONE");
    printf("\n");
  }
  return 0;
}
