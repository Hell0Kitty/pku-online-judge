#include <stdio.h>
#define ma(x, y, z) x > (y > z ? y : z) ? x : (y > z ? y : z);
int i, j, n, a[50000], x, y, z, max, min, tmp;
int find(int start, int end) {
  if (start >= end)
    return -1;
  int tmp, min, max, x, y, z;
  tmp = min = max = start;
  while (start <= end) {
    if (a[start] < a[min])
      min = start;
    if (a[start] > a[max])
      max = start;
    start++;
  }
  if (max > min) {
    x = max - min;
    y = find(tmp, min - 1);
    z = find(max + 1, end);
  } else {
    x = find(tmp, max);
    y = find(max + 1, min - 1);
    z = find(min, end);
  }
  return ma(x, y, z);
}
int main() {
  while (scanf("%d", &n) != EOF) {
    max = min = 0;
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      if (a[i] < a[min])
        min = i;
      if (a[i] > a[max])
        max = i;
    }
    i = min - 2;
    while (i > -1 && a[i] > a[i + 1]) // 把递减到最小值的删掉
      i--;
    i += 2;
    tmp = i;
    for (j = min; j < n; j++, tmp++)
      a[tmp] = a[j];
    n = n - (min - i);
    if (max > min)
      max = max - (min - i);
    min = i;
    i = max + 1;
    while (i < n && a[i] > a[i + 1]) // 把从最大值开始递减的删掉
      i++;
    tmp = max + 1;
    for (j = i; j < n; j++, tmp++)
      a[tmp] = a[j];
    n = n - (i - (max + 1));
    if (min > max)
      min = min - (i - (max + 1));
    printf("%d\n", find(0, n - 1));
    }
    return 0;
}
