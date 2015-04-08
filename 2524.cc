#include <iostream>
using namespace std;

int father[50001], rank[50001];

void Init(int n) {
  int i;
  for (i = 1; i <= n; i++) {
    father[i] = i;
    rank[i] = 1;
  }
}

int Find_Set(int x) {
  if (x != father[x]) father[x] = Find_Set(father[x]);
  return father[x];
}

void Union_Set(int x, int y) {
  x = Find_Set(x);
  y = Find_Set(y);
  if (x == y) return;
  if (rank[x] >= rank[y]) {
    father[y] = x;
    rank[x] += rank[y];
  } else {
    father[x] = y;
    rank[y] += rank[x];
  }
}

int main() {
  //  freopen("in.txt", "r", stdin);
  int n, m;
  int i, x, y, c;
  int num = 1;
  while (1) {
    cin >> n >> m;
    if (!n && !m) break;
    Init(n);
    for (i = 0; i < m; i++) {
      cin >> x >> y;
      Union_Set(x, y);
    }
    c = 0;
    for (i = 1; i <= n; i++) {
      if (i == father[i]) c++;
    }
    cout << "Case " << num << ": " << c << endl;
    num++;
  }
  return 0;
}