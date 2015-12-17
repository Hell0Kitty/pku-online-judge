
#include <iostream>
#include <cstring>
using namespace std;

int d[100][100];
int c[100][100] = {-1};
int len;
string s;

void dp() {
  int i, j, k, l;
  int min;

  for (i = 0; i < len; i++) d[i][i] = 1;

  for (l = 1; l < len; ++l)
    for (i = 0; i + l < len; ++i) {
      j = i + l;
      min = d[i][i] + d[i + 1][j];
      c[i][j] = i;
      for (k = i + 1; k < j; k++) {
        if (d[i][k] + d[k + 1][j] < min) {
          min = d[i][k] + d[k + 1][j];
          c[i][j] = k;
        }
      }
      d[i][j] = min;

      if (s[i] == '(' && s[j] == ')' || s[i] == '[' && s[j] == ']') {
        if (d[i + 1][j - 1] < min) {
          d[i][j] = d[i + 1][j - 1];
          c[i][j] = -1;
        }
      }
    }
}

void print(int i, int j) {
  if (i > j) return;
  if (i == j) {
    if (s[i] == '(' || s[i] == ')')
      cout << "()";
    else
      cout << "[]";
  } else {
    if (c[i][j] >= 0) {
      print(i, c[i][j]);
      print(c[i][j] + 1, j);
    } else {
      if (s[i] == '(') {
        cout << "(";
        print(i + 1, j - 1);
        cout << ")";
      } else {
        cout << "[";
        print(i + 1, j - 1);
        cout << "]";
      }
    }
  }
}

int main() {
  cin >> s;

  len = s.size();
  dp();
  print(0, len - 1);
  cout << endl;
  return 0;
}