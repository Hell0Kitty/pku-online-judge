#include <cstdlib>
#include <cstring>
#include <cstdio>
#define MAXN 10000
using namespace std;

int N, M, d, p[600005];
int hash[10005], path[10005];

void pre() {
  int k;
  for (int i = 4; i <= MAXN; i += 2) {
    p[i] = 1;
  }
  for (int i = 3; i <= 105; i += 2) {
    if (!p[i]) {
      k = 2 * i;
      for (int j = i * i; j <= MAXN; j += k) {
        p[j] = 1;
      }
    }
  }
}

bool dfs(int x, int step) {
  path[step] = x;
  if (step >= 2) {
    int sum = path[step], k = step > d ? d : step;
    for (int i = step - 1; i > step - k; --i) {
      sum += path[i];
      if (!p[sum]) {
        return false;
      }
    }
    if (step == M - N + 1) {
      for (int i = 1; i <= M - N + 1; ++i) {
        printf(i == 1 ? "%d" : ",%d", path[i]);
      }
      puts("");
      return true;
    }
  }
  for (int i = N; i <= M; ++i) {
    if (!hash[i]) {
      hash[i] = 1;
      if (dfs(i, step + 1)) {
        return true;
      }
      hash[i] = 0;
    }
  }
  return false;
}

int main() {
  int flag;
  pre();
  while (scanf("%d %d %d", &N, &M, &d), N | M | d) {
    if (N > M) {
      int t = N;
      N = M;
      M = t;
    }
    flag = 0;
    memset(hash, 0, sizeof(hash));
    for (int i = N; i <= M; ++i) {
      hash[i] = 1;
      if (dfs(i, 1)) {
        flag = 1;
        break;
      }
      hash[i] = 0;
    }
    if (!flag) {
      puts("No anti-prime sequence exists.");
    }
  }
  return 0;
}
