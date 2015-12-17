

#include <stdio.h>
int main() {
  int a[1505], an, i, two, three, five, n;
  a[0] = 1;
  two = three = five = 0;
  for (an = 1; an < 1500; an++) {
    if (a[two] * 2 <= a[three] * 3 && a[two] * 2 <= a[five] * 5) {
      if (a[two] * 2 == a[three] * 3 && a[two] * 2 == a[five] * 5)
        three++, five++;
      else if (a[two] * 2 == a[three] * 3)
        three++;
      else if (a[two] * 2 == a[five] * 5)
        five++;
      a[an] = a[two++] * 2;
    } else if (a[three] * 3 <= a[two] * 2 && a[three] * 3 <= a[five] * 5) {
      if (a[three] * 3 == a[two] * 2)
        two++;
      else if (a[three] * 3 == a[five] * 5)
        five++;
      a[an] = a[three++] * 3;
    } else if (a[five] * 5 <= a[two] * 2 && a[five] * 5 <= a[three] * 3) {
      if (a[five] * 5 == a[two] * 2)
        two++;
      else if (a[five] * 5 == a[three] * 3)
        three++;
      a[an] = a[five++] * 5;
    }
  }
  while (scanf("%d", &n) && n != 0) printf("%d\n", a[n - 1]);
}