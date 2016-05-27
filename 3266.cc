#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 5e4 + 9;
double high[maxn], low[maxn];
long long sumt[maxn], sump[maxn];
struct D {
  long long t, p;
  bool operator<(const D& xx) const { return t * xx.p > xx.t * p; }
} test[maxn];
int que[maxn];

bool chk(int i, int j, int t, int s) {
  long long a = (test[i].t - test[j].t) * (test[t].p - test[s].p);
  long long b = (test[t].t - test[s].t) * (test[i].p - test[j].p);
  return a > b;
}

bool chk2(int i, int j, long long t, long long p) {
  long long a = (test[i].t - test[j].t) * p;
  long long b = t * (test[i].p - test[j].p);
  return a > b;
}
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; i++) scanf("%lld %lld", &test[i].t, &test[i].p);
    sort(test + 1, test + 1 + n);

    for (int i = 1; i <= n; i++) {
      sumt[i] = sumt[i - 1] + test[i].t;
      sump[i] = sump[i - 1] + test[i].p;
    }

    int front = 1, end = 0;
    for (int i = 1; i <= n; i++) {
      while (end >= front && test[i].p >= test[que[end]].p) end--;
      while (end > front && chk(que[end], i, que[end - 1], que[end])) end--;
      que[++end] = i;
      while (front < end &&
             chk2(que[front], que[front + 1], sumt[i], sump[i]) == 1)
        front++;
      int u = que[front];
      low[i] = test[u].t - (double)sumt[i] / sump[i] * test[u].p;
    }
    int top = 0;
    for (int i = n; i >= 1; i--) {
      while (top > 0 && test[i].p <= test[que[top]].p) top--;
      while (top > 1 && chk(i, que[top], que[top], que[top - 1])) top--;
      que[++top] = i;
      while (top > 1 &&
             chk2(que[top], que[top - 1], sumt[i - 1], sump[i - 1]) == 0)
        top--;
      int u = que[top];
      high[i] = test[u].t - (double)sumt[i - 1] / sump[i - 1] * test[u].p;
    }
    int ans = 0;
    for (int i = 1; i < n; i++)
      if (high[i + 1] > low[i]) ans++;
    cout << ans << endl;
    for (int i = n - 1; i >= 1; i--)
      if (high[i + 1] > low[i]) printf("%d\n", n - i);
  }
  return 0;
}
