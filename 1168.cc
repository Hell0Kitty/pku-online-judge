#include <iostream>
#include <string.h>
#include <algorithm>
#include <string.h>
#include <list>
#include <vector>
using namespace std;

int n, m, k;
int nowans[10];
int s[10];
bool used[100];
int resnum = -1;
list<string> res;
int findnext() {
  for (int i = m; i <= m + n * (n - 1) + 1; i++)
    if (!used[i]) return i;
  return -1;
}
int findmin(int pos) {
  for (int i = 0; i < n; i++)
    if (s[i] == pos) return i;
  return -1;
}
void search1(int pos, int last) {
  if (pos == -1) {
    int maxnum = findnext() - 1;
    if (maxnum >= resnum) {
      char tmp[10];
      for (int i = 0; i < n; i++) tmp[i] = nowans[i];
      tmp[n] = '\0';
      if (maxnum > resnum) {
        resnum = maxnum;
        res.clear();
      }
      res.push_back(string(tmp));
    }
  } else {
    int nextneed = findnext();
    for (int i = last; i <= m + n * (n - 1) + 1; i++) {
      if (i > nextneed) break;
      vector<int> tmp;
      nowans[pos] = i;
      for (int j = 0; j < n; j++)
        for (int step = 0; step < n; step++) {
          int total = 0;
          for (int l = j; l <= j + step; l++) {
            if (nowans[l % n] == -1) {
              total = -1;
              break;
            } else
              total += nowans[l % n];
          }
          if (total == -1)
            break;
          else {
            if (!used[total]) {
              used[total] = 1;
              tmp.push_back(total);
            }
          }
        }
      search1(findmin(s[pos] + 1), i);
      for (int i = 0; i < tmp.size(); i++) used[tmp[i]] = 0;
    }
    nowans[pos] = -1;
  }
}
int main() {
  memset(used, 0, sizeof(used));
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) s[i] = i, nowans[i] = -1;
  do {
    search1(findmin(0), k);
  } while (next_permutation(s + 1, s + n));
  res.sort();
  res.unique();
  cout << resnum << endl;
  for (list<string>::iterator it = res.begin(); it != res.end(); it++) {
    for (int j = 0; j < (it->length()); j++) cout << (int)(it->at(j)) << " ";
    cout << endl;
  }
  return 0;
}
