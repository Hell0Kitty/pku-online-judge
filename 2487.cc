#include <iostream>
using namespace std;
const int Max = 1005;

void qsort(int *num, int left, int right) {
  int i = left, j = right;
  int mid = num[(i + j) / 2];
  while (i <= j) {
    while (num[i] > mid) i++;
    while (num[j] < mid) j--;
    if (i <= j) {
      int tmp;
      tmp = num[i];
      num[i] = num[j];
      num[j] = tmp;
      i++;
      j--;
    }
  }
  if (i < right) qsort(num, i, right);
  if (j > left) qsort(num, left, j);
}

int main() {
  int t, k, i, stamp[Max];
  scanf("%d", &t);
  for (k = 1; k <= t; k++) {
    int aim, f;
    scanf("%d%d", &aim, &f);
    for (i = 1; i <= f; i++) scanf("%d", &stamp[i]);
    qsort(stamp, 1, f);
    int sum = 0, ans = 0;
    bool possible = false;
    for (i = 1; i <= f; i++) {
      sum += stamp[i];
      ans++;
      if (sum >= aim) {
        possible = true;
        break;
      }
    }
    if (possible)
      printf("Scenario #%d:\n%d\n\n", k, ans);
    else
      printf("Scenario #%d:\nimpossible\n\n", k);
  }
  return 0;
}
