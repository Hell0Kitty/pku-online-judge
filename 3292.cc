#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

#define maxn 250005

int n, prime[maxn], ncount[maxn];

int main() {
  memset(prime, 0, sizeof(prime));
  int temp;
  n = maxn * 4;
  for (int i = 1; (i * 4 + 1) * (i * 4 + 1) <= n; i++) {
    for (int j = i; (temp = (i * 4 + 1) * (j * 4 + 1)) <= n; j++) {
      if (prime[i] == 0 && prime[j] == 0 && prime[(temp - 1) / 4] != 1)
        prime[((i * 4 + 1) * (j * 4 + 1) - 1) / 4] = 2;
      else
        prime[((i * 4 + 1) * (j * 4 + 1) - 1) / 4] = 1;
    }
  }
  ncount[0] = 0;
  for (int i = 1; i < maxn; i++)
    if (prime[i] == 2)
      ncount[i] = ncount[i - 1] + 1;
    else
      ncount[i] = ncount[i - 1];
  while (scanf("%d", &n) != EOF && n != 0) {
    printf("%d %d\n", n, ncount[(n - 1) / 4]);
  }
  return 0;
}
