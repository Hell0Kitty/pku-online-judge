#include <stdio.h>

int main() {
  int ncase;
  scanf("%d", &ncase);
  int i;
  for (i = 0; i < ncase; i++) {
    float x, y;
    scanf("%f%f", &x, &y);
    int answer = (int)(3.1415926 * (x * x + y * y) / 100.0);
    printf("Property %d: This property will begin eroding in year %d.\n", i + 1,
           answer + 1);
  }
  puts("END OF OUTPUT.");
  return 0;
}
