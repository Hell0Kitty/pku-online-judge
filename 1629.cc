#include <stdio.h>
#include <string.h>
int main() {
  int ch[26];
  memset(ch, 0, sizeof(ch));
  int i, n, m, p;
  char str[200];
  char c;
  scanf("%d%d%d", &n, &m, &p);
  while (n--) {
    scanf("%s", str);
    for (i = 0; str[i] != '\0'; i++) ch[str[i] - 'A']++;
  }
  while (p--) {
    scanf("%s", str);
    for (i = 0; str[i] != '\0'; i++) ch[str[i] - 'A']--;
  }
  for (i = 0; i < 26; i++) {
    if (ch[i] != 0)
      while (ch[i]--) {
        c = 'A' + i;
        printf("%c", c);
      }
  }
  return 0;
}
