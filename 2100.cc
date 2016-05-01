#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define maxn 1000000

ll n;
pii ans[maxn];

int main() {
  while (~scanf("%I64d", &n)) {
    ll s = 1, pos = 1, sum = 0;
    int len = 0;
    for (; s * s <= n; ++s) {
      while (sum < n) {
        sum += pos * pos;
        ++pos;
      }
      if (sum == n) {
        ans[len].first = pos - s;
        ans[len++].second = s;
      }
      sum -= s * s;
    }

    printf("%d\n", len);
    for (int i = 0; i < len; ++i) {
      printf("%I64d", ans[i].first);
      for (int j = 0; j < ans[i].first; ++j)
        printf(" %I64d", ans[i].second + j);
      printf("\n");
    }
  }
  return 0;
}
