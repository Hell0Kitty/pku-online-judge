#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
LL po[15];
struct Data {
  LL x, y;
  bool operator<(const Data &ne) const { return x < ne.x; }
} ans[10000];
int top;
LL remove(LL x, int i) { return x / po[i] * po[i - 1] + x % po[i - 1]; }
void solve1(int i, LL n) {
  LL left = -po[i], right = po[i], m = 11 - (10 * n) % 11, x;
  for (LL mm = m; mm >= left; mm -= 11) {
    x = (10 * n + mm) / 11;
    if (x <= 0ll) break;
    LL y = remove(x, i);
    if (x + y == n) {
      ans[top].x = x;
      ans[top++].y = y;
    }
  }
  for (LL mm = m + 11; mm <= right; mm += 11) {
    x = (10 * n + mm) / 11;
    if (x >= n) break;
    LL y = remove(x, i);
    if (x + y == n) {
      ans[top].x = x;
      ans[top++].y = y;
    }
  }
}
void solve2(int i, LL n) {
  if (n % 2 != 0) return;
  LL ad = po[i - 1] / 2;
  for (LL x = n / 2 + ad; x <= n; x += ad) {
    LL y = remove(x, i);
    if (x + y == n) {
      ans[top].x = x;
      ans[top++].y = y;
    }
  }
}
int main() {
  LL n;
  po[0] = 1;
  for (int i = 1; i <= 10; i++) po[i] = po[i - 1] * 10ll;
  while (scanf("%lld", &n) != EOF) {
    top = 0;
    int len;
    for (len = 1; len <= 10; len++)
      if (n < po[len]) break;
    for (int i = 1; i <= len / 2; i++) solve1(i, n);
    for (int i = len / 2 + 1; i <= len; i++) solve2(i, n);
    if (top == 0) {
      printf("0\n");
      continue;
    }
    sort(ans, ans + top);
    int num = 0;
    for (int i = 1; i < top; i++) {
      if (ans[i].x != ans[num].x) ans[++num] = ans[i];
    }
    num++;
    printf("%d\n", num);
    for (int i = 0, j, k; i < num; i++) {
      for (j = 1; j <= 10; j++)
        if (ans[i].x < po[j]) break;
      for (k = 1; k <= 10; k++)
        if (ans[i].y < po[k]) break;
      printf("%lld + ", ans[i].x);
      k++;
      while (k < j) printf("0"), k++;
      printf("%lld = %lld\n", ans[i].y, n);
    }
  }
  return 0;
}
