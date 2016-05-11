#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
char Mp[30][30];
int dir[8][2] = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
int DFS(int r, int c) {
  if (Mp[r][c] == '.' || Mp[r][c] == 'n') return 0;
  Mp[r][c] = 'n';
  int sum = 0;
  for (int i = 0; i != 4; i++) sum += (Mp[r + dir[i][0]][c + dir[i][1]] == '.');
  for (int i = 0; i != 8; i++) sum += DFS(r + dir[i][0], c + dir[i][1]);
  return sum;
}
int main() {
  int row, col, r, c;
  while (cin >> row >> col >> r >> c && row) {
    memset(Mp, '.', sizeof(Mp));
    for (int i = 1; i <= row; i++)
      for (int j = 1; j <= col; j++) cin >> Mp[i][j];
    cout << DFS(r, c) << endl;
  }
}
