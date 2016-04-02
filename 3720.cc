#include <iostream>
using namespace std;
#define esp 1e-10
int ans[102][11];
int vis[1000];
void getans(int n) {
  int now = 10;
  memset(vis, 0, sizeof(vis));
  while (!vis[now] && now != 0) {
    vis[now] = 1;
    int temp = now / n;
    ans[n][temp]++;
    now %= n;
    now *= 10;
  }
}
int main() {
  memset(ans, 0, sizeof(ans));
  for (int i = 2; i < 101; i++) {
    getans(i);
  }
  int n, k;
  while (scanf("%d%d", &n, &k) != EOF) {
    int sum = 0;
    for (int i = 2; i <= n; i++) sum += ans[i][k];
    cout << sum << endl;
  }
  return 0;
}
