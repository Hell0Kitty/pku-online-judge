#include <cstdio>
#include <iostream>
using namespace std;

const int MAXM = 100000;
int num, pri[MAXM];

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else
    return gcd(b, a % b);
}

int get(int n) {
  num = 0;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      pri[num++] = i;
    }
    while (n % i == 0) {
      n /= i;
    }
  }
  if (n != 1) pri[num++] = n;
  return num;
}
int main() {
  int n, x, k, temp, d = 0;
  bool res;
  while (cin >> n >> x >> k) {
    d = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &temp);
      if (i == 0)
        d = temp;
      else {
        d = gcd(d, temp);
      }
    }
    get(k);
    res = true;
    for (int i = 0; i < num; i++) {
      while (d % pri[i] == 0) {
        d /= pri[i];
      }
    }
    if (x % d != 0) res = false;
    if (res)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}
