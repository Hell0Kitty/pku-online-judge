#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 1006

int n;
int a[maxn], cnt, c[maxn];

void input() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
}

void MergeSort(int l, int r) {
  int mid, i, j, tmp;
  if (r > l + 1) {
    mid = (l + r) / 2;
    MergeSort(l, mid);
    MergeSort(mid, r);
    tmp = l;
    for (i = l, j = mid; i < mid && j < r;) {
      if (a[i] > a[j]) {
        c[tmp++] = a[j++];
        cnt += mid - i;
      } else
        c[tmp++] = a[i++];
    }
    if (j < r)
      for (; j < r; ++j) c[tmp++] = a[j];
    else
      for (; i < mid; ++i) c[tmp++] = a[i];
    for (i = l; i < r; ++i) a[i] = c[i];
  }
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    input();
    cnt = 0;
    MergeSort(0, n);
    printf("Scenario #%d:\n%d\n\n", i + 1, cnt);
  }
  return 0;
}
