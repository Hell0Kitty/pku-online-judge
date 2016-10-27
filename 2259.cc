#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <cstring>
#include <map>
using namespace std;

const int maxn = 1000 + 5;

int team[999999 + 6];
int main() {
  // freopen("input.txt", "r", stdin);
  int n;
  int kcase = 0;
  char cmd[10];
  int x, t;
  while (scanf("%d", &n) == 1 && n) {
    printf("Scenario #%d\n", ++kcase);
    queue<int> q, q2[maxn];
    for (int i = 0; i < n; i++) {
      scanf("%d", &x);
      while (x--) {
        scanf("%d", &t);
        team[t] = i;
      }
    }
    while (1) {
      scanf("%s", cmd);
      if (strcmp(cmd, "STOP") == 0)
        break;
      else if (strcmp(cmd, "DEQUEUE") == 0) {
        t = q.front();
        printf("%d\n", q2[t].front());
        q2[t].pop();
        if (q2[t].empty()) q.pop();
      } else {
        scanf("%d", &x);
        t = team[x];
        if (q2[t].empty()) q.push(t);
        q2[t].push(x);
      }
    }
    printf("\n");
  }
  return 0;
}
