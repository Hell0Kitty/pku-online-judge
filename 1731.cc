#include <iostream>
#include <algorithm>
using namespace std;
#define MAXV 210

int t, a[MAXV];
char s[MAXV], pr[MAXV];

void pl(int cap) {
  char c = 0;
  int j;
  if (cap == t) {
    printf("%s\n", pr);
    return;
  }
  for (j = 0; j < t; j++) {
    if (!a[j] && c != s[j]) {
      pr[cap] = c = s[j];
      a[j] = 1;
      pl(cap + 1);
      a[j] = 0;
    }
  }
}

int main() {
  while (gets(s)) {
    memset(a, 0, sizeof(a));
    t = strlen(s);
    pr[t] = '\0';
    sort(s, s + strlen(s));
    pl(0);
  }
  return 0;
}