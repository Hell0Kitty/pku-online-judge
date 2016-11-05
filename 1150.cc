#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

int s, e;
int count_two, count_five;

int get_digit(int s, int e) {
  int s1 = s / 10 * 10 + 10;
  int e1 = e / 10 * 10;
  int ret = 1;
  if (e1 <= s1) {
    for (int i = s; i <= e; i++)
      if ((i & 1) && (i % 5 != 0)) ret = ret * (i % 10) % 10;
    return ret;
  }
  ret = (e1 - s1) / 10 % 2 * 8 + 1;
  for (int i = s; i < s1; i++)
    if ((i & 1) && (i % 5 != 0)) ret = ret * (i % 10) % 10;
  for (int i = e1 + 1; i <= e; i++)
    if ((i & 1) && (i % 5 != 0)) ret = ret * (i % 10) % 10;
  return ret;
}

int cal_odd(int s, int e) {
  if (s > e) return 1;
  int ret = get_digit(s, e);
  int s1 = s;
  while (s1 % 10 != 5) s1++;
  int e1 = e;
  while (e1 > 0 && e1 % 10 != 5) e1--;
  if (e1 < s1) return ret;
  s1 /= 5;
  e1 /= 5;
  ret = ret * cal_odd(s1, e1) % 10;
  count_five += (e1 - s1) / 2 + 1;
  return ret;
}

int cal(int s, int e) {
  if (s > e) return 1;
  int ret = cal((s + 1) / 2, e / 2) % 10;
  count_two += e / 2 - (s + 1) / 2 + 1;
  ret = ret * cal_odd(s, e) % 10;
  return ret;
}

void test(int s, int e) {
  long long a = 1;
  for (int i = s; i <= e; i++) {
    a *= i;
    while (a % 10 == 0) a /= 10;
  }
  printf("%lld", a % 10);
}

int main() {
  while (~scanf("%d%d", &e, &s)) {
    s = e - s + 1;
    count_two = 0;
    count_five = 0;
    int ans = cal(s, e);
    if (count_five > count_two) {
      puts("5");
      continue;
    }
    int temp = count_two - count_five;
    if (temp == 0) {
      printf("%d\n", ans);
      continue;
    }
    temp--;
    ans = ans * 2 % 10;
    for (int i = 0; i < temp % 4; i++) ans = ans * 2 % 10;
    printf("%d\n", ans);
  }
  return 0;
}
