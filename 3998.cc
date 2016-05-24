#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

#define MAXN 100002

inline int mabs(int x) { return x > 0 ? x : -x; }
inline int mmax(int a, int b) { return a > b ? a : b; }
inline int mmin(int a, int b) { return a < b ? a : b; }

int N, K, AVE;
int CP[MAXN];
int sum[MAXN];
int X[MAXN];
int Y[MAXN];
vector<int> v;
int bestRes;

int gcd(int a, int b) {
  while (b > 0) {
    int tmp = a;
    a = b;
    b = tmp % b;
  }

  return a;
}

inline void updateBest(int x) {
  if (x < bestRes) bestRes = x;
}

void DFS(int x, int pos, int F) {
  if (F >= bestRes) return;

  if (pos >= (int)v.size()) {
    F += x * AVE;
    updateBest(F);
    return;
  }

  if (x <= 1) {
    F += mabs(sum[pos] - AVE);
    updateBest(F);
    return;
  }

  int ep = CP[pos];
  DFS(x - 1, ep, F + mabs(sum[pos] - sum[ep] - AVE));
  DFS(x - 1, ep - 1, F + mabs(sum[pos] - sum[ep - 1] - AVE));
}

void solve(int mx, int* cors) {
  v.clear();
  int i;
  for (i = 0; i <= mx; i++) {
    if (cors[i] > 0) v.push_back(cors[i]);
  }
  i = v.size();
  sum[i--] = 0;

  int rangeSum = 0;
  int rangeEnd = v.size() - 1;
  for (; i >= 0; i--) {
    sum[i] = sum[i + 1] + v[i];
    rangeSum += v[i];
    while (rangeSum - v[rangeEnd] >= AVE) {
      rangeSum -= v[rangeEnd];
      rangeEnd--;
    }

    CP[i] = rangeEnd + 1;
  }

  DFS(K, 0, 0);
}

int main() {
  int kase = 0;
  while (scanf("%d %d", &N, &K), N > 0 || K > 0) {
    int x, y;
    int maxx = 0, maxy = 0;
    memset(X, 0, sizeof(X));
    memset(Y, 0, sizeof(Y));

    for (int i = 0; i < N; i++) {
      scanf("%d %d", &x, &y);
      maxx = mmax(maxx, x);
      maxy = mmax(maxy, y);
      X[x] += K;
      Y[y] += K;
    }
    AVE = N;
    N *= K;
    bestRes = N;
    solve(maxx, X);
    solve(maxy, Y);
    int num = bestRes;

    printf("%d. ", ++kase);
    int denom = K * K;
    if (num == 0) {
      denom = 1;
    } else {
      int g = gcd(num, denom);
      num /= g;
      denom /= g;
    }

    printf("%d/%d\n", num, denom);
  }

  return 0;
}
