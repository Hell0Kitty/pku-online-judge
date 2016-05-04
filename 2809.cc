#include <iostream>
#include <string>
using namespace std;
int main() {
  int uy;
  cin >> uy;
  int qw = 1;
  while (qw <= uy) {
    int n;
    cin >> n;
    string a;
    int xy = 0;
    int sr = 0, e;
    cin >> a;
    int len = a.length();
    int sh[1000], ch = 0, g = 0;
    char abc[1000];
    long sum1[1000];
    int yz = 0, i;
    sh[0] = -1;
    if (a[0] == '+' || a[0] == '-') {
      yz = 1;
      sh[0] = 0;
    }
    int j = 1;
    for (i = yz; i < len; i++)
      if (a[i] == '+' || a[i] == '-') {
        sh[j] = i;
        j++;
      }
    sh[j] = len;
    for (i = 0; i < j; i++) {
      ch = 0;
      g = 0;
      string s = a.substr(sh[i] + 1, sh[i + 1] - sh[i] - 1);
      len = s.length();
      int u, ua = 1, v, va = 1;
      for (u = 0; u < len; u++)
        if (s[u] == '^') break;
      if (u == len) ua = -1;
      for (v = 0; v < len; v++)
        if (s[v] == 'x') break;
      if (v == len) va = -1;
      if (ua == -1 && va == -1) ch = 0;
      if (ua == -1 && va == 1) ch = 1;
      if (ua == 1) {
        int p = 1;
        int l = len;
        for (l -= 1; l > u; l--)
          if (s[l] >= '0' && s[l] <= '9') {
            ch = ch + int(s[l] - 48) * p;
            p = p * 10;
          }
      }
      if (s[0] == 'x') {
        g = 1;
        if (sh[i] >= 0 && a[sh[i]] == '-') g = g - 2 * g;
      }
      if (s[0] != 'x') {
        int l = v - 1;
        int p = 1;
        for (; l >= 0; l--) {
          g = g + int(s[l] - 48) * p;
          p = p * 10;
        }
        if (sh[i] >= 0 && a[sh[i]] == '-') g = g - 2 * g;
      }
      if (ch == 1) sr++;
      int sum = g * ch;
      sum1[i] = sum;
      for (int o = 1; o <= ch - 1; o++) sum1[i] = sum1[i] * n;
      if (sum > 0 && xy != 0) {
        abc[xy] = '+';
        xy++;
      }
      if (sum < 0) {
        abc[xy] = '-';
        xy++;
        sum = sum - 2 * sum;
      }
      if (sum > 0) {
        int m[100];
        int z = 0;
        for (z = 0;; z++) {
          m[z] = sum % 10;
          sum = sum / 10;
          if (sum == 0) break;
        }
        for (; z >= 0; z--) {
          abc[xy] = char(m[z] + 48);
          xy++;
        }
      }
      if (ch >= 2) {
        abc[xy] = 'x';
        xy++;
      }
      if (ch >= 3) {
        abc[xy] = '^';
        xy++;
      }
      if (ch >= 3) {
        abc[xy] = char(ch + 47);
        xy++;
      }
    }
    cout << "POLYNOMIAL " << qw << endl;
    qw++;
    cout << a << endl;
    if (xy == 0) {
      for (int o = 0; o < 4; o++) cout << 0 << endl;
      continue;
    }
    for (e = 0; e < xy; e++) cout << abc[e];
    cout << endl;
    for (e = 0; e < xy; e++) {
      if (abc[e] != 'x') cout << abc[e];
      if (abc[e] == 'x') {
        sr++;
        cout << "(" << n << ")";
      }
    }
    cout << endl;
    for (i = 0; i < sr; i++) {
      if (i > 0 && sum1[i] >= 0) cout << "+";
      cout << sum1[i];
    }
    cout << endl;
    for (i = 1; i < j; i++) sum1[0] = sum1[0] + sum1[i];
    cout << sum1[0] << endl;
  }
  return 0;
}
