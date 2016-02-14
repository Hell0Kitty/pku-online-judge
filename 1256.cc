#include <stdio.h>
#include <iostream>
#include <stack>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

char str[15];

bool cmp(char x, char y) {
  if (tolower(x) == tolower(y)) {
    return x < y;
  } else {
    return tolower(x) < tolower(y);
  }
}

void Swap(char *a, char *b) {
  char temp = *a;
  *a = *b;
  *b = temp;
}

void Reserve(char *a, char *b) {
  while (a < b) {
    Swap(a++, b--);
  }
}

bool Next_Permutation(char *pstr, int nLen) {
  if (nLen == 1) {
    return false;
  }
  char *pEnd = pstr + nLen - 1;
  char *p = pEnd;
  char *q = pEnd;
  while (p != pstr) {
    q = p;
    p--;
    if (cmp(*p, *q)) {
      char *pfind = pEnd;
      while (cmp(*pfind, *p) || *pfind == *p) {
        --pfind;
      }
      Swap(p, pfind);
      Reserve(q, pEnd);
      return true;
    }
  }
  Reserve(pstr, pEnd);
  return false;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", str);
    sort(str, str + strlen(str), cmp);
    do {
      printf("%s\n", str);
    } while (Next_Permutation(str, strlen(str)));
  }
  return 0;
}
