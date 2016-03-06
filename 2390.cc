#include <stdio.h>
#include <math.h>
int main() {
  int year;
  double money, rate;
  scanf("%lf%lf%d", &rate, &money, &year);
  rate = pow((1 + rate / 100), year);
  money = money * rate;
  money = floor(money);
  printf("%.0lf", money);
}
