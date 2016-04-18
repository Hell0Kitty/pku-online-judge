#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <cctype>
#include <set>
#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin())
const int maxn = 10005;
typedef long long LL;
struct Point {
  double x, y;
};
using namespace std;
Point point[12][22];
int t[12];
bool flag[21][21];
bool PtInPolygon(Point p, int num) {
  int nCross = 0;
  for (int i = 0; i < t[num]; i++) {
    Point p1 = point[num][i];
    int tt = (i + 1) % t[num];
    Point p2 = point[num][tt];
    double x1 = min(p1.x, p2.x);
    double x2 = max(p1.x, p2.x);
    double y1 = min(p1.y, p2.y);
    double y2 = max(p1.y, p2.y);
    if ((p.y - p1.y) * (p.x - p2.x) == (p.y - p2.y) * (p.x - p1.x)) {
      if (p.x >= x1 && p.x <= x2 && p.y >= y1 && p.y <= y2) return true;
      continue;
    }
    if (p.y < y1) continue;
    if (p.y > y2 || abs(p.y - y2) < 10e-6) continue;
    double x = (p.y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y) + p1.x;
    if (x > p.x) nCross++;
  }
  return (nCross % 2 == 1);
}
int main() {
  int tt;
  cin >> tt;
  for (int cas = 1; cas <= tt; cas++) {
    int n;
    cin >> n;
    memset(flag, 0, sizeof(flag));
    for (int i = 0; i < n; i++) {
      cin >> t[i];
      for (int j = 0; j < t[i]; j++) {
        int tmp1, tmp2;
        char ch;
        cin >> tmp1 >> ch >> tmp2;
        point[i][j].x = tmp1;
        point[i][j].y = tmp2;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i != j) {
          bool mark = 0;
          for (int k = 0; k < t[i]; k++) {
            if (PtInPolygon(point[i][k], j)) {
              mark = 1;
              break;
            }
          }
          if (mark) {
            flag[i][j] = flag[j][i] = 1;
          }
        }
      }
    }
    bool aflag = 1;
    cout << "Data Set #" << cas << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (flag[i][j]) {
          flag[i][j] = flag[j][i] = 0;
          aflag = 0;
          cout << i + 1 << " " << j + 1 << endl;
        }
      }
    }
    if (aflag) cout << "no collisions" << endl;
  }
  return 0;
}
