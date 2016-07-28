#include <stdio.h>
#include <iostream>
#include <string.h>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>
#include <ctype.h>
#include <vector>
#define MAX 110
using namespace std;

vector<int> map[MAX];
bool odd[MAX], even[MAX];
int odd_count[MAX], even_count[MAX];

void init(const int &n) {
  for (int i = 0; i < MAX; ++i) map[i].clear();
  memset(odd_count, 0, sizeof(odd_count));
  memset(even_count, 0, sizeof(even_count));
}

void dfs(const int &x, const int &step) {
  bool flag = false;
  if (!odd[x] && step % 2) {
    flag = true;
    odd[x] = true;
  }
  if (!even[x] && step % 2 == 0) {
    flag = true;
    even[x] = true;
  }
  if (flag) {
    for (size_t i = 0; i < map[x].size(); ++i) dfs(map[x][i], step + 1);
  }
}

int main(void) {
  int n, m, ncase = 1;
  int id, u, v, tmp;
  scanf("%d", &ncase);

  while (ncase--) {
    scanf("%d%d", &n, &m);
    init(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", &id, &tmp);
      for (int j = 0; j < tmp; ++j) {
        scanf("%d", &v);
        map[id].push_back(v);
      }
    }
    for (int i = 0; i < m; ++i) {
      memset(odd, false, sizeof(odd));
      memset(even, false, sizeof(even));
      scanf("%d", &u);
      dfs(u, 0);
      for (int j = 0; j < MAX; ++j) {
        if (odd[j]) ++odd_count[j];
        if (even[j]) ++even_count[j];
      }
    }
    bool ans = false;
    for (int i = 0; i < MAX && !ans; ++i) {
      if (odd_count[i] == m) ans = true;
      if (even_count[i] == m) ans = true;
    }
    if (ans)
      printf("YES\n");
    else
      printf("NO\n");
  }

  return 0;
}
