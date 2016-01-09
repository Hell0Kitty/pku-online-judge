#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int maxn = 100100;
const int INF = 1100000000;
int n, c;

int cow[maxn];

int check(int now) {
  int cnt = 1;
  int pos = cow[0];
  for (int i = 1; i < n; i++) {
    if (cow[i] - pos >= now) {
      cnt++;
      pos = cow[i];
    }
  }
  return cnt >= c;
}

int main() {
  while (scanf("%d%d", &n, &c) != EOF) {
    for (int i = 0; i < n; i++) {
      scanf("%d", &cow[i]);
    }
    sort(cow, cow + n);
    int l = 0;
    int r = INF;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      if (check(mid)) {
        l = mid;
      } else
        r = mid;
    }
    printf("%d\n", l);
  }
  return 0;
}
