#include <stdio.h>
#include <memory.h>

const int CAPACITY = 200;
const int MAX = 32000 + 1;
const int BUCKET = MAX / CAPACITY + 1;
const int N = 15000;

short bucket[BUCKET] = {0};
short a[MAX] = {0}, level[N] = {0};

int main() {
  int i, j, n, x, y, big, s;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d%d", &x, &y);
    big = x / CAPACITY;
    s = 0;
    for (j = 0; j < big; j++) s += bucket[j];
    for (j = CAPACITY * big; j <= x; j++) s += a[j];
    level[s]++;
    a[x]++;
    bucket[big]++;
  }
  for (i = 0; i < n; i++) printf("%d\n", level[i]);
  scanf("\n");
}
