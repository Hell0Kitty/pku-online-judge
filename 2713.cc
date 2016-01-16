#include <stdio.h>
#include <ctype.h>
char tmp[99];
int main() {
  while (gets(tmp)) {
    if (!tmp[0]) continue;
    double a[3], * val = a;
    for (char* p = tmp;;) {
      while (*p && !isdigit(*p) && *p != '.') ++p;
      if (!*p) break;
      int n;
      sscanf(p, "%lf%n", val++, &n);
      p += n;
    }
    double t = a[0] * a[1] / 500 + a[2] * 2.54;
    printf("%s: %.0f\n", tmp, t * 3.1415926535897932);
  }
}
