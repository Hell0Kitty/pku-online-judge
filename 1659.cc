#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 14

struct Node {
  int num, id;
} pp[MAXN];

int n;
int map[MAXN][MAXN];

int cmp(const Node &p, const Node &q) { return p.num > q.num; }

int main() {
  int _case;
  scanf("%d", &_case);
  while (_case--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &pp[i].num);
      pp[i].id = i;
    }
    memset(map, 0, sizeof(map));
    bool flag = true;
    while (true) {
      sort(pp + 1, pp + n + 1, cmp);
      if (pp[1].num == 0) break;
      for (int i = 1; i <= pp[1].num; i++) {
        pp[1 + i].num--;
        if (pp[1 + i].num < 0) flag = false;
        map[pp[1].id][pp[1 + i].id] = map[pp[1 + i].id][pp[1].id] = 1;
      }
      pp[1].num = 0;
      if (!flag) break;
    }
    if (flag) {
      puts("YES");
      for (int i = 1; i <= n; i++) {
        printf("%d", map[i][1]);
        for (int j = 2; j <= n; j++) {
          printf(" %d", map[i][j]);
        }
        printf("\n");
      }
    } else
      puts("NO");
    if (_case) puts("");
  }
  return 0;
}
