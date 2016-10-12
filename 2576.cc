#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define INF 1000000000
using namespace std;
int dp[22501][51];
int l, m;
int n;
int w[101];
int sum;
void Init() {
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
}

void ZeroOnePack(int weight) {
  for (int i = l; i >= weight; i--) {
    for (int j = m; j >= 1; j--) {
      if (dp[i - weight][j - 1] == 1) dp[i][j] = 1;
    }
  }
}
int main() {
  cin >> n;
  sum = 0;
  Init();
  for (int i = 0; i < n; i++) {
    cin >> w[i];
    sum += w[i];
  }
  l = sum / 2;
  if (sum % 2 == 1) l++;
  m = n / 2;
  for (int i = 0; i < n; i++) {
    ZeroOnePack(w[i]);
  }
  int temp1 = l;
  while (dp[temp1][m] == 0) {
    temp1--;
  }
  if (n % 2 == 1) {
    Init();
    m++;
    for (int i = 0; i < n; i++) {
      ZeroOnePack(w[i]);
    }
    int temp2 = l;
    while (dp[temp2][m] == 0) {
      temp2--;
    }
    if (abs(sum - 2 * temp1) > abs(sum - 2 * temp2)) temp1 = temp2;
  }
  cout << min(temp1, sum - temp1) << " " << max(temp1, sum - temp1) << endl;
  return 0;
}
