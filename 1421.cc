#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <deque>
#include <list>
using namespace std;

const int MAXN = 10086;
map<string, int> var;
int vist[MAXN];
string vec[MAXN];
char str[MAXN];
int len;

int get_val(char c) {
  switch (c) {
    case '+':
      return 100;
    case '-':
      return 150;
    case '*':
      return 200;
    case '(':
      return 1000;
    case ')':
      return 50;
  }
  if (c >= '0' && c <= '9') return 10;
  if (c == '-') return 10;
  return 20;
}

int get_le(int a, int b, int ope) {
  if (ope == 200)
    return a * b;
  else if (ope == 100)
    return a + b;
  else
    return b - a;
}

int slove(string &s) {
  if (var.find(s) == var.end()) return INT_MIN;
  int t = var[s];
  // if (vist[t]) return -1;
  ++vist[t];
  if (vist[t] > 10) return INT_MIN;
  vector<int> num;
  vector<int> ope;
  for (int i = 0; i < vec[t].size(); ++i) {
    if (vec[t][i] == ' ') continue;
    int l = get_val(vec[t][i]);
    if (l == 150 && vec[t][i + 1] >= '0' && vec[t][i + 1] <= '9') l = 10;
    if (l < 50) {
      if (l == 10) {
        int flag = 1;
        if (vec[t][i] == '-') {
          flag = -1;
          ++i;
          if (num.size() - ope.size() == 1) ope.push_back(100);
        }
        int ml = 0;
        while (vec[t][i] >= '0' && vec[t][i] <= '9')
          ml = ml * 10 + vec[t][i++] - '0';
        --i;
        num.push_back(ml * flag);
      } else {
        string sl = "";
        while (i < vec[t].size() && vec[t][i] != ' ' && get_val(vec[t][i]) < 50)
          sl += vec[t][i++];
        --i;
        int ml = slove(sl);
        if (ml == INT_MIN) return INT_MIN;
        num.push_back(ml);
      }
    } else {
      while (ope.size() > 0 && l <= ope.back() && ope.back() != 1000) {
        int t1 = num.back();
        num.pop_back();
        int t2 = num.back();
        num.pop_back();
        num.push_back(get_le(t1, t2, ope.back()));
        ope.pop_back();
      }
      if (l == 50)
        ope.pop_back();
      else {
        if (ope.size() > 0 && ope.back() == 150) {
          if (l == 100)
            ope.push_back(150);
          else if (l == 150)
            ope.push_back(100);
          else
            ope.push_back(l);
        } else
          ope.push_back(l);
      }
    }
  }
  while (ope.size() > 0) {
    int t1 = num.back();
    num.pop_back();
    int t2 = num.back();
    num.pop_back();
    num.push_back(get_le(t1, t2, ope.back()));
    ope.pop_back();
  }
  return num.back();
}

void Print(int c) {
  string t = "";
  for (int i = 5 + c; str[i]; ++i) {
    if (str[i] == ' ') continue;
    t += str[i];
  }
  memset(vist, false, sizeof(vist));
  int ans = slove(t);
  if (ans == INT_MIN)
    puts("UNDEF");
  else
    printf("%d\n", ans);
}

void reset() {
  len = 0;
  var.clear();
}

int main() {
  while (gets(str)) {
    if (str[0] == 0) continue;
    int i = 0;
    while (str[i] == ' ') ++i;
    // puts(str + i);
    char c = str[5 + i];
    str[5 + i] = 0;
    if (strcmp(str + i, "RESET") == 0) {
      reset();
      continue;
    }

    if (strcmp(str + i, "PRINT") == 0) {
      str[5 + i] = c;
      Print(i);
      continue;
    }
    str[5 + i] = c;
    string s = "";
    for (; str[i] != ' ' && str[i] != ':'; ++i) s += str[i];
    if (var.find(s) == var.end()) var[s] = len++;
    int t = var[s];
    s = "";
    while (str[i] != ':') ++i;
    i += 2;
    while (str[i]) s += str[i++];
    vec[t] = s;
  }
  return 0;
}
