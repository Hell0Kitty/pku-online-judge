#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int a[100005], c[100005], n;

int bin(int size, int k) {
  int l = 1, r = size;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (k > c[mid])
      l = mid + 1;
    else
      r = mid - 1;
  }
  return l;
}

int LIS() {
  int i, j, cnt = 0, k;
  for (i = 1; i <= n; i++) {
    if (cnt == 0 || a[i] > c[cnt])
      c[++cnt] = a[i];
    else {
      k = bin(cnt, a[i]);
      c[k] = a[i];
    }
  }
  return cnt;
}

int main() {
  long i;
  while (~scanf("%d", &n)) {
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    printf("%d\n", LIS());
  }

  return 0;
}
