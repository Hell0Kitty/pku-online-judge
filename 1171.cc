#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

char pre1[30] = "qwertyuiopasdfghjklzxcvbnm";
int pre2[30] = {7, 6, 1, 2, 2, 5, 4, 1, 3, 5, 2, 1, 4,
                6, 5, 5, 7, 6, 3, 7, 7, 4, 6, 5, 2, 5};
int value[300];
char collected[10];
char word[40005][10];
int n, ans;

int cal(char *st, int len) {
  int ret = 0;
  for (int i = 0; i < len; i++) ret += value[st[i]];
  return ret;
}

bool ok(char *a, char *b) {
  int len1 = strlen(a);
  int len2 = strlen(b);
  int len = strlen(collected);
  if (len1 + len2 > len) return false;
  bool vis[10];
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < len1; i++) {
    bool did = false;
    for (int j = 0; j < len; j++)
      if (collected[j] == a[i] && !vis[j]) {
        vis[j] = true;
        did = true;
        break;
      }
    if (!did) return false;
  }
  for (int i = 0; i < len2; i++) {
    bool did = false;
    for (int j = 0; j < len; j++)
      if (collected[j] == b[i] && !vis[j]) {
        vis[j] = true;
        did = true;
        break;
      }
    if (!did) return false;
  }
  return true;
}

int main() {
  for (int i = 0; i < 26; i++) value[pre1[i]] = pre2[i];
  scanf("%s", collected);
  int lenc = strlen(collected);
  char now[10];
  n = 0;
  ans = 0;
  while (scanf("%s", now), strcmp(".", now)) {
    int len = strlen(now);
    if (len > lenc || !ok(now, "")) continue;
    ans = max(ans, cal(now, len));
    if (len <= lenc / 2 + (lenc & 1)) strcpy(word[n++], now);
  }
  for (int i = 0; i < n - 1; i++)
    for (int j = i; j < n; j++)
      if (ok(word[i], word[j]))
        ans = max(
            ans, cal(word[i], strlen(word[i])) + cal(word[j], strlen(word[j])));
  printf("%d\n", ans);
  return 0;
}
