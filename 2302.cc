#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <queue>

#define MAXN (10 + 10)

#define mmst(a, b) memset(a, b, sizeof(a))
#define mmcya(a, b) memcpy(a, b, sizeof(a))
#define mmcyb(a, b) memcpy(a, b, sizeof(b))

using namespace std;

int MAP[MAXN][MAXN];

int R[MAXN * MAXN], C[MAXN * MAXN];

int que[MAXN * MAXN];

void Init() {
  int i, j;
  for (i = 1; i <= 75; i++) R[i] = C[i] = -1;
  for (i = 1; i <= 5; i++)
    for (j = 1; j <= 5; j++) {
      if (i == 3 && j == 3) continue;
      int tmp;
      scanf("%d", &tmp);
      R[tmp] = i;
      C[tmp] = j;
    }
  mmst(MAP, 0);
  MAP[3][3] = 1;
  for (i = 1; i <= 75; i++) scanf("%d", &que[i]);
}

bool Check() {
  int i, j;
  bool yes;
  for (i = 1; i <= 5; i++) {
    yes = 1;
    for (j = 1; j <= 5; j++) {
      if (!MAP[i][j]) {
        yes = 0;
        break;
      }
    }
    if (yes) return 1;
  }
  for (i = 1; i <= 5; i++) {
    yes = 1;
    for (j = 1; j <= 5; j++) {
      if (!MAP[j][i]) {
        yes = 0;
        break;
      }
    }
    if (yes) return 1;
  }
  yes = 1;
  for (i = 1; i <= 5; i++)
    if (!MAP[i][i]) {
      yes = 0;
      break;
    }
  if (yes) return 1;
  yes = 1;
  for (i = 1; i <= 5; i++)
    if (!MAP[i][5 - i + 1]) {
      yes = 0;
      break;
    }
  if (yes) return 1;
  return 0;
}

void Solve() {
  int i;
  for (i = 1; i <= 75; i++) {
    int u = que[i];
    if (R[u] == -1) continue;
    MAP[R[u]][C[u]] = 1;
    if (Check()) break;
  }
  printf("BINGO after %d numbers announced\n", i);
}

int main() {
  int Case;
  for (scanf("%d", &Case); Case--;) {
    Init();
    Solve();
  }
  return 0;
}
