#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;
int bag[12900];
int w[3410], v[3410];
int main(void) {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];
  memset(bag, 0, sizeof(bag));
  for (int i = 1; i <= n; i++)
    for (int k = m; k >= w[i]; k--)
      if (bag[k - w[i]] + v[i] > bag[k]) bag[k] = bag[k - w[i]] + v[i];
  cout << bag[m] << endl;
  return 0;
}
