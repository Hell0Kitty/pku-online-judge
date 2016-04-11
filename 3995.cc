#include <vector>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <string>
#include <cassert>
using namespace std;
#define inf 2000000000
#define ll __int64
#define add 10009
int f_min(int x, int y) { return x < y ? x : y; }
int f_max(int x, int y) { return x > y ? x : y; }
int f_abs(int x) {
  if (x < 0) x = -x;
  return x;
}
char s[110];
void swap1(int x, int y) {
  char c;
  c = s[x];
  s[x] = s[y];
  s[y] = c;
}
void swap2(int x, int y) {
  char c;
  if (s[y] == 'B')
    s[y] = 'W';
  else
    s[y] = 'B';
  c = s[x];
  s[x] = s[y];
  s[y] = c;
}
int len;
int ans;
bool cheak() {
  int i;
  bool flag1 = false;
  bool flag2 = false;
  for (i = 0; s[i]; i++) {
    if (!flag1 && s[i] == 'B') flag1 = true;
    if (flag1 && (s[i] == 'W')) flag2 = true;
    if (flag2 && s[i] == 'B') return false;
  }
  return true;
}
void f(int pre, int x, int step) {
  int i;
  int tx;
  if (step >= ans) return;

  if (pre != 1 && pre != -1 && cheak()) {
    ans = step;
    return;
  }
  if (step >= 9) return;
  if (pre != 1 && x - 1 >= 0) {
    swap1(x, x - 1);
    f(-1, x - 1, step + 1);
    swap1(x, x - 1);
  }
  if (pre != -1 && x + 1 < len) {
    swap1(x, x + 1);
    f(1, x + 1, step + 1);
    swap1(x, x + 1);
  }
  if (pre != 2 && x - 2 >= 0) {
    swap2(x, x - 2);
    f(-2, x - 2, step + 1);
    swap2(x - 2, x);
  }
  if (pre != -2 && x + 2 < len) {
    swap2(x, x + 2);
    f(2, x + 2, step + 1);
    swap2(x + 2, x);
  }
}

int main() {
  int n, m, cas = 0, u, v, x, y;
  while (~scanf("%s", s), s[0] - '-') {
    len = strlen(s);
    for (int i = 0; s[i]; i++) {
      if (s[i] == 'F') {
        x = i;
        break;
      }
    }
    ans = 10;
    f(-222, x, 0);
    if (ans == 10) ans = -1;
    printf("%d. %d\n", ++cas, ans);
  }
  return 0;
}
