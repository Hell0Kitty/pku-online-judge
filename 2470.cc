#include <iostream>
#include <stdio.h>
using namespace std;

int a[100001];

int main() {
  int i;
  int n;

  while (scanf("%d", &n) != EOF && n) {
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);

    for (i = 1; i <= n; i++) {
      if (a[a[i]] != i) {
        printf("not ambiguous\n");
        break;
      }
    }
    if (i > n) printf("ambiguous\n");
  }
  return 0;
}
