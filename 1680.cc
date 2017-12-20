#include <iostream>
#include <stdio.h>
using namespace std;
int id, A, N, K, num;
int ok, st;
void work(int tag, int A, int loop) {
  int pid = id;
  if (ok == 1) return;
  for (int i = loop; i < N; i++) {
    if (tag != 0) {
      num++;
      if (num == K) {
        printf("Loop %d: Process ID=%d\n", i, pid);
        ok = 1;
        return;
      }
      A += 7;
      id++;
      work(tag * 0, A, i);
    }
    if (tag == 0) {
      num++;
      if (num == K) {
        printf("Process ID=%d, A=%d\n", pid, A);
        ok = 1;
        return;
      }
    }
    tag++;
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &N, &K);
    num = ok = 0;
    id = 1000;
    work(1, 0, 0);
  }
  return 0;
}
