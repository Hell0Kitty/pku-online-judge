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
string s[8], st;
int flag[8];
int N;
int Max = 0x3f3f3f3f;
string merge(string s1, string s2) {
  int i, j, l;
  for (i = 0; i < s1.size(); i++) {
    j = 0;
    l = i;
    while (s1[l] == s2[j] && l < s1.size() && j < s2.size()) {
      l++;
      j++;
    }
    if (l == s1.size()) {
      s1.replace(i, s2.size(), s2);
      return s1;
    }
  }
  return s1 + s2;
}
void dfs(int deep) {
  if (deep == N) {
    if (Max > st.size()) Max = st.size();
    return;
  }
  int i;
  string temp = st;
  for (i = 0; i < N; i++) {
    if (!flag[i]) {
      if (!st.size())
        st += s[i];
      else
        st = merge(st, s[i]);
      flag[i] = 1;
      dfs(deep + 1);
      flag[i] = 0;
      st = temp;
    }
  }
}
int main() {
  memset(flag, 0, sizeof(flag));
  int i;
  cin >> N;
  for (i = 0; i < N; i++) {
    cin >> s[i];
  }
  dfs(0);
  cout << Max << endl;
  return 0;
}
