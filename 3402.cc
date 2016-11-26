#include <iostream>

struct t {
  int x, y;
} data[2][700];

int main() {
  using namespace std;
  char flag[27][27], temp[4];
  int row, column, i, j, k, max, max_x, max_y, x1, x2, y1, y2, safe, count,
      left;
  cin >> row >> column >> k;
  for (i = 1; i <= row; i++) {
    for (j = 1; j <= column; j++) {
      flag[i][j] = 0;
    }
  }
  while (k > 0) {
    k--;
    cin >> temp;
    x1 = temp[0] - 'a' + 1;
    y1 = temp[1] - '0';
    if (temp[2] != '\0') y1 = y1 * 10 + temp[2] - '0';
    flag[x1][y1] = 2;  // occupied
    for (x2 = 1; x2 <= row; x2++) {
      for (y2 = 1; y2 <= column; y2++) {
        if (flag[x2][y2] == 0)
          if (x1 == x2 || y1 == y2 || (x1 - y1) == (x2 - y2) ||
              (x1 + y1) == (x2 + y2))
            flag[x2][y2] = 1;
      }
    }
  }
  safe = 0;
  count = 0;
  for (i = 1; i <= row; i++) {
    for (j = 1; j <= column; j++) {
      if (flag[i][j] != 2) {
        if (flag[i][j] == 0) {
          data[0][safe].x = i;
          data[0][safe].y = j;
          safe++;
        }
        data[1][count].x = i;
        data[1][count].y = j;
        count++;
      }
    }
  }
  max = -1;
  for (i = 0; i < count; i++) {
    x1 = data[1][i].x;
    y1 = data[1][i].y;
    left = safe;
    for (j = 0; j < safe; j++) {
      x2 = data[0][j].x;
      y2 = data[0][j].y;
      if (x1 == x2 || y1 == y2 || (x1 - y1) == (x2 - y2) ||
          (x1 + y1) == (x2 + y2))
        left--;
    }
    if (left > max) {
      max = left;
      max_x = x1;
      max_y = y1;
    } else {
      if (left == max) {
        if (max_x > x1) {
          max_x = x1;
          max_y = y1;
        }
        if (max_x == x1) {
          if (max_y < 10 && y1 >= 10 && y1 / 10 < max_y) max_y = y1;
        }
      }
    }
  }
  cout << (char)(max_x + 'a' - 1) << max_y << endl
       << max << endl;
  return 0;
}
