#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100100;
bool b[maxn];
int a[maxn];

int GetNextNumber(int i, int p, int k) {
  int q = 0;
  while (q <= p) {
    i++;
    if (i > k) i = 1;
    if (b[i]) q++;
  }
  return i;
}

int main() {
  int n, k, p;
  int cnt = 0;
  memset(b, 1, sizeof(b));
  scanf("%d%d%d", &n, &k, &p);
  int curNumber = 1;
  b[curNumber] = false;
  for (int i = 2; i <= k; i++) {
    int nextNumber = GetNextNumber(curNumber, p, k);
    curNumber = nextNumber;
    b[curNumber] = false;
    if (i % n == 0) a[cnt++] = curNumber;
  }
  sort(a, a + cnt);
  for (int i = 0; i < cnt; i++) printf("%d\n", a[i]);
  return 0;
}
