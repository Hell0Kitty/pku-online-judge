#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxl 105

int ans;

int cal(char ch, int d) {
  if (ch == 'Y') return max(500, d);
  if (ch == 'B') return int(1.5 * d + 0.5);
  return 2 * d;
}

void input() {
  char name1[maxl], name2[maxl], type[maxl];
  int dist;
  while (true) {
    scanf("%s", name1);
    if (strcmp(name1, "0") == 0) return;
    if (strcmp(name1, "#") == 0) exit(0);
    scanf("%s%d%s", name2, &dist, type);
    ans += cal(type[0], dist);
  }
}

int main() {
  while (1) {
    ans = 0;
    input();
    printf("%d\n", ans);
  }
  return 0;
}
