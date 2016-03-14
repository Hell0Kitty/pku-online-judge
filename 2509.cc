#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
  long long n, m;
  long long sum;
  while (scanf("%lld%lld", &n, &m) != EOF) {
    sum = n;
    while (n >= m) {
      sum += n / m;
      n = n / m + n % m;
    }
    printf("%lld\n", sum);
  }
  return 0;
}
