#include <stdio.h>
#include <memory.h>
int Find(int x, int p[]) {
  int j, t = x;
  while (p[x] >= 0) x = p[x];
  j = x;
  while (p[t] >= 0) {
    x = p[t];
    p[t] = j;
    t = x;
  }
  return j;
}
void Union(int i, int j, int p[]) {
  int t = p[i] + p[j];
  if (p[i] < p[j]) {
    p[j] = i;
    p[i] = t;
  } else {
    p[i] = j;
    p[j] = t;
  }
}
int cal(char ch) {
  if (ch >= 'a')
    return ch - 'a';
  else
    return ch - 'A' + 26;
}
int main() {
  char str[10], hash[53];
  int i, degree[52], p[52], s, a, b, c, d, cnt1, cnt2;
  while (~scanf("%s", str)) {
    cnt1 = cnt2 = 0;
    memset(hash, 0, sizeof(hash));
    memset(degree, 0, sizeof(degree));
    memset(p, -1, sizeof(p));
    while (scanf("%s", str), str[0] != '{')
      ;
    while (scanf("%s", str), str[0] != '}') {
      s = cal(str[0]);
      hash[s] = 1;
    }
    while (scanf("%s", str), str[0] != '{')
      ;
    while (scanf("%s", str), str[0] != '}') {
      a = cal(str[1]);
      b = cal(str[3]);
      degree[a]++;
      degree[b]++;
      if (a != b && (c = Find(a, p)) != (d = Find(b, p))) Union(c, d, p);
    }
    for (i = 0; i < 52; i++) {
      if (hash[i] && p[i] < 0 && degree[i] > 0) cnt1++;
      if (degree[i] % 2) cnt2++;
      if (cnt2 > 2 || cnt1 > 1) break;
    }
    if ((cnt1 == 1 && cnt2 == 2) || (!cnt1 && !cnt2))
      printf("Yes ");
    else
      printf("No ");
    if (cnt1 <= 1 && !cnt2)
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
