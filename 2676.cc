#include <cstdio>
using namespace std;
int v[100][2], a[10][10], num, flag;
bool judge(int x, int y, int k) {
  for (int i = 0; i < 9; i++) {
    if (a[x][i] == k) return 0;
    if (a[i][y] == k) return 0;
  }
  int tx = (x / 3) * 3;
  int ty = (y / 3) * 3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (a[i + tx][j + ty] == k) return 0;
    }
  }
  return 1;
}

void dfs(int cap) {
  if (cap < 0) {
    flag = 1;
    return;
  }
  for (int i = 1; i <= 9; i++) {
    int x, y;
    x = v[cap][0];
    y = v[cap][1];
    if (judge(x, y, i)) {
      a[x][y] = i;
      dfs(cap - 1);
      if (flag) return;
      a[x][y] = 0;
    }
  }
  return;
}

int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    flag = 0, num = 0;
    char c;
    for (int i = 0; i < 9; i++) {
      getchar();
      for (int j = 0; j < 9; j++) {
        scanf("%c", &c);
        a[i][j] = c - '0';
        if (a[i][j] == 0) {
          v[num][0] = i;
          v[num++][1] = j;
        }
      }
    }
    dfs(num - 1);
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        printf("%d", a[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}
