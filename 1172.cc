#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <set>
using namespace std;

template <class T>
void tension(T& a, const T& b) {
  if (b < a) a = b;
}

template <class T>
void relax(T& a, const T& b) {
  if (b > a) a = b;
}

typedef long long i64;

#ifndef ONLINE_JUDGE
#define ep(...) fprintf(stderr, __VA_ARGS__)
#else
#define ep(...) assert(true)
#endif

struct Edge {
  Edge* next;
  int to;
};

Edge mem[1000];
Edge* curMem = mem;
Edge* info[1000];

int n;

void insert(int a, int b) {
  curMem->to = b;
  curMem->next = info[a];
  info[a] = curMem++;
}

int ban;

set<int> que;

void dfs(int v) {
  que.insert(v);
  if (v == ban) return;
  for (Edge* pt = info[v]; pt; pt = pt->next) {
    int u = pt->to;
    if (!que.count(u)) dfs(u);
  }
}

void output(vector<int>& x) {
  printf("%d", (int)x.size());
  sort(x.begin(), x.end());
  for (int i = 0, _i = x.size(); i < _i; i++) printf(" %d", x[i]);
  printf("\n");
}

typedef set<int>::iterator siter;

bool check(int v) {
  que.clear();
  ban = v;
  dfs(0);

  que.erase(v);
  for (int i = 0; i < n; i++)
    if (!que.count(i)) {
      for (Edge* pt = info[i]; pt; pt = pt->next)
        if (que.count(pt->to)) return false;
    }

  return true;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif

  while (true) {
    int u;
    while (true) {
      scanf("%d", &u);
      if (u < 0) break;
      insert(n, u);
    }
    if (u == -1) break;
    n++;
  }
  n++;

  vector<int> ansA;
  for (int i = 1; i + 1 < n; i++) {
    ban = i;
    que.clear();
    dfs(0);
    if (!que.count(n - 1)) {
      ansA.push_back(i);
    }
  }
  output(ansA);

  vector<int> ansB;
  for (int i = 0, _i = ansA.size(); i < _i; i++) {
    int v = ansA[i];
    if (check(v)) ansB.push_back(v);
  }
  output(ansB);

  return 0;
}
