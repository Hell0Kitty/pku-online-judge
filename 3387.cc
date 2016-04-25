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
using namespace std;
const double eps(1e-8);
typedef long long lint;
#define clr(x) memset(x, 0, sizeof(x))
#define sz(v) ((int)(v).size())
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repf(i, a, b) for (int i = (a); i <= (b); ++i)
#define repd(i, a, b) for (int i = (a); i >= (b); --i)
#define clrs(x, y) memset(x, y, sizeof(x))
bool bj[110000];
int jl[110000];
bool mul[110000];
int s[110000];
int e[110000];
int first[110000], last[110000], vv[110000];
int n, m, ans, top, dtop;
void insert(int a, int b) {
  dtop++;
  e[dtop] = b;
  if (first[a] == 0)
    last[a] = first[a] = dtop;
  else {
    vv[last[a]] = dtop;
    last[a] = dtop;
  }
}
void dfs(int i) {
  if (bj[i]) return;
  bj[i] = top;
  if (s[i] % 2) jl[top]++;
  if (s[i] > 2) {
    ans++;
    mul[top] = true;
  }
  for (int j = first[i]; j != 0; j = vv[j]) dfs(e[j]);
}
int solve() {
  if (top == 1) {
    return ans + jl[1] / 2;
  } else {
    repf(i, 1, top) {
      if (jl[i] == 0 && mul[i]) continue;
      if (jl[i] == 0)
        ans++;
      else
        ans += jl[i] / 2 - 1;
    }
    ans += top;
  }
  return ans;
}
int main() {
  while (scanf("%d %d", &n, &m) == 2) {
    ans = 0;
    clr(jl);
    clr(mul);
    dtop = 0;
    clr(s);
    clr(e);
    clr(vv);
    clr(first);
    clr(last);
    int have = n;
    repf(i, 1, m) {
      int a, b;
      scanf("%d %d", &a, &b);
      if (a == 0) a = ++have;
      if (b == 0) b = ++have;
      s[a]++;
      s[b]++;
      insert(a, b);
      insert(b, a);
    }
    n = have;
    top = 0;
    clr(bj);
    repf(i, 1, n) {
      if (s[i] == 0) continue;
      if (!bj[i]) {
        top++;
        dfs(i);
      }
    }
    printf("%d\n", solve());
  }
}
