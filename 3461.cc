#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void get__next(char *p, int *_next) {
  int k = -1;
  int j = 0;
  _next[0] = -1;
  int len = strlen(p);
  while (j < len) {
    if (k == -1 || p[j] == p[k]) {
      j++;
      k++;
      if (p[j] != p[k]) {
        _next[j] = k;
      } else {
        _next[j] = _next[k];
      }
    } else {
      k = _next[k];
    }
  }
}

int kmp(char *p, char *t, int *_next) {
  int ans = 0;
  int plen = strlen(p);
  int tlen = strlen(t);
  int i = 0, j = 0;
  while (i < tlen) {
    if (j == -1 || p[j] == t[i]) {
      i++;
      j++;
    } else {
      j = _next[j];
    }
    if (j == plen) {
      ans++;
      j = _next[j];
    }
  }
  return ans;
}
char t[1000010], p[1000010];
int _next[1000010];
int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    scanf("%s", p);
    scanf("%s", t);
    get__next(p, _next);
    int ans = kmp(p, t, _next);
    printf("%d\n", ans);
  }
  return 0;
}