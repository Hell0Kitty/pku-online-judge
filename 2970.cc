#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
struct rec {
  int a, b, d;
  double x;
} work[100100];
struct cmp1 {
  bool operator()(rec x, rec y) { return x.a < y.a; }
};
int cmp2(rec x, rec y) { return x.d < y.d; }
priority_queue<rec, vector<rec>, cmp1> q;
int n;
int main() {
  while (scanf("%d\n", &n) != EOF) {
    for (int i = 1; i <= n; i++) {
      scanf("%d %d %d", &work[i].a, &work[i].b, &work[i].d);
      work[i].x = 0;
    }
    sort(work + 1, work + n + 1, cmp2);
    double deadline = 0, ans = 0;
    while (!q.empty()) q.pop();
    for (int i = 1; i <= n; i++) {
      q.push(work[i]);
      deadline += work[i].b;
      while (deadline - work[i].d > 1e-9) {
        int x = deadline - work[i].d;
        rec tmp = q.top();
        q.pop();
        if (tmp.b - tmp.x - x > 1e-9) {
          ans += (double)x / tmp.a;
          tmp.x += x;
          deadline -= x;
          q.push(tmp);
        } else {
          ans += (double)(tmp.b - tmp.x) / tmp.a;
          deadline -= tmp.b - tmp.x;
        }
      }
    }
    printf("%.2f\n", ans);
  }
  return 0;
}
