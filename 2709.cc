#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

int N;
int amount[15];
int mix;
int main() {
  while (scanf("%d", &N) != EOF && N) {
    int Max = -1;
    for (int i = 1; i <= N; i++) {
      scanf("%d", &amount[i]);
      if (Max < amount[i]) Max = amount[i];
    }
    scanf("%d", &mix);
    int nf;
    if (Max % 50 == 0) {
      nf = Max / 50;
    } else {
      nf = Max / 50 + 1;
    }
    int i;
    if (mix == 0) {
      printf("%d\n", nf);
    } else {
      priority_queue<int> q;

      int tt = mix;
      while ((i = nf++) >= 0) {
        mix = tt;
        while (!q.empty()) q.pop();
        int v = i * 50;

        for (int j = 1; j <= N; j++) {
          int tmpa = v - amount[j];
          if (tmpa > 0) {
            q.push(tmpa);
          }
        }
        bool flag = false;
        while (q.size() >= 3) {
          int a = q.top();
          q.pop();
          int b = q.top();
          q.pop();
          int c = q.top();
          q.pop();
          --a;
          --b;
          --c;
          --mix;
          if (mix == 0) {
            flag = true;
            break;
          }
          if (a > 0) q.push(a);
          if (b > 0) q.push(b);
          if (c > 0) q.push(c);
        }
        if (flag) break;
      }
      printf("%d\n", i);
    }
  }
  return 0;
}
