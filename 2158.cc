#include <cstdio>
#include <cstring>
#include <iostream>
#define Min(a1, b1) ((a1) > (b1) ? (b1) : (a1))
using namespace std;
const int Maxn = 5010;

long long arr[5][Maxn];
int k, n;

void ini() {
  memset(arr, 0, sizeof(arr));
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < k; ++j) {
      arr[2][i] += Min(i, j) + 1;
    }
  }

  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < k; ++j) {
      arr[3][i] += (Min(i, j) + 1) * (arr[2][j]);
    }
  }

  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < k; ++j) {
      arr[4][i] += (Min(i, j) + 1) * (arr[3][j]);
    }
  }
}

int main(void) {
  while (scanf("%d%d", &n, &k) != EOF) {
    ini();
    long long sum = 0;
    for (int i = 0; i < k; ++i) {
      sum += arr[n][i];
    }
    cout << sum << endl;
  }
  return 0;
}
