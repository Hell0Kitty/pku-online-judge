#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 5010;
struct node {
  int digit;
  int yu;
  int pre;
} que[maxn];
int n, m;
int d[100];
bool flag[maxn];
void output(node t) {
  if (t.pre != -1) {
    output(que[t.pre]);
    printf("%d", t.digit);
  }
}
void bfs() {
  int front, rear, r;
  bool f = 0;
  memset(flag, 0, sizeof(flag));
  que[0].digit = 0;
  que[0].yu = 0;
  que[0].pre = -1;
  front = 0;
  rear = 1;
  while (front < rear) {
    node now = que[front];
    node t;
    for (int i = 0; i < n; ++i) {
      r = (10 * now.yu + d[i]) % m;
      if (!flag[r] && (now.pre != -1 || d[i] > 0)) {
        flag[r] = 1;
        t.digit = d[i];
        t.yu = r;
        t.pre = front;
        que[rear++] = t;
        if (r == 0) {
          output(t);
          printf("\n");
          f = true;
          break;
        }
      }
      if (f) break;
    }
    front++;
    if (f) break;
  }
  if (!f) {
    printf("0\n");
  }
}
int main() {
  while (scanf("%d", &m) != EOF) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &d[i]);
    sort(d, d + n);
    if (m == 0) {
      printf("0\n");
      continue;
    }
    bfs();
  }
  return 0;
}
