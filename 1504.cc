#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int main() {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  while (n--) {
    string op1, op2;
    cin >> op1 >> op2;
    reverse(op1.begin(), op1.end());
    reverse(op2.begin(), op2.end());
    int a = atoi(op1.c_str());
    int b = atoi(op2.c_str());
    int sum = a + b;

    stringstream ss;
    string result;
    ss << sum;
    ss >> result;
    reverse(result.begin(), result.end());
    cout << atoi(result.c_str()) << endl;
  }

  return 0;
}