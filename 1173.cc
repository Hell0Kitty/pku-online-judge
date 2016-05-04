#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <float.h>
#include <iostream>
using namespace std;

#define M 104

typedef unsigned __int64 UINT64;

int num;
int g_n, g_k, g_m;
int input[M][36];

int g_number[36];
int g_divider[36];
UINT64 Combination(int n, int k) {  // still work when n==k, reurn 1
  k = min(k, n - k);

  for (int i = 0; i <= k; i++) {
    g_number[i] = n - i;
    g_divider[i] = i;
  }
  for (int i = 2; i <= k; i++) {
    for (int j = 0; j < k; j++) {
      if (g_number[j] % i == 0) {
        g_number[j] /= i;
        g_divider[i] = 1;
        break;
      }
    }
  }

  UINT64 nRes = 1;
  for (int i = 0; i < k; i++) {
    nRes *= g_number[i];
  }
  for (int i = 2; i <= k; i++) {
    nRes /= g_divider[i];
  }

  return nRes;
}

int Func(int n, int k, int m) {
  n = n - k;  // Xi = Yi+1

  UINT64 nRes = Combination(n + k - 1, k - 1);

  int nSign = -1;
  int nTmp;
  for (int i = 1; i <= k; i++) {
    nTmp = n - i * m;
    if (n - i * m < 0) break;

    nRes += nSign * Combination(k, i) * Combination(nTmp + k - 1, k - 1);
    nSign *= -1;
  }

  return (int)nRes;
}

int GetMinOnes(int nHandled, int kLeft) {
  return max(g_n - nHandled - (kLeft)*g_m, 1);
}

int GetMaxZeros(int nHandled, int kLeft) {
  return min(g_n - nHandled - (kLeft), g_m);
}

int GetSequence(int nth) {
  int nLen;
  int idx = 0;
  int nRes = 0;
  int nHandled = 0;
  int i;
  for (i = 1; i <= g_k - 2; i++) {
    // odd
    if (i % 2 == 1) {
      nLen = 0;
      while (input[nth][idx++] != 0) nLen++;
      idx--;
      for (int j = GetMinOnes(nHandled, g_k - i); j <= nLen - 1; j++) {
        nRes += Func(g_n - nHandled - j, g_k - i, g_m);
      }
      nHandled += nLen;
    }
    // even
    else {
      nLen = 0;
      while (input[nth][idx++] != 1) nLen++;
      idx--;
      for (int j = GetMaxZeros(nHandled, g_k - i); j > nLen; j--) {
        nRes += Func(g_n - nHandled - j, g_k - i, g_m);
      }
      nHandled += nLen;
    }
  }

  // odd
  if (i % 2 == 1) {
    nLen = 0;
    while (input[nth][idx++] != 0) nLen++;
    nRes += nLen - GetMinOnes(nHandled, g_k - i) + 1;
  }
  // even
  else {
    nLen = 0;
    while (input[nth][idx++] != 1) nLen++;
    nRes += GetMaxZeros(nHandled, g_k - i) - nLen + 1;
  }
  return nRes - 1;
}

int main() {
  scanf("%d %d %d", &g_n, &g_k, &g_m);
  scanf("%d", &num);
  char buf[36];

  for (int i = 0; i < num; i++) {
    scanf("%s", buf);
    for (int j = 0; j < g_n; j++) {
      input[i][j] = buf[j] - '0';
    }
  }

  printf("%d\n", Func(g_n, g_k, g_m));

  for (int i = 0; i < num; i++) {
    printf("%d\n", GetSequence(i));
  }

  return 0;
}
