#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int r, c;
typedef long long ll;
ll map[400][400];
struct Data {
  int x, y;
  ll h;
  bool operator<(const Data &ne) const { return h > ne.h; }
  Data(){};
  Data(int _x, int _y, ll _h) {
    x = _x;
    y = _y;
    h = _h;
  }
};
priority_queue<Data> Q;
int dr[][2] = {0, 1, 0, -1, 1, 0, -1, 0};
bool in(int x, int y) { return x >= 1 && x <= r && y >= 1 && y <= c; }
int main() {
  while (scanf("%d%d", &c, &r) != EOF) {
    for (int i = 1; i <= r; i++) {
      for (int j = 1; j <= c; j++) {
        scanf("%lld", &map[i][j]);
      }
    }
    while (!Q.empty()) Q.pop();
    for (int i = 1; i <= r; i++) {
      Q.push(Data(i, 1, map[i][1]));
      Q.push(Data(i, c, map[i][c]));
      map[i][1] = -1;
      map[i][c] = -1;
    }
    for (int i = 1; i <= c; i++) {
      Q.push(Data(1, i, map[1][i]));
      Q.push(Data(r, i, map[r][i]));
      map[1][i] = -1;
      map[r][i] = -1;
    }
    long long ans = 0;
    while (!Q.empty()) {
      Data a = Q.top(), b;
      Q.pop();
      for (int i = 0; i < 4; i++) {
        b.x = a.x + dr[i][0];
        b.y = a.y + dr[i][1];
        if (in(b.x, b.y)) {
          ll tp = map[b.x][b.y];
          if (tp == -1)
            continue;
          else if (tp < a.h) {
            ans += a.h - tp;
          }
          b.h = max(tp, a.h);
          Q.push(b);
          map[b.x][b.y] = -1;
        }
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
