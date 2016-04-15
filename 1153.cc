#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int P[300000];
int SEG = 10000000;
int main() {
  long n;
  long i;
  long j;
  double result, tempresult;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> P[i];
  }
  sort(P, P + n);
  for (i = 0; i < n; i++) {
    P[i + n] = P[i] + SEG;
    P[i + 2 * n] = P[i + n] + SEG;
  }
  tempresult = 0;
  int s;
  s = P[n] + SEG / 2;
  for (i = n + 1; P[i] <= s; ++i) {
    tempresult += (P[i] - P[n]);
  }
  int ln = i;
  j = 2 * n - i;
  for (i = 0; i < j; ++i) {
    tempresult += (P[n] - P[n - i - 1]);
  }
  result = tempresult;
  for (i = n + 1; i < 2 * n; ++i) {
    s = P[i] + SEG / 2;
    for (j = ln; P[j] <= s; j++) {
      tempresult += (P[j] - P[i]);
      tempresult -= (P[i - 1] - P[j - n]);
    }
    tempresult += ((n - ln + 2 * i - j) * (P[i] - P[i - 1]));
    ln = j;
    if (result > tempresult) result = tempresult;
  }
  printf("%.0f\n", result);
  return 0;
}
