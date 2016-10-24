#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef struct e {
  int data;
  vector<int> a;
} e;

e edge[1501];
int dp[1501][2];
int v[1501][2];
int n;
int solve(int);

int solve1(int s) {
  int i, j, k;
  if (v[s][1]) return dp[s][1];
  v[s][1] = 1;
  dp[s][1] = 1;
  k = edge[s].a.size();
  for (i = 0; i < k; i++) {
    j = edge[s].a[i];
    dp[s][1] += solve(j);
  }
  return dp[s][1];
}

int solve(int s) {
  int i, j, k, t = 0;
  if (v[s][0]) return dp[s][0];
  v[s][0] = 1;
  k = edge[s].a.size();
  for (i = 0; i < k; i++) {
    j = edge[s].a[i];
    t += solve1(j);
  }
  dp[s][0] = min(solve1(s), t);
  return dp[s][0];
}

void read() {
  int i, j, k, s, t;
  char c;
  while (scanf("%d", &n) != EOF) {
    for (i = 0; i <= n; i++) {
      edge[i].data = i;
      edge[i].a.clear();
    }
    int start;
    for (i = 1; i <= n; i++) {
      scanf("%d:(%d)", &j, &k);
      if (i == 1) start = j;
      for (s = 1; s <= k; s++) {
        scanf("%d", &t);

        edge[j].a.push_back(t);
      }
    }
    memset(v, 0, sizeof(v));
    cout << solve(start) << endl;
  }
}

int main() {
  read();
  return 0;
}
