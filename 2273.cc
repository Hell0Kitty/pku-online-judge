#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char s[30], s1[30];
int pow[7] = {0, 26, 702, 18278, 475254, 12356630, 321272406};

int main() {
  while (~scanf("%s", s)) {
    if (strcmp(s, "R0C0") == 0) break;
    int cnt = 0, i, j;
    for (i = 1; s[i]; i++) {
      if (s[i] == 'C') break;
      s1[cnt++] = s[i];
    }
    s1[cnt] = '\0';

    int ans = 0;
    for (j = i + 1; s[j]; j++) ans = ans * 10 + s[j] - '0';

    char tmp[10];

    if (ans <= 26)
      printf("%c", 'A' + ans - 1);

    else if (ans <= 702) {
      for (cnt = 0; cnt < 2; cnt++) {
        int t = ans % 26;
        if (t == 0) {
          tmp[cnt] = 'Z';
          ans -= 26;
        } else {
          tmp[cnt] = 'A' + t - 1;
          ans -= t;
        }
        ans = ans / 26;
      }
      for (j = cnt - 1; j >= 0; j--) printf("%c", tmp[j]);
    } else if (ans <= 18278) {
      for (cnt = 0; cnt < 3; cnt++) {
        int t = ans % 26;
        if (t == 0) {
          tmp[cnt] = 'Z';
          ans -= 26;
        } else {
          tmp[cnt] = 'A' + t - 1;
          ans -= t;
        }
        ans = ans / 26;
      }
      for (j = cnt - 1; j >= 0; j--) printf("%c", tmp[j]);
    } else if (ans <= 475254) {
      for (cnt = 0; cnt < 4; cnt++) {
        int t = ans % 26;
        if (t == 0) {
          tmp[cnt] = 'Z';
          ans -= 26;
        } else {
          tmp[cnt] = 'A' + t - 1;
          ans -= t;
        }
        ans = ans / 26;
      }
      for (j = cnt - 1; j >= 0; j--) printf("%c", tmp[j]);
    } else if (ans <= 12356630) {
      for (cnt = 0; cnt < 5; cnt++) {
        int t = ans % 26;
        if (t == 0) {
          tmp[cnt] = 'Z';
          ans -= 26;
        } else {
          tmp[cnt] = 'A' + t - 1;
          ans -= t;
        }
        ans = ans / 26;
      }
      for (j = cnt - 1; j >= 0; j--) printf("%c", tmp[j]);
    } else if (ans <= 321272406) {
      for (cnt = 0; cnt < 6; cnt++) {
        int t = ans % 26;
        if (t == 0) {
          tmp[cnt] = 'Z';
          ans -= 26;
        } else {
          tmp[cnt] = 'A' + t - 1;
          ans -= t;
        }
        ans = ans / 26;
      }
      for (j = cnt - 1; j >= 0; j--) printf("%c", tmp[j]);
    }
    printf("%s\n", s1);
  }
  return 0;
}