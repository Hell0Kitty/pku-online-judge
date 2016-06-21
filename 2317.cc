#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <set>
using namespace std;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define dd puts("!");
typedef unsigned long long big;
const int N = 202;
char a[N][N], str[N * N], b[N][N];
int n;
char cmd[N];
char stack[N * 4];
int top;
void shake() {
  int i, j;
  for (j = 0; j < n; j++) {
    if (j & 1) {
      for (i = 0; i < n; i++) stack[(i + 1) % n] = a[i][j];
      for (i = 0; i < n; i++) a[i][j] = stack[i];
    } else {
      for (i = 0; i < n; i++) stack[i] = a[(i + 1) % n][j];
      for (i = 0; i < n; i++) a[i][j] = stack[i];
    }
  }
}
void rattle() {
  int i, j;
  for (i = 0; i < n; i++) {
    if (i & 1) {
      for (j = 0; j < n; j++) stack[j] = a[i][(j + 1) % n];
      for (j = 0; j < n; j++) a[i][j] = stack[j];
    } else {
      for (j = 0; j < n; j++) stack[(j + 1) % n] = a[i][j];
      for (j = 0; j < n; j++) a[i][j] = stack[j];
    }
  }
}
void pri() {
  int i, j;
  for (i = 0; i < n; i++, puts(""))
    for (j = 0; j < n; j++) printf("%c", a[i][j]);
  puts("#");
}
void ddd() {
  int i;
  for (i = 0; i < top; i++) printf("%c", stack[i]);
  puts("!");
}
void loop() {
  int k, delta, i, j, l;
  for (l = 0; l + l < n; l++) {
    top = 0;
    for (i = l + 1; i < n - l; i++) stack[top++] = a[l][i];
    for (i = l + 1; i < n - l; i++) stack[top++] = a[i][n - l - 1];
    for (i = n - l - 2; i >= l; i--) stack[top++] = a[n - l - 1][i];
    for (i = n - l - 2; i >= l; i--) stack[top++] = a[i][l];
    if (l & 1)
      delta = 1;
    else
      delta = top - 1;
    k = 0;
    for (i = l + 1; i < n - l; i++) a[l][i] = stack[(k + delta) % top], k++;
    for (i = l + 1; i < n - l; i++)
      a[i][n - l - 1] = stack[(k + delta) % top], k++;
    for (i = n - l - 2; i >= l; i--)
      a[n - l - 1][i] = stack[(k + delta) % top], k++;
    for (i = n - l - 2; i >= l; i--) a[i][l] = stack[(k + delta) % top], k++;
  }
}
int main() {
  int i, j, k, x, y, z, len;
  while (~scanf("%s\n", cmd)) {
    n = (cmd[0] - '0') * 10 + cmd[1] - '0';
    if (!n) n = 100;
    gets(str);
    for (i = 0; str[i]; i++) a[i / n][i % n] = toupper(str[i]);
    x = 0;
    for (; i < n * n; i++) a[i / n][i % n] = 'A' + (x++) % 26;
    for (i = 2; cmd[i]; i++) {
      if (cmd[i] == 'S') shake();
      if (cmd[i] == 'R') rattle();
      if (cmd[i] == 'L') loop();
    }
    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++) printf("%c", a[i][j]);
    puts("");
  }
}
