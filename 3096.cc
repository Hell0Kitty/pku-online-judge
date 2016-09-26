#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

#define maxn 100

string st;
char pairs[maxn][2];

bool ok(char a, char b, int x) {
  for (int i = 0; i < x; i++)
    if (pairs[i][0] == a && pairs[i][1] == b) return false;
  pairs[x][0] = a;
  pairs[x][1] = b;
  return true;
}

int main() {
  while (getline(cin, st) && st != "*") {
    int n = st.length();
    bool s = true;
    for (int i = 1; i < n - 1; i++) {
      for (int j = 0; j + i < n; j++) {
        if (!ok(st[j], st[i + j], j)) {
          s = false;
          break;
        }
      }
      if (!s) break;
    }
    if (s)
      cout << st << " is surprising.\n";
    else
      cout << st << " is NOT surprising.\n";
  }
  return 0;
}
