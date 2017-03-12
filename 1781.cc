#include <iostream>
#include <cstdio>
using namespace std;
typedef long long int ll;

ll get_num(ll x) {
  if (x == 1) return 1;
  if (x & 1)
    return (2 * get_num(x / 2) + 1);
  else
    return (2 * get_num(x / 2) - 1);
}

int main() {
  ll n, m;
  while (scanf("%I64de%I64d", &n, &m) && !(n == 0 && m == 0)) {
    for (int i(0); i < m; ++i) {
      n *= 10;
    }
    printf("%I64d\n", get_num(n));
  }
  return 0;
}
