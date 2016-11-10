#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>

using namespace std;
typedef long long LL;
const int N = 250000;

LL a[N], b[N], c[N];
int n;

void Import() {
  LL x, y, z;
  for (int i = 0; i < n; i++) {
    scanf("%I64d%I64d%I64d", &x, &y, &z);
    a[i] = y - x;
    b[i] = z - y;
    c[i] = z - x;
  }
  sort(a, a + n);
  sort(b, b + n);
  sort(c, c + n);
}

void Work() {
  LL sum = 0;
  for (int i = 0; i < n; i++) {
    sum += i * a[i] - (n - 1 - i) * a[i];
    sum += i * b[i] - (n - 1 - i) * b[i];
    sum += i * c[i] - (n - 1 - i) * c[i];
  }
  printf("%I64d\n", sum >> 1);
}

int main() {
  while (~scanf("%d", &n)) {
    if (n == 0) break;
    Import();
    Work();
  }
  return 0;
}
