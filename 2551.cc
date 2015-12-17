#include <cstdio>
using namespace std;
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    int a = 0, res = 0;
    do {
      res++;
      a = a * 10 % n + 1;
      a %= n;
    } while (a != 0);
    printf("%d\n", res);
  }
  return 0;
}