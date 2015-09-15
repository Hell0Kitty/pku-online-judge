
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 10000;
int sign[10][6] = {1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0,
                   1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,  // 5
                   1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1,
                   1, 1, 1, 1, 0, 1};  //光标移动域
int way[N][8], top;                    //排列与状态、步数
struct Data {
  int ar[6], step, state, pos;  //数列，步数，光标状态
};
bool mark[6][6][6][6][6][6][6][10];  // bfs状态集
void bfs() {
  Data a, b, stk[N];
  int f, r;
  f = r = top = 0;
  for (int i = 0; i < 6; i++) a.ar[i] = i;
  a.step = a.state = a.pos = 0;
  stk[r++] = a;
  memset(mark, false, sizeof(mark));
  mark[a.ar[0]][a.ar[1]][a.ar[2]][a.ar[3]][a.ar[4]][a.ar[5]][a.pos][a.state] =
      true;
  while (f != r) {
    a = stk[f++];
    if (f == N) f = 0;
    for (int i = 0; i < 6; i++) way[top][i] = a.ar[i];
    way[top][6] = a.state;
    way[top++][7] = a.step;
    b = a;
    b.step++;
    if (b.pos > 0) {
      swap(b.ar[0], b.ar[b.pos]);
      if (!mark[b.ar[0]][b.ar[1]][b.ar[2]][b.ar[3]][b.ar[4]][b.ar[5]][b.pos]
               [b.state]) {
        mark[b.ar[0]][b.ar[1]][b.ar[2]][b.ar[3]][b.ar[4]][b.ar[5]][b.pos]
            [b.state] = true;
        stk[r++] = b;
        if (r == N) r = 0;
      }
      swap(b.ar[0], b.ar[b.pos]);
    }
    if (b.pos < 5) {
      int temp = b.state;
      b.pos++;
      if (b.pos > b.state || (b.state > 5 && b.pos > b.state - 6)) {
        if (b.state == 9)
          b.state = 5;
        else
          ++b.state;
      }
      if (!mark[b.ar[0]][b.ar[1]][b.ar[2]][b.ar[3]][b.ar[4]][b.ar[5]][b.pos]
               [b.state]) {
        mark[b.ar[0]][b.ar[1]][b.ar[2]][b.ar[3]][b.ar[4]][b.ar[5]][b.pos]
            [b.state] = true;
        stk[r++] = b;
        if (r == N) r = 0;
      }
      --b.pos;
      b.state = temp;
      swap(b.ar[5], b.ar[b.pos]);
      if (b.state < 5) b.state += 6;
      if (!mark[b.ar[0]][b.ar[1]][b.ar[2]][b.ar[3]][b.ar[4]][b.ar[5]][b.pos]
               [b.state]) {
        mark[b.ar[0]][b.ar[1]][b.ar[2]][b.ar[3]][b.ar[4]][b.ar[5]][b.pos]
            [b.state] = true;
        stk[r++] = b;
        if (r == N) r = 0;
      }
    }
  }
}
int main() {
  bfs();
  int start, end;
  while (scanf("%d%d", &start, &end) != EOF) {
    int a[6], b[6];
    for (int i = 5; i >= 0; i--) {
      a[i] = start % 10;
      b[i] = end % 10;
      start /= 10;
      end /= 10;
    }
    int ans = 1 << 29, st;
    for (int i = 0, j; i < top; i++) {
      st = way[i][7];
      for (j = 0; j < 6; j++) {
        if (a[way[i][j]] != b[j] && !sign[way[i][6]][j])
          break;
        else
          st += abs(a[way[i][j]] - b[j]);
      }
      if (j == 6 && st < ans) ans = st;
    }
    printf("%d\n", ans);
  }
  return 0;
}