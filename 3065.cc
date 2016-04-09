#include <cstdio>
#include <ctype.h>
#include <algorithm>
#define MAXN 6000010
using namespace std;

int set[MAXN];

int Find(int x) {
  if (x == set[x]) return x;
  set[x] = Find(set[x]);
  return set[x];
}

void Connect(int a, int b) {
  int x = Find(a);
  int y = Find(b);
  if (x > y) swap(x, y);
  set[y] = x;
}

int getNum(char *s) {
  int i, k = 0;
  for (i = 1; s[i] != '\0'; i++)
    if (s[i] != ' ' && s[i - 1] == ' ') k++;
  return k;
}

bool Query(int a, int b) {
  int x = Find(a);
  int y = Find(b);
  return x == y;
}

int main() {
  char s[100];
  int i, j, k, n, l, r, v, w;
  int src, dst, nnn, dststep, srcstep;
  char cmd;
  for (; gets(s);) {
    cmd = tolower(s[0]);
    if (cmd == 'd') {
      sscanf(s, "%*s %d", &n);
      for (i = 0; i <= n; i++) set[i] = i;
    } else {
      k = getNum(s);
      nnn = dststep = 1;
      srcstep = 0;
      if (k == 2)
        sscanf(s, "%*s %d %d", &src, &dst);
      else if (k == 3)
        sscanf(s, "%*s %d %d %d", &src, &dst, &nnn);
      else if (k == 4)
        sscanf(s, "%*s %d %d %d %d", &src, &dst, &nnn, &dststep);
      else
        sscanf(s, "%*s %d %d %d %d %d", &src, &dst, &nnn, &dststep, &srcstep);
      if (cmd == 'c') {
        if (dststep == srcstep && !srcstep) nnn = 1;
        for (i = 0, v = src, w = dst; i < nnn; i++, v += srcstep, w += dststep)
          Connect(v, w);
      } else {
        l = r = 0;
        for (i = 0, v = src, w = dst; i < nnn; i++, v += srcstep, w += dststep)
          Query(v, w) ? l++ : r++;
        printf("%d - %d\n", l, r);
      }
    }
  }
  return 0;
}
