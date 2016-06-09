#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <map>
#include <ctime>
#define MAXN 4005
#define MAXM 1122222
#define INF 1000000001
using namespace std;
priority_queue<int, vector<int>, greater<int> > q1;
priority_queue<int, vector<int>, less<int> > q2;
vector<int> g;
void add(int x) {
  if (q1.empty()) {
    q1.push(x);
    return;
  }
  if (x > q1.top())
    q1.push(x);
  else
    q2.push(x);
  while (q1.size() < q2.size()) {
    q1.push(q2.top());
    q2.pop();
  }
  while (q1.size() > q2.size() + 1) {
    q2.push(q1.top());
    q1.pop();
  }
}
int main() {
  int T, cas, n, x;
  scanf("%d", &T);
  while (T--) {
    while (!q1.empty()) q1.pop();
    while (!q2.empty()) q2.pop();
    g.clear();
    scanf("%d%d", &cas, &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &x);
      add(x);
      if (i % 2 == 0) g.push_back(q1.top());
    }
    printf("%d %d\n", cas, (n + 1) / 2);
    for (int i = 0; i < g.size(); i++) {
      if (i > 0 && i % 10 == 0) putchar('\n');
      if (i % 10) putchar(' ');
      printf("%d", g[i]);
    }
    printf("\n");
  }
  return 0;
}
