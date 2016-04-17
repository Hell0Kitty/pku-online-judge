#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#include <queue>
#include <string>
using namespace std;

const int maxn(111);
struct Edge {
  int v, start, end, time, next;
} e[maxn * 10];
int head[maxn], cnt;
int num;
void init() {
  memset(head, -1, sizeof head);
  cnt = 0;
  num = 0;
}
void add_Edge(int u, int v, int start, int end, int time) {
  e[cnt].v = v, e[cnt].start = start, e[cnt].end = end, e[cnt].time = time,
  e[cnt].next = head[u];
  head[u] = cnt++;
}
struct point {
  int end, blood;
  int u;
  friend bool operator<(const point &a, const point &b) {
    return a.blood > b.blood;
  }
  point(int x, int y, int z) : u(x), end(y), blood(z) {}
};
int vis[maxn];

void spfa(int s, int t) {
  priority_queue<point> q;

  q.push(point(s, 18, 0));
  memset(vis, 0, sizeof vis);
  vis[s] = 1;
  while (!q.empty()) {
    point tmp = q.top();
    q.pop();
    int u = tmp.u;

    vis[u] = 0;
    if (u == t) {
      printf("Vladimir needs %d litre(s) of blood.\n", tmp.blood);
      return;
    }
    for (int i = head[u]; i + 1; i = e[i].next) {
      int v = e[i].v;
      int start = e[i].start;
      if ((tmp.end < 18 && start < 18 && tmp.end <= start) ||
          (tmp.end >= 18 && (start >= tmp.end || start < 18)))
        q.push(point(v, e[i].end, tmp.blood));
      else
        q.push(point(v, e[i].end, tmp.blood + 1));
      if (!vis[v]) vis[v] = 1;
    }
  }
  puts("There is no route Vladimir can take.");
}
int main() {
  int tcase;
  scanf("%d", &tcase);
  int z = 1;
  while (tcase--) {
    int m;
    scanf("%d", &m);
    map<string, int> mat;
    string s1, s2;
    int start, time;
    init();
    while (m--) {
      cin >> s1 >> s2 >> start >> time;
      if (mat.count(s1) == 0) mat[s1] = num++;
      if (mat.count(s2) == 0) mat[s2] = num++;
      start %= 24;
      if (!(start <= 6 && start + time <= 6 ||
            start >= 18 && start + time <= 30))
        continue;
      add_Edge(mat[s1], mat[s2], start % 24, (start + time) % 24, time);
    }
    cin >> s1 >> s2;
    printf("Test Case %d.\n", z++);
    spfa(mat[s1], mat[s2]);
  }
  return 0;
}
