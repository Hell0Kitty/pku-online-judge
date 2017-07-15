

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 1005

int n;
double f[maxn];
int len1[maxn], len2[maxn];

int main() {
  memset(len1, 0, sizeof(len1));
  memset(len2, 0, sizeof(len2));
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lf", &f[i]);
  for (int i = 1; i < n; i++)
    for (int j = 0; j < i; j++)
      if (f[j] < f[i] && len1[j] + 1 > len1[i]) len1[i] = len1[j] + 1;
  for (int i = n - 2; i >= 0; i--)
    for (int j = n - 1; j > i; j--)
      if (f[j] < f[i] && len2[j] + 1 > len2[i]) len2[i] = len2[j] + 1;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(len1[i] + 1, ans);
    for (int j = i + 1; j < n; j++) ans = max(ans, len1[i] + len2[j] + 2);
  }
  printf("%d\n", n - ans);
  return 0;
}
