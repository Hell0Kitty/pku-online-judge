#include <iostream>
#include <stdio.h>
#include <string.h>

char left[3][7], right[3][7], result[3][7];

bool isLight(char x) {
  int i;
  for (i = 0; i < 3; i++) {
    switch (result[i][0]) {
      case 'u':
        if (strchr(right[i], x) == NULL) return false;
        break;
      case 'e':
        if (strchr(right[i], x) != NULL || strchr(left[i], x) != NULL)
          return false;
        break;
      case 'd':
        if (strchr(left[i], x) == NULL) return false;
        break;
    }
  }
  return true;
}

bool isHeavy(char x) {
  int i;
  for (i = 0; i < 3; i++) {
    switch (result[i][0]) {
      case 'u':
        if (strchr(left[i], x) == NULL) return false;
        break;
      case 'e':
        if (strchr(right[i], x) != NULL || strchr(left[i], x) != NULL)
          return false;
        break;
      case 'd':
        if (strchr(right[i], x) == NULL) return false;
        break;
    }
  }
  return true;
}

int main() {
  int n;
  int i;
  char c;
  scanf("%d", &n);
  while (n--) {
    for (i = 0; i < 3; i++) scanf("%s %s %s", left[i], right[i], result[i]);
    for (c = 'A'; c <= 'L'; c++) {
      if (isLight(c)) {
        printf("%c is the counterfeit coin and it is light.\n", c);
        break;
      }
      if (isHeavy(c)) {
        printf("%c is the counterfeit coin and it is heavy.\n", c);
        break;
      }
    }
  }
  return 1;
}
