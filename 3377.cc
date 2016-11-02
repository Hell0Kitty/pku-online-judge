#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

#define MAXN 1000010

struct dist {
  int id;
  __int64 val;
  bool operator<(const dist& a) const { return val > a.val; }
} next, tmp;

priority_queue<dist> Q;
__int64 dis[2 * MAXN], ferry[MAXN];
bool vis[MAXN * 2];
int N;
int st, end;

void relax(int k, __int64 dis) {
  next.id = k;
  next.val = tmp.val + dis;
  Q.push(next);
}

__int64 bfs() {
  for (int i = 0; i < 2 * MAXN; i++) vis[i] = 0;
  while (!Q.empty()) Q.pop();
  tmp.id = st;
  tmp.val = 0;
  Q.push(tmp);
  while (!Q.empty()) {
    tmp = Q.top();
    Q.pop();
    if (tmp.id == end) return tmp.val;
    if (vis[tmp.id]) continue;
    vis[tmp.id] = 1;
    if (tmp.id == 0) {
      relax(N + 1, ferry[0]);
      relax(1, dis[1]);
    } else if (tmp.id == N + 1) {
      relax(0, ferry[0]);
      relax(tmp.id + 1, dis[tmp.id + 1]);
    } else if (tmp.id == N) {
      relax(tmp.id - 1, dis[tmp.id]);
      relax(tmp.id + N + 1, ferry[N]);
    } else if (tmp.id == 2 * N + 1) {
      relax(N, ferry[N]);
      relax(tmp.id - 1, dis[tmp.id]);
    } else if (tmp.id > 0 && tmp.id < N) {
      relax(tmp.id - 1, dis[tmp.id]);
      relax(tmp.id + 1, dis[tmp.id + 1]);
      relax(tmp.id + N + 1, ferry[tmp.id]);
    } else if (tmp.id > N + 1 && tmp.id < 2 * N + 1) {
      relax(tmp.id - 1, dis[tmp.id]);
      relax(tmp.id + 1, dis[tmp.id + 1]);
      relax(tmp.id - N - 1, ferry[tmp.id - N - 1]);
    }
  }
  return -1;
}

int main() {
  int x, y;
  while (scanf("%d", &N) && N) {
    scanf("%d%d", &x, &y);
    st = y + x * (N + 1);
    scanf("%d%d", &x, &y);
    end = y + x * (N + 1);
    for (int i = 1; i <= N; i++) scanf("%I64d", &dis[i]);
    for (int i = 0; i <= N; i++) scanf("%I64dd", &ferry[i]);
    for (int i = 1; i <= N; i++) scanf("%I64d", &dis[i + N + 1]);
    printf("%I64d\n", bfs());
  }
  return 0;
}
