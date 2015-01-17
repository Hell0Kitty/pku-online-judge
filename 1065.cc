#include <stdio.h>
int T, n, i, last, l[5000], w[5000], next, curr, ans;
bool b[5000], cant;
void shell_sort(int* a, int n) {
  int gap, i, j, tmp;
  for (gap = 1; (gap *= 3) < n; ++gap)
    ;
  for (gap /= 3; 0 < gap; gap = (gap + 1) / 3)
    for (i = gap; i < n; ++i)
      for (j = i - gap; j >= 0; j -= gap) {
        if (a[j + gap] < a[j]) {
          tmp = a[j];
          a[j] = a[j + gap];
          a[j + gap] = tmp;
          tmp = w[j];
          w[j] = w[j + gap];
          w[j + gap] = tmp;
        } else {
          if (a[j + gap] == a[j] && w[j + gap] < w[j]) {
            tmp = w[j];
            w[j] = w[j + gap];
            w[j + gap] = tmp;
          } else {
            break;
          }
        }
      }
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
      b[i] = true;
      scanf("%d%d", &l[i], &w[i]);
    }
    shell_sort(l, n);
    last = 0;
    ans = 1;
    next = 0;
    cant = true;
    while (cant) {
      cant = false;
      curr = next;
      next = 0;
      last = curr;
      for (i = curr + 1; i < n; i++) {
        if (b[i]) {
          if (l[i] >= l[last] && w[i] >= w[last]) {
            b[i] = false;
            last = i;
          } else {
            if (next == 0) {
              next = i;
              cant = true;
              ans++;
            }
          }
        }
      }
      //   if(cant)
    }
    printf("%d\n", ans);
  }
}
