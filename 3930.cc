#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
const int maxn = 102;
struct instuction {
  int t, up;
  int fr, to;
  bool operator<(const instuction &other) const {
    if (t == other.t) {
      return up > other.up;
    }
    return t < other.t;
  }
} ins[maxn];
int wait[maxn >> 1][2][maxn], num[maxn >> 1][2], inside[maxn >> 1];
int n, layer, ti;

void read() {
  memset(wait, 0, sizeof(wait));
  memset(num, 0, sizeof(num));
  memset(inside, 0, sizeof(inside));
  scanf("%d %d", &layer, &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", &ins[i].t, &ins[i].fr, &ins[i].to);
    ins[i].up = (ins[i].fr <= ins[i].to);
  }
  sort(ins, ins + n);
  return;
}

bool check(int d) {
  if (d == 1) {
    for (int i = layer + 1; i <= 50; i++) {
      if (num[i][0] || num[i][1] || inside[i]) {
        return false;
      }
    }
    return true;
  }
  if (d == 0) {
    for (int i = layer - 1; i > 0; i--) {
      if (num[i][0] || num[i][1] || inside[i]) {
        return false;
      }
    }
    return true;
  }
}

void solve() {
  int l = 0, dir = -1;
  bool idle = true, close = true, run = false;
  while (l < n || !idle) {
    if (idle) {
      idle = false;
      ti = ins[l].t;
      continue;
    }
    while (l < n && ins[l].t <= ti) {
      wait[ins[l].fr][ins[l].up][num[ins[l].fr][ins[l].up]] = ins[l].to;
      num[ins[l].fr][ins[l].up]++;
      l++;
    }
    if (dir == -1) {
      if (num[layer][1])
        dir = 1;
      else if (num[layer][0])
        dir = 0;
      else {
        for (int i = layer + 1; i <= 50; i++) {
          if (num[i][1] || num[i][0]) {
            dir = 1;
            break;
          }
        }
        if (dir == -1) {
          for (int i = layer - 1; i > 0; i--) {
            if (num[i][1] || num[i][0]) {
              dir = 0;
              break;
            }
          }
        }
        if (dir == -1) {
          run = false;
          idle = true;
        }
      }
      continue;
    }
    if (num[layer][dir] || inside[layer] || close == false) {
      if (close) {
        close = false;
        if (run)
          printf("%02d:%02d The elevator stops at floor %d.\n", ti / 60,
                 ti % 60, layer);
        printf("%02d:%02d The elevator door is opening.\n", ti / 60, ti % 60);
        run = false;
        ti++;
      } else if (inside[layer]) {
        printf("%02d:%02d %d people leave the elevator.\n", ti / 60, ti % 60,
               inside[layer]);
        ti++;
        inside[layer] = 0;
        if (check(dir)) dir = -1;
      } else if (num[layer][dir]) {
        for (int i = 0; i < num[layer][dir]; i++) {
          inside[wait[layer][dir][i]]++;
        }
        printf("%02d:%02d %d people enter the elevator.\n", ti / 60, ti % 60,
               num[layer][dir]);
        ti++;
        num[layer][dir] = 0;
      } else {
        close = true;
        printf("%02d:%02d The elevator door is closing.\n", ti / 60, ti % 60);
        ti++;
      }
    } else if (dir == 1) {
      if (check(dir) == false) {
        if (run == false) {
          printf("%02d:%02d The elevator starts to move up from floor %d.\n",
                 ti / 60, ti % 60, layer);
          run = true;
        }
        ti++;
        layer++;
      } else
        dir = -1;
    } else {
      if (check(dir) == false) {
        if (run == false) {
          printf("%02d:%02d The elevator starts to move down from floor %d.\n",
                 ti / 60, ti % 60, layer);
          run = true;
        }
        ti++;
        layer--;
      } else
        dir = -1;
    }
  }
  printf("%02d:%02d The elevator door is closing.\n\n", ti / 60, ti % 60);
  return;
}

int main() {
  int cas;
  scanf("%d", &cas);
  for (int i = 1; i <= cas; i++) {
    printf("Case %d:\n", i);
    read();
    solve();
  }
  return 0;
}
