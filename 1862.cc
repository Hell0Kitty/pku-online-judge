#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define maxn 105

int n;
int f[maxn];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &f[i]);
  sort(f, f + n);
  double ans = f[n - 1];
  for (int i = n - 2; i >= 0; i--) ans = 2 * sqrt(ans * f[i]);
  printf("%.3f\n", ans);
}
