
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 1000

int f[5];
char st[maxn];
char ans[maxn];
int len;

int group(char c) {
  if (c >= 'a' && c <= 'i') return 0;
  if (c >= 'j' && c <= 'r') return 1;
  return 2;
}

int getpos(int a) {
  int g = group(st[a]);
  int i = a;
  int t = f[g];
  while (t--) {
    i++;
    while (group(st[i % len]) != g) i++;
  }
  return i % len;
}

int main() {
  // freopen("t.txt", "r", stdin);
  while (scanf("%d%d%d", &f[0], &f[1], &f[2]), f[0] | f[1] | f[2]) {
    scanf("%s", st);
    len = strlen(st);
    for (int i = 0; i < len; i++) ans[getpos(i)] = st[i];
    ans[len] = '\0';
    printf("%s\n", ans);
  }
  return 0;
}