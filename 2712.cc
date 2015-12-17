#include <iostream>
using namespace std;

int isdigit(char c) {
  if (c >= '0' && c <= '9')
    return 1;
  return 0;
}

int isletter(char c) {
  if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')
    return 1;
  return 0;
}

int isupper(char c) {
  if (c >= 'A' && c <= 'Z')
    return 1;
  return 0;
}

int ismark(char c) {
  if (!isletter(c) && !isdigit(c) && c != ' ')
    return 1;
  return 0;
}

int un(char c) {
  if (c != 'A' && c != 'a' && c != 'I')
    return 1;
  return 0;
}

int main() {
  char s[85];
  int i, l, flag;
  while (1) {
    gets(s);
    if (s[0] == '#')
      break;
    for (l = 0; s[l] != '\0'; l++)
      ;
    flag = 1;

    if (l == 1 && un(s[0]))
      flag = 0;

    for (i = 0; i < l - 1 && flag == 1; i++) {
      if (isupper(s[i]) && isupper(s[i + 1]))
        flag = 0;
      else if (isletter(s[i]) && isdigit(s[i + 1]) ||
               isletter(s[i + 1]) && isdigit(s[i]))
        flag = 0;
      else if (i >= 1 && i <= (l - 3) && s[i] == ' ' && s[i + 2] == ' ' &&
               un(s[i + 1]))
        flag = 0;
      else if (i == (l - 2) && s[i] == ' ' && un(s[i + 1]))
        flag = 0;
      else if (i == 0 && s[i + 1] == ' ' && un(s[i]))
        flag = 0;
      else if (ismark(s[i]) && ismark(s[i + 1]) && s[i] != '"' &&
               s[i + 1] != '"')
        flag = 0;
    }

    if (flag == 0)
      printf("suspicious\n");
    else
      printf("OK\n");
  }
  return 0;
}