

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int s, len;
char LED[100][25], n[10];
const char code[5][31] = {
    {" -     -  -     -  -  -  -  - "},
    {"| |  |  |  || ||  |    || || |"},
    {"       -  -  -  -  -     -  - "},
    {"| |  ||    |  |  || |  || |  |"},
    {" -     -  -     -  -     -  - "},
};
void print(int s, int i, char *str) {
  int j, k;
  for (j = 0; j < len; j++) {
    int m = (str[j] - '0') * 3;
    putchar(code[i][m]);
    for (k = 0; k < s; k++) putchar(code[i][m + 1]);
    putchar(code[i][m + 2]);
    printf("%c", j == len - 1 ? '\n' : ' ');
  }
}
void deal() {
  for (int i = 0; i < 5; i++) {
    if (i % 2)
      for (int j = 0; j < s; j++) print(s, i, n);
    else
      print(s, i, n);
  }
  putchar('\n');
}
int main(void) {
  while (scanf("%d%s", &s, &n) == 2) {
    len = (int)strlen(n);
    if (s == 0) break;
    deal();
  }
  return 0;
}