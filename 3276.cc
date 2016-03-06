#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int cow[5005], temp[5005];
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    char ch, lc = 'F';
    for (int i = 1; i <= n; i++) {
      scanf(" %c", &ch);
      if (lc == ch)
        cow[i] = 0;
      else
        cow[i] = 1;
      lc = ch;
    }
    int ansk, ansm = 1 << 30;
    for (int k = 1; k <= n; k++) {
      int tp = 0;
      memcpy(temp, cow, sizeof(cow));
      for (int i = 1; i <= n - k + 1; i++)
        if (temp[i]) tp++, temp[i + k] ^= 1;
      for (int i = n - k + 2; i <= n; i++) {
        if (temp[i]) {
          tp = 1 << 30;
          break;
        }
      }
      if (ansm > tp) {
        ansm = tp;
        ansk = k;
      }
    }
    printf("%d %d\n", ansk, ansm);
  }
  return 0;
}
