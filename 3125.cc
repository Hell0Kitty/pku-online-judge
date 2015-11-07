#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
  int a[10010];
  int front, rear, i;
  int cases, n, d, time, ok;
  scanf("%d", &cases);
  while (cases--) {
    front = 0;
    rear = 0;
    time = 0;
    ok = 0;
    scanf("%d%d", &n, &d);
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      rear++;
    }
    while (front <= rear) {
      for (i = front; i < rear; i++) {
        if (a[i] > a[front]) {
          a[rear++] = a[front];
          break;
        }
      }

      if (i >= rear) {
        time += 1;
        if (front == d) {
          printf("%d\n", time);
          ok = 1;
          break;
        } else
          front++;
      } else if (front == d) {
        d = rear - 1;
      } else
        front++;
      if (ok) break;
    }
  }
  return 0;
}
