#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <stack>
#define ll long long
#define oo 1000000000
#define pi acos(-1)
using namespace std;
int w, h, move[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
char arc[105][105];
bool ok(char c) {
  int y, x, yy, xx, i, j, k;
  for (y = 1; y <= h; y++)
    for (x = 1; x <= w; x++)
      if (arc[y][x] == c) goto A;
A:
  ;
  if (y > h) return false;
  k = 0;
  if (arc[move[k][0] + y][move[k][1] + x] != c) k++;
  k %= 4;
  j = y + move[k][0];
  i = x + move[k][1];
  while (x != i || y != j) {
    if (arc[j][i] != c) return false;
    if (arc[move[k][0] + j][move[k][1] + i] != c) {
      k++;
      if (k == 2) {
        yy = j;
        xx = i;
      }
    }
    k %= 4;
    j = j + move[k][0];
    i = i + move[k][1];
  }
  for (i = y + 1; i < yy; i++)
    for (j = x + 1; j < xx; j++)
      if (arc[i][j] != '.') return false;
  return true;
}
int main() {
  int i, j;
  char c;
  while (~scanf("%d%d", &h, &w)) {
    if (!h && !w) break;
    for (i = 0; i <= h + 1; i++) arc[i][0] = arc[i][w + 1] = '?';
    for (i = 0; i <= w + 1; i++) arc[0][i] = arc[h + 1][i] = '?';
    for (i = 1; i <= h; i++) scanf("%s", arc[i] + 1);
    for (c = 'A'; c <= 'Z'; c++)
      if (ok(c)) printf("%c", c);
    printf("\n");
  }
  return 0;
}
