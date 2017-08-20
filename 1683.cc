#include <iostream>
using namespace std;
struct NODE {
  int a, b;
  int c, d;
  char x;
};
NODE p[100];
char ch[10][10];
int host[10][10];
int t, M, N;
int num;
bool IsOk(int r, int c, int m) {
  int i;
  for (i = 1; i < num; i++) {
    if (r == p[i].a && c == p[i].b && host[p[i].c][p[i].d] != 0) {
      if (p[i].x == 'R') {
        if (host[p[i].c][p[i].d] != m) return false;
      } else {
        if (host[p[i].c][p[i].d] == m) return false;
      }
    }
    if (r == p[i].c && c == p[i].d && host[p[i].a][p[i].b] != 0) {
      if (p[i].x == 'R') {
        if (host[p[i].a][p[i].b] != m) return false;
      } else {
        if (host[p[i].a][p[i].b] == m) return false;
      }
    }
  }
  return true;
}
bool dfs(int k, int m) {
  int i;
  if (m == M + 1) {
    return true;
  }
  for (i = 1; i <= M; i++) {
    if (host[k][i] != 0) continue;
    if (!IsOk(k, i, m)) continue;
    host[k][i] = m;
    if (k == N) {
      if (dfs(1, m + 1)) return true;
    } else {
      if (dfs(k + 1, m)) return true;
    }
    host[k][i] = 0;
  }
  return false;
}
int main() {
  cin >> t;
  while (t--) {
    cin >> N >> M;
    int i, j, k;
    for (i = 1; i <= N; i++) {
      cin >> ch[i];
    }
    num = 1;
    while (true) {
      cin >> p[num].a >> p[num].b;
      cin >> p[num].x;
      cin >> p[num].c >> p[num].d;
      if (p[num].a == 0) break;
      num++;
    }
    memset(host, 0, sizeof(host));
    dfs(1, 1);
    for (i = 1; i <= M; i++) {
      for (j = 1; j <= N; j++) {
        for (k = 1; k <= M; k++) {
          if (host[j][k] == i) cout << ch[j][k - 1];
        }
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
