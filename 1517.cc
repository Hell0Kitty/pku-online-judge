#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

double cal(int a) {
  int temp = 1;
  double ret = 0;
  for (int i = 1; i <= a; i++) {
    temp *= i;
    ret += 1.0 / temp;
  }
  return ret + 1;
}

int main() {
  freopen("t.txt", "r", stdin);
  puts("n e");
  puts("- -----------");
  puts("0 1");
  puts("1 2");
  puts("2 2.5");
  puts("3 2.666666667");
  puts("4 2.708333333");
  for (int i = 5; i <= 9; i++) printf("%d %.9f\n", i, cal(i));
  return 0;
}
