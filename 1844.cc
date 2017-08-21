#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int sum = 0;
  int i = 0;
  while (sum < n || (sum - n) & 1) {
    i++;
    sum += i;
  }
  printf("%d\n", i);
  return 0;
}
