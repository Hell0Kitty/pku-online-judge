#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int a[20], hash[100000], T;
void init() {
  a[0] = 2;
  hash[2] = 0;
  int sum = a[0];
  for (int i = 1; i <= 15; i++) {
    a[i] = sum + i + 1;
    sum += a[i];
    hash[a[i]] = i;
  }
}
void print(int n) {
  if (n == 0) {
    printf("{}");
    return;
  }
  printf("{");
  for (int i = 0; i < n; i++) {
    print(i);
    if (i < n - 1) printf(",");
  }
  printf("}");
}
int main() {
  init();
  scanf("%d", &T);
  while (T--) {
    char s[100000];
    int n = 0;
    for (int i = 0; i < 2; i++) {
      scanf("%s", s);
      int len = strlen(s);
      n += hash[len];
    }
    print(n);
    printf("\n");
  }
  return 0;
}
