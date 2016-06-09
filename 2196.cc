#include <cstdio>

int sum(int a, int b) {
  int ret = 0;
  while (a) {
    ret += a % b;
    a /= b;
  }
  return ret;
}

int main() {
  for (int i = 2992; i <= 9999; i++)
    if (sum(i, 10) == sum(i, 12) && sum(i, 10) == sum(i, 16)) printf("%d\n", i);
  return 0;
}
