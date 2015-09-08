#include <cmath>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <cstdio>
#include <string>
#define INF 99999999

using namespace std;

int init, dest, l, nop, nw;
int d[1 << 20];
char op[32][21];
int w[32];

int oper(int u, char oper[21]) {
  for (int i = 0; i < l; ++i) {
    if (oper[i] == 'F')
      u ^= 1 << (l - 1 - i);
    else if (oper[i] == 'S')
      u |= 1 << (l - 1 - i);
    else if (oper[i] == 'C')
      u &= ~(1 << (l - 1 - i));
  }
  return u;
}

bool dijkstra() {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>> PQ;
  bool inS[1 << 20];
  for (int i = 0; i < (1 << 20); ++i) {
    inS[i] = false;
    d[i] = INF;
  }
  d[init] = 0;
  PQ.push(make_pair(0, init));
  while (!PQ.empty() && !inS[dest]) {
    int u = PQ.top().second;
    PQ.pop();
    if (!inS[u]) {
      inS[u] = true;
      for (int i = 0; i < nop; ++i) {
        int v = oper(u, op[i]);
        if (!inS[v] && d[v] > d[u] + w[i]) {
          d[v] = d[u] + w[i];
          PQ.push(make_pair(d[v], v));
        }
      }
    }
  }
  if (d[dest] == INF)
    return false;
  else
    return true;
}

int main() {
  std::ios::sync_with_stdio(false);
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d%d%d", &l, &nop, &nw);
    for (int i = 0; i < nop; ++i) {
      scanf("%s %d", op[i], &w[i]);
    }
    for (int i = 0; i < nw; ++i) {
      init = dest = 0;
      char c;
      for (int pos = l - 1; pos >= 0; --pos) {
        cin >> c;
        if (c == '1') init |= 1 << pos;
      }
      for (int pos = l - 1; pos >= 0; --pos) {
        cin >> c;
        if (c == '1') dest |= 1 << pos;
      }
      if (dijkstra())
        printf("%d ", d[dest]);
      else
        printf("NP ");
    }
    putchar('\n');
  }
}