#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int id[1001], dp[6][6][6][6][6];
pair<int, int> Price[6];  // num and price
int N, M;
struct {
  int m[6];
  int w;
} offer[200];

int getmin(int a, int b, int c, int d, int e) {
  if (a < 0 || b < 0 || c < 0 || d < 0 || e < 0) return 2000000;
  if (dp[a][b][c][d][e] != -1) return dp[a][b][c][d][e];
  dp[a][b][c][d][e] = 2000000;
  for (int i = 0; i < M; i++) {
    dp[a][b][c][d][e] =
        min(dp[a][b][c][d][e],
            offer[i].w + getmin(a - offer[i].m[0], b - offer[i].m[1],
                                c - offer[i].m[2], d - offer[i].m[3],
                                e - offer[i].m[4]));
  }
  return dp[a][b][c][d][e];
}

int main() {
  int i, j, k;
  int t, tt, no = 0, t2;
  scanf("%d", &N);

  memset(Price, 0, sizeof(Price));
  memset(dp, -1, sizeof(dp));
  memset(offer, 0, sizeof(offer));

  for (i = 0; i < N; i++) {
    scanf("%d", &t);
    id[t] = i;
    scanf("%d %d", &Price[i].first, &Price[i].second);
    offer[i].m[i] = 1;
    offer[i].w = Price[i].second;
  }

  scanf("%d", &M);
  for (i = N; i < N + M; i++) {
    scanf("%d", &t);
    for (j = 0; j < t; j++) {
      scanf("%d", &tt);
      scanf("%d", &t2);
      offer[i].m[id[tt]] += t2;
    }
    scanf("%d", &offer[i].w);
  }

  M += N;
  dp[0][0][0][0][0] = 0;

  if (M == N) {
    int ans = 0;
    for (i = 0; i < 5; i++) ans += Price[i].first * Price[i].second;
    printf("%d\n", ans);
  } else
    printf("%d\n", getmin(Price[0].first, Price[1].first, Price[2].first,
                          Price[3].first, Price[4].first));
  return 0;
}
