
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

#define maxn 1028

int f[maxn];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &f[i]);
    while (k--) next_permutation(f, f + n);
    printf("%d", f[0]);
    for (int i = 1; i < n; i++) printf(" %d", f[i]);
    printf("\n");
  }
  return 0;
}
