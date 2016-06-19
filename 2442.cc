#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 2002;
int main() {
  int t, n, k, m, i, j;
  int a[N], b[N];
  priority_queue<int> q;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++) {
      if (i == 0) {
        for (j = 0; j < m; j++) scanf("%d", &a[j]);
        sort(a, a + m);
      } else {
        for (j = 0; j < m; j++) scanf("%d", &b[j]);
        sort(b, b + m);

        for (j = 0; j < m; j++) {
          for (k = 0; k < m; k++) {
            if (j == 0) {
              q.push(b[j] + a[k]);
            } else {
              if (b[j] + a[k] < q.top()) {
                q.pop();
                q.push(b[j] + a[k]);
              } else
                break;
            }
          }
        }
        for (k = 0; k < m; k++) {
          a[k] = q.top();
          q.pop();
        }
        sort(a, a + m);
      }
    }
    printf("%d", a[0]);
    for (i = 1; i < m; i++) printf(" %d", a[i]);
    printf("\n");
  }
  return 0;
}
