#include <iostream>
#include <stdio.h>

using namespace std;

int phi[1010], sum[1010];
void phi_table(int n, int phi[]) {
  for (int i = 2; i <= n; i++) phi[i] = 0;
  phi[1] = 1;
  for (int i = 2; i <= n; i++)
    if (!phi[i])
      for (int j = i; j <= n; j += i) {
        if (!phi[j]) phi[j] = j;
        phi[j] = phi[j] / i * (i - 1);
      }
}

int main() {
  int T, t = 1;
  phi_table(1002, phi);
  sum[0] = sum[1] = 0;
  for (int i = 2; i <= 1002; i++) sum[i] = sum[i - 1] + phi[i];
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    cout << t++ << " " << n << " " << 3 + sum[n] * 2 << endl;
  }
  return 0;
}
