
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
long long arr[33];
int main() {
  //  ifstream cin("test.txt");
  int j;
  for (j = 0; j < 32; j++) {
    arr[j] = pow(2.0, j + 1.0) - 1;
  }
  string str;
  int len, i;
  long long sum;
  while (cin >> str && (str != "0")) {
    len = str.length();
    sum = 0;
    for (i = 0; i < len; i++) {
      sum += (str[i] - '0') * arr[len - i - 1];
    }
    cout << sum << endl;
  }
  return 0;
}