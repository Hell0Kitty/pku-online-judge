#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 205;
const int INF = 0x3f3f3f3f;
#define CLR(a, v) memset(a, v, sizeof(a))
template <typename T>
inline T sq(T a) {
  return a * a;
}
struct Point {
  int x, y;
  bool read() {
    if (scanf("%d%d", &x, &y) == -1) return false;
    return x != -1 && y != -1;
  }
  double dist(const Point &rhs) { return sqrt(sq(x - rhs.x) + sq(y - rhs.y)); }
} point[N];
double mp[N][N];
double dist[N];
bool vis[N];
int main() {
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) mp[i][j] = INF;
  int cnt = 0;
  point[cnt++].read();
  point[cnt++].read();
  while (true) {
    if (!point[cnt].read()) break;
    cnt++;
    for (; point[cnt].read(); cnt++)
      mp[cnt][cnt - 1] = mp[cnt - 1][cnt] =
          point[cnt].dist(point[cnt - 1]) / 40000;
  }
  for (int i = 0; i < cnt; i++)
    for (int j = 0; j < i; j++)
      if (mp[i][j] == INF)
        mp[i][j] = mp[j][i] = point[i].dist(point[j]) / 10000;
  for (int i = 0; i < N; i++) dist[i] = INF;
  CLR(vis, false);
  dist[0] = 0;
  for (int i = 0; i < cnt; i++) {
    int x = 1;
    for (int j = 0; j < cnt; j++)
      if (!vis[j] && dist[j] < dist[x]) x = j;
    for (int j = 0; j < cnt; j++) dist[j] = min(dist[j], dist[x] + mp[j][x]);
    if (x == 1) break;
    vis[x] = true;
  }
  printf("%.0f\n", dist[1] * 60);
  return 0;
}
