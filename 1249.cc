#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
vector<int> data[100];
int x, y, minx, maxx, miny, maxy;
int GetMin(int pos) {
  int ans = pos / 5 * 5;
  if (ans == pos) ans -= 5;
  return ans;
}
int GetMax(int pos) { return (pos / 5 + 1) * 5; }
int main() {
  int c = 0;
  while (true) {
    scanf("%d%d", &x, &y);
    if (x == 0 && y == 0) break;
    for (int i = 1; i <= 94; i++) data[i].clear();
    data[x].push_back(y);
    minx = maxx = x;
    miny = maxy = y;
    while (true) {
      scanf("%d%d", &x, &y);
      if (x == -1 && y == -1) break;
      data[x].push_back(y);
      minx = min(minx, x);
      maxx = max(maxx, x);
      miny = min(miny, y);
      maxy = max(maxy, y);
    }
    for (int i = minx; i <= maxx; i++) sort(data[i].begin(), data[i].end());
    int total = 0, ans = 1;
    for (y = 1; y <= 73; y++)
      if (y == 1) {
        for (int i = minx; i <= maxx; i++)
          if (!data[i].empty()) {
            if (y >= data[i].front() && y <= data[i].back())
              total = data[i].back() - data[i].front();
            else if (y > data[i].back())
              total = data[i].back() - data[i].front() + y - data[i].back();
            else
              total = data[i].back() - data[i].front() + data[i].front() - y;
          }
        ans = y;
      } else {
        int tmp = total;
        for (int i = minx; i <= maxx; i++)
          if (!data[i].empty()) {
            if (y > data[i].front() && y <= data[i].back())
              ;
            else if (y <= data[i].front())
              tmp--;
            else
              tmp++;
          }
        if (tmp < total) total = tmp, ans = y;
      }

    printf("OIL FIELD %d\n", ++c);
    int left = GetMin(minx), right = GetMax(maxx), down = GetMin(miny),
        up = GetMax(maxy);
    if (right - left > 70 || up - down > 20)
      printf("Map is too big to draw for pipeline at %d\n", ans);
    else {
      char orimap[100][100];
      memset(orimap, '.', sizeof(orimap));
      char *map[100];
      for (int i = 0; i < 100; i++) map[i] = orimap[i];
      // draw left border&right border
      for (int i = down; i <= up; i++) {
        if ((i - down) % 5 == 0) {
          sprintf(map[up - i], "%2d+", i);
          sprintf(&orimap[up - i][right - left + 2], "+");
        } else {
          sprintf(map[up - i], "  |");
          sprintf(&orimap[up - i][right - left + 2], "|");
        }
        map[up - i] += 3;
        *map[up - i] = '.';
      }

      sprintf(orimap[up - down + 1], "  %-5d", left);
      map[up - down + 1] += 7;
      for (int i = left + 1; i < right; i++) {
        if ((i - left) % 5 == 0) {
          sprintf(map[up - down + 1], "%-5d", i);
          map[up - down + 1] += 5;
          *map[up - down] = *map[0] = '+';
        } else {
          *map[up - down] = *map[0] = '-';
        }
        map[up - down]++;
        map[0]++;
      }
      sprintf(map[up - down + 1], "%d", right);

      for (int i = down + 1; i < up; i++) map[up - i] += minx - left - 1;
      for (int i = minx; i <= maxx; i++) {
        if (!data[i].empty())
          for (int j = min(ans, data[i].front()); j <= max(ans, data[i].back());
               j++)
            *map[up - j] = '*';
        for (int j = down + 1; j < up; j++) map[up - j]++;
      }

      for (int i = left + 1; i < right; i++)
        orimap[up - ans][2 + i - left] = '*';

      for (int i = minx; i <= maxx; i++)
        for (int j = 0; j < data[i].size(); j++)
          orimap[up - data[i][j]][i - left + 2] = '@';
      for (int i = up; i >= down - 1; i--)
        printf("%s\n", up < 10 ? orimap[up - i] + 1 : orimap[up - i]);
    }
  }
  return 0;
}
