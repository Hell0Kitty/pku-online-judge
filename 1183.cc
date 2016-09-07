#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
  long long a;
  scanf("%lld", &a);
  long long ans;
  for (ans = a; (a * a + 1) % ans; ans--)
    ;
  printf("%lld\n", ans + 2 * a + (a * a + 1) / ans);
  return 0;
}
