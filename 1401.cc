
#include <stdio.h>

int main() {
  int ncase;
  scanf("%d", &ncase);
  while (ncase--) {
    long int value;
    scanf("%d", &value);
    int count = 0;
    while (value) {
      count += value / 5;
      value = value / 5;
    }
    printf("%d\n", count);
  }
  return 0;
}