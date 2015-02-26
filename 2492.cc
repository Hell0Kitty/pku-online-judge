#include <stdio.h>
#include <queue>
using namespace std;
struct abc {
  int level, j;
};
abc tmp;

int i, j, k, t, a, b, nbug, nint, level, f[2001][2001], bug[2001];
bool sus;

int main() {
  queue<abc> que;
  scanf("%d", &t);
  for (k = 1; k <= t; k++) {
    scanf("%d%d", &nbug, &nint);
    for (i = 0; i <= nbug; i++) {
      f[i][0] = 0;
      bug[i] = -1;
    }
    for (i = 1; i <= nint; i++) {
      scanf("%d%d", &a, &b);
      f[a][++f[a][0]] = b;
      f[b][++f[b][0]] = a;
    }
    sus = false;
    for (j = 1; j <= nbug && !sus; j++) {
      if (bug[j] != -1) continue;
      tmp.j = j;
      tmp.level = 0;
      que.push(tmp);
      bug[j] = 0;
      while (!que.empty()) {
        tmp = que.front();
        que.pop();
        a = tmp.j;
        level = tmp.level;
        if (bug[a] == level % 2) {
          for (i = 1; i <= f[a][0]; i++) {
            if (bug[f[a][i]] == -1) {
              bug[f[a][i]] = (level + 1) % 2;
              tmp.j = f[a][i];
              tmp.level = level + 1;
              que.push(tmp);
            } else if (bug[f[a][i]] == level % 2) {
              sus = true;
              break;
            }
          }
        } else {
          sus = true;
        }
        if (sus) break;
      }
    }
    while (!que.empty()) que.pop();
    if (sus)
      printf("Scenario #%d:\nSuspicious bugs found!\n\n", k);
    else
      printf("Scenario #%d:\nNo suspicious bugs found!\n\n", k);
  }
  return 0;
}
