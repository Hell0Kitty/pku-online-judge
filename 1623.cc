#include <iostream>
#include <cstring>
#include <map>
#include <cstdio>
using namespace std;
int number[10];
char a[1030][1030];
int col, row;
map<string, int> Map;
int flag;
int ans;
string dfs(int len, int x, int y, int deep, int &temp) {
  string s = "\0";
  if (len == 1) return s + a[x][y];
  if (len == 2) {
    s = dfs(len / 2, x, y, deep + 1, temp) +
        dfs(len / 2, x, y + len / 2, deep + 1, temp) +
        dfs(len / 2, x + len / 2, y, deep + 1, temp) +
        dfs(len / 2, x + len / 2, y + len / 2, deep + 1, temp);
    int l = s.length();
    bool flag0 = 0, flag1 = 0;
    for (int i = 0; i < l; i++) {
      if (s[i] == '0')
        flag0 = 1;
      else
        flag1 = 1;
    }
    if (flag1 && flag0) {
      temp = 5;
      Map[s]++;
      if (Map[s] == 1) ans += 4;
    } else if (flag1) {
      temp = 1;
    } else {
      temp = 0;
    }
  } else {
    flag = 0;
    string s1 = "\0";
    s = dfs(len / 2, x, y, deep + 1, temp);
    int flag0 = 0, flag1 = 0;
    int ret = 1;
    if (temp > 1)
      ret += temp;
    else if (temp)
      flag1++;
    else
      flag0++;
    if (temp == 0)
      s1 = s1 + "0";
    else if (temp)
      s1 = s1 + "1";
    s = s + dfs(len / 2, x, y + len / 2, deep + 1, temp);
    if (temp > 1)
      ret += temp;
    else if (temp)
      flag1++;
    else
      flag0++;
    if (temp == 0)
      s1 = s1 + "0";
    else if (temp)
      s1 = s1 + "1";
    s = s + dfs(len / 2, x + len / 2, y, deep + 1, temp);
    if (temp > 1)
      ret += temp;
    else if (temp)
      flag1++;
    else
      flag0++;
    if (temp == 0)
      s1 = s1 + "0";
    else if (temp)
      s1 = s1 + "1";
    s = s + dfs(len / 2, x + len / 2, y + len / 2, deep + 1, temp);
    if (temp > 1)
      ret += temp;
    else if (temp)
      flag1++;
    else
      flag0++;
    if (temp == 0)
      s1 = s1 + "0";
    else if (temp)
      s1 = s1 + "1";
    if (flag0 == 4) {
      temp = 0;
      s = "0000";
    } else if (flag1 == 4) {
      temp = 1;
      s = "1111";
    } else if (flag0 + flag1 == 4) {
      s = s1;
      temp = 5;
      Map[s]++;
      if (Map[s] == 1) ans += 4;
    } else {
      ret += flag0 + flag1;
      temp = ret;
      Map[s]++;
      if (Map[s] == 1) {
        ans += flag0 + flag1;
      }
    }
  }
  return s;
}
int main() {
  ios::sync_with_stdio(false);
  number[0] = 1;
  int n, m;
  for (int i = 1; i < 10; i++) number[i] = number[i - 1] * 2;
  while (cin >> n >> m && (n || m)) {
    ans = 0;
    row = n, col = m;
    int id = 0;
    while (number[id] < n || number[id] < m) id++;
    row = col = number[id];
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) a[i][j] = '0';
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    Map.clear();
    int temp = 0;
    string s = dfs(row, 0, 0, 1, temp);
    if (temp == 0 || temp == 1) ans = 1;
    map<string, int>::iterator it;
    int ans1 = 0, ans2 = 0;

    for (it = Map.begin(); it != Map.end(); it++) {
      ans++;
    }

    if (temp == 0) temp = 1;
    cout << temp << " " << ans << endl;
  }
}
