#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <cctype>
#include <utility>
#include <map>
#include <string>
#include <climits>
#include <set>
#include <string>
#include <sstream>
#include <utility>
#include <ctime>

using std::priority_queue;
using std::vector;
using std::swap;
using std::stack;
using std::sort;
using std::max;
using std::min;
using std::pair;
using std::map;
using std::string;
using std::cin;
using std::cout;
using std::set;
using std::queue;
using std::string;
using std::istringstream;
using std::make_pair;
using std::getline;
using std::greater;
using std::endl;

typedef long long LL;

const int MAXN((1 << 10) + 5);
int N;

void subs_1(int (*ma1)[MAXN], int (*ma2)[MAXN], bool flag) {
  memcpy(ma1, ma2, sizeof(ma2[0]) * N);
}

void subs_2(int (*ma1)[MAXN], int (*ma2)[MAXN], bool flag) {
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      if (flag)
        ma1[N - j - 1][i] = ma2[i][j];
      else
        ma1[i][j] = ma2[N - j - 1][i];
}

void subs_3(int (*ma1)[MAXN], int (*ma2)[MAXN], bool flag) {
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j) ma1[i][N - j - 1] = ma2[i][j];
}

void subs_4(int (*ma1)[MAXN], int (*ma2)[MAXN], bool flag) {
  memcpy(ma1, ma2, sizeof(ma2[0]) * N);
  for (int i = N / 2; i < N; ++i)
    for (int j = 0; j < N; ++j) ma1[i][N - j - 1] = ma2[i][j];
}

void subs_5(int (*ma1)[MAXN], int (*ma2)[MAXN], bool flag) {
  memcpy(ma1, ma2, sizeof(ma2[0]) * N);
  int temp = N / 2;
  for (int i = N / 2; i < N; ++i)
    for (int j = 0; j < N; ++j) ma1[N - i - 1 + temp][j] = ma2[i][j];
}

void subs_6(int (*ma1)[MAXN], int (*ma2)[MAXN], bool flag) {
  int ti = 0;
  for (int i = 0; i < N; i += 2, ++ti)
    for (int j = 0; j < N; ++j)
      if (flag)
        ma1[ti][j] = ma2[i][j];
      else
        ma1[i][j] = ma2[ti][j];
  ti = N / 2;
  for (int i = 1; i < N; i += 2, ++ti)
    for (int j = 0; j < N; ++j)
      if (flag)
        ma1[ti][j] = ma2[i][j];
      else
        ma1[i][j] = ma2[ti][j];
}

void subs_7(int (*ma1)[MAXN], int (*ma2)[MAXN], bool flag) {
  int tj;
  for (int i = 0; i < N; i += 2) {
    tj = 0;
    for (int j = 0; j < N; tj += j & 1, ++j)
      if (flag)
        ma1[i][j] = ma2[i ^ (j & 1)][tj];
      else
        ma1[i ^ (j & 1)][tj] = ma2[i][j];
  }
  for (int i = 1; i < N; i += 2) {
    tj = N / 2;
    for (int j = 0; j < N; tj += j & 1, ++j)
      if (flag)
        ma1[i][j] = ma2[i ^ 1 ^ (j & 1)][tj];
      else
        ma1[i ^ 1 ^ (j & 1)][tj] = ma2[i][j];
  }
}

void (*fp[7])(int (*ma1)[MAXN], int (*ma2)[MAXN], bool flag) = {
    subs_1, subs_2, subs_3, subs_4, subs_5, subs_6, subs_7};

LL gcd(LL a, LL b) {
  LL temp;
  while (b) {
    temp = a % b;
    a = b;
    b = temp;
  }
  return a;
}

LL lcm(LL a, LL b) { return a / gcd(a, b) * b; }

bool vis[MAXN * MAXN];

LL solve(int *arr) {
  int tn = N * N;
  memset(vis, 0, sizeof(vis[0]) * tn);
  LL ans = 1LL;
  for (int i = 0; i < tn; ++i)
    if (!vis[arr[i]]) {
      int t1 = arr[i];
      int t2 = arr[t1];
      int count = 1;
      vis[t1] = true;
      while (t2 != t1) {
        vis[t2] = true;
        t2 = arr[t2];
        ++count;
      }
      ans = lcm(count, ans);
    }
  return ans;
}

string str;
string op[35];
int op_c;
int ma[2][MAXN][MAXN];
int subm[MAXN * MAXN];
map<string, pair<int, bool> > mp;

int main() {
  mp.insert(make_pair(string("id"), make_pair(0, true)));
  mp.insert(make_pair(string("id-"), make_pair(0, false)));
  mp.insert(make_pair(string("rot"), make_pair(1, true)));
  mp.insert(make_pair(string("rot-"), make_pair(1, false)));
  mp.insert(make_pair(string("sym"), make_pair(2, true)));
  mp.insert(make_pair(string("sym-"), make_pair(2, false)));
  mp.insert(make_pair(string("bhsym"), make_pair(3, true)));
  mp.insert(make_pair(string("bhsym-"), make_pair(3, false)));
  mp.insert(make_pair(string("bvsym"), make_pair(4, true)));
  mp.insert(make_pair(string("bvsym-"), make_pair(4, false)));
  mp.insert(make_pair(string("div"), make_pair(5, true)));
  mp.insert(make_pair(string("div-"), make_pair(5, false)));
  mp.insert(make_pair(string("mix"), make_pair(6, true)));
  mp.insert(make_pair(string("mix-"), make_pair(6, false)));
  while (~scanf("%d", &N)) {
    while (getchar() != '\n')
      ;

    getline(cin, str);

    istringstream in(str);
    op_c = 0;

    while (in >> op[op_c]) ++op_c;

    int cur = 1, last = 0;
    int ti = 0;
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j) ma[last][i][j] = ti++;
    for (int i = op_c - 1; i >= 0; --i) {
      pair<int, bool> temp;
      temp = mp[op[i]];
      fp[temp.first](ma[cur], ma[last], temp.second);
      cur ^= 1;
      last ^= 1;
    }
    ti = 0;
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j) subm[ti++] = ma[last][i][j];
    printf("%I64d\n", solve(subm));
  }
  return 0;
}
