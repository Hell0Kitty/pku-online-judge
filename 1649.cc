#include <cstdio>
#include <set>
std::set<int> s;
#define M 110
int price[M], bk[M], n, t[M];
int profit(int pos, int p) {
  for (int i = 1; i <= pos; i++) t[i] = price[i];
  t[pos + 1] = p;
  for (int i = pos + 1; i <= n; i++) t[i + 1] = price[i];
  bool flag = true;
  int tot = 0;
  for (int i = 1; i <= pos; i++)  // from left
    if (t[i] < p) flag = false;
  if (flag) {
    tot += bk[pos + 1];
    for (int i = pos + 2; i <= n; i++) {
      if (t[i] <= p) break;
      tot += bk[i];
    }
  }
  flag = true;
  for (int i = n + 1; i > pos; i--)  // from right
    if (t[i] < p) flag = false;
  if (flag) {
    tot += bk[n + 1 - pos];
    for (int i = pos; i > 1; i--) {
      if (t[i] <= p) break;
      tot += bk[n - i + 2];
    }
  }
  return p * tot;
}
int main(void) {
  while (~scanf("%d", &n)) {
    s.clear();
    for (int i = 1; i <= n; i++) {
      scanf("%d", &price[i]);
      s.insert(price[i]);
      s.insert(price[i] - 1);
    }
    for (int i = 1; i <= n; i++) scanf("%d", &bk[i]);
    int num = 0, plf, ans = -99999;
    for (int i = 1; i < n; i++)
      for (std::set<int>::iterator j = s.begin(); j != s.end(); j++) {
        int temp = profit(i, *j);
        if (temp > ans) ans = temp, num = i, plf = *j;
      }
    printf("%d %d\n", num, plf);
  }
  return 0;
}
