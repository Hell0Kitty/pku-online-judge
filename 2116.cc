#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main() {
  double f[50] = {1, 2}, sum1, sum2, sum;
  int s1[40], s2[40], s3[40], n;
  string a, b;
  char *a1, *a2, *a3;
  for (int i = 2; i < 50; i++) f[i] = f[i - 1] + f[i - 2];
  while (cin >> a >> b) {
    int t1 = 0, t2 = 0;
    for (int i = 0; i < a.size(); i++)
      if (a[i] != '0') {
        t1 = i;
        break;
      }
    for (int i = 0; i < b.size(); i++)
      if (b[i] != '0') {
        t2 = i;
        break;
      }
    sum1 = sum2 = sum = 0;
    memset(s1, -1, sizeof(s1));
    memset(s2, -1, sizeof(s2));
    memset(s3, -1, sizeof(s3));
    for (int i = a.size() - 1, j = 0; i >= 0; i--, j++)
      if (a[i] == '1') sum1 += f[j];
    for (int i = b.size() - 1, j = 0; i >= 0; i--, j++)
      if (b[i] == '1') sum2 += f[j];
    sum = sum1 + sum2;
    n = 0;
    while (sum1 > 0) {
      int i = 0;
      while (sum1 >= f[i]) i++;
      s1[n++] = --i;
      sum1 -= f[i];
    }
    n = 0;
    while (sum2 > 0) {
      int i = 0;
      while (sum2 >= f[i]) i++;
      s2[n++] = --i;
      sum2 -= f[i];
    }
    n = 0;
    while (sum > 0) {
      int i = 0;
      while (sum >= f[i]) i++;
      s3[n++] = --i;
      sum -= f[i];
    }
    a1 = new char[s1[0] + 2];
    a2 = new char[s2[0] + 2];
    a3 = new char[s3[0] + 2];
    memset(a1, '0', (s1[0] + 2) * sizeof(char));
    memset(a2, '0', (s2[0] + 2) * sizeof(char));
    memset(a3, '0', (s3[0] + 2) * sizeof(char));
    a1[s1[0] + 1] = a2[s2[0] + 1] = a3[s3[0] + 1] = '\0';
    for (int i = 0; s1[i] != -1; i++) a1[s1[0] - s1[i]] = '1';
    for (int i = 0; s2[i] != -1; i++) a2[s2[0] - s2[i]] = '1';
    for (int i = 0; s3[i] != -1; i++) a3[s3[0] - s3[i]] = '1';
    if (a[t1] == '0' && b[t2] != '0') {
      cout << setw(s3[0] + 3) << 0 << endl
           << "+" << setw(s3[0] + 2) << a2 << endl
           << "  ";
      for (int i = 0; i < s3[0] + 1; i++) cout << "-";
      cout << endl
           << setw(s3[0] + 3) << a3 << endl
           << endl;
    } else if (a[t1] != '0' && b[t2] == '0') {
      cout << setw(s3[0] + 3) << a1 << endl
           << "+" << setw(s3[0] + 2) << 0 << endl
           << "  ";
      for (int i = 0; i < s3[0] + 1; i++) cout << "-";
      cout << endl
           << setw(s3[0] + 3) << a3 << endl
           << endl;
    } else if (a[t1] == '0' && b[t2] == '0') {
      cout << setw(3) << 0 << endl
           << "+" << setw(2) << 0 << endl
           << "  -" << endl
           << setw(3) << 0 << endl
           << endl;
    } else {
      cout << setw(s3[0] + 3) << a1 << endl
           << "+" << setw(s3[0] + 2) << a2 << endl
           << "  ";
      for (int i = 0; i < s3[0] + 1; i++) cout << "-";
      cout << endl
           << setw(s3[0] + 3) << a3 << endl
           << endl;
    }
    delete[] a1;
    delete[] a2;
    delete[] a3;
  }
  return 0;
}
