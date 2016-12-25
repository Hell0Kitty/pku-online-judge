#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;

int sum(int n) {
  int ans = 0;

  while (n > 0) {
    ans += n % 10;
    n /= 10;
  }
  return ans;
}

bool work(int n) {
  int i, temp, ans1, ans2;

  ans1 = sum(n);
  temp = n;
  i = 2;
  ans2 = 0;
  while (i <= sqrt(double(n))) {
    if (n % i == 0) {
      n /= i;
      ans2 += sum(i);
    } else
      i++;
  }
  ans2 += sum(n);
  if (ans1 == ans2 && temp != n)
    return true;
  else
    return false;
}

int main() {
  int n;
  while (cin >> n && n != 0) {
    n++;
    while (!work(n)) n++;
    cout << n << endl;
  }
  return 0;
}
