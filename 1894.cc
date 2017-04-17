#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 100 + 5;
char a[maxn], s[maxn * 4];
int adder[maxn * 4], buffer[maxn * 4];
int k, n, B, cnt;

void add() {
  int p = 0;
  for (int i = 0, p_; i < cnt; i++) {
    p_ = (buffer[i] + adder[i] + p) / B;
    buffer[i] = (buffer[i] + adder[i] + p) % B;
    p = p_;
  }
  if (p) {
    buffer[cnt] = p;
    cnt++;
  }
}
void update() {
  n = max(cnt, n);
  int p = 0;
  for (int i = 0, p_; i < n; i++) {
    p_ = ((s[i] + buffer[i] + p) - '0') / B;
    s[i] = ((s[i] + buffer[i] + p) - '0') % B + '0';
    p = p_;
  }
  if (p) s[n++] = p + '0';
}
int main() {
  while (~scanf("%d", &B)) {
    scanf("%s", a);
    k = strlen(a);
    if (k == 1 && a[k - 1] == '0') {
      printf("\n");
      continue;
    }
    for (int i = 0; i < maxn * 4; i++) s[i] = '0';
    memset(adder, 0, sizeof adder);
    cnt = n = 0;
    for (int i = k - 1; i >= 0; i--) {
      int j = k - 1 - i, t;
      if (!j) {
        cnt = 1;
        adder[0] = buffer[0] = 1;
      } else {
        t = 10;
        memcpy(buffer, adder, sizeof buffer);
        while (--t) add();
        memcpy(adder, buffer, sizeof buffer);
      }
      t = a[i] - '0';
      if (t) {
        while (--t) add();
        update();
      }
    }
    int p = 0;
    for (int i = 0; i < n; i++) {
      int t = s[i] - '0' + p;
      s[i] = '0' + (t <= 0 ? B + t : t);
      p = t <= 0 ? -1 : 0;
    }
    if (s[n - 1] == B + '0') n--;
    for (int i = n - 1; i >= 0; i--) putchar(s[i]);
    printf("\n");
  }
  return 0;
}
