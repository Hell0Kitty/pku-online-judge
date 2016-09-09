#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <map>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 1e6 + 10;
const int INF = 0x3f3f3f3f;
struct NODEb {
  char ch, col;
  int pow, row;
} nodeb[1000];
struct NODEw {
  char ch, col;
  int pow, row;
} nodew[1000];
int a[50][50];
string s[16];
string ss[16];

bool cmpb(NODEb x, NODEb y) {
  if (x.pow == y.pow) {
    if (x.row == y.row)
      return x.col < y.col;
    else
      return x.row < y.row;
  }
  return x.pow < y.pow;
}

bool cmpw(NODEw x, NODEw y) {
  if (x.pow == y.pow) {
    if (x.row == y.row)
      return x.col < y.col;
    else
      return x.row > y.row;
  }
  return x.pow < y.pow;
}

void work(void) {
  for (int i = 1; i <= 8; ++i) {
    int k = 0;
    for (int j = 2; j < 33; j += 4) {
      ++k;
      switch (s[i][j]) {
        case 'K':
          a[i][k] = 1;
          break;
        case 'Q':
          a[i][k] = 2;
          break;
        case 'R':
          a[i][k] = 3;
          break;
        case 'B':
          a[i][k] = 4;
          break;
        case 'N':
          a[i][k] = 5;
          break;
        case 'P':
          a[i][k] = 6;
          break;
        case 'k':
          a[i][k] = -1;
          break;
        case 'q':
          a[i][k] = -2;
          break;
        case 'r':
          a[i][k] = -3;
          break;
        case 'b':
          a[i][k] = -4;
          break;
        case 'n':
          a[i][k] = -5;
          break;
        case 'p':
          a[i][k] = -6;
          break;
        case ':':
          a[i][k] = 0;
          break;
        case '.':
          a[i][k] = 0;
          break;
        default:
          break;
      }
    }
  }
  int tb = 0, tw = 0;
  for (int i = 1; i <= 8; ++i) {
    for (int j = 1; j <= 8; ++j) {
      if (a[i][j] > 0) {
        nodeb[++tb].pow = a[i][j];
        nodeb[tb].row = 9 - i;
        nodeb[tb].col = 'a' + j - 1;
        switch (a[i][j]) {
          case 1:
            nodeb[tb].ch = 'K';
            break;
          case 2:
            nodeb[tb].ch = 'Q';
            break;
          case 3:
            nodeb[tb].ch = 'R';
            break;
          case 4:
            nodeb[tb].ch = 'B';
            break;
          case 5:
            nodeb[tb].ch = 'N';
            break;
          // case 6: nodeb[tb].ch = 'P'; break;
          default:
            break;
        }
      }
      if (a[i][j] < 0) {
        nodew[++tw].pow = -a[i][j];
        nodew[tw].row = 9 - i;
        nodew[tw].col = 'a' + j - 1;
        switch (a[i][j]) {
          case -1:
            nodew[tw].ch = 'K';
            break;
          case -2:
            nodew[tw].ch = 'Q';
            break;
          case -3:
            nodew[tw].ch = 'R';
            break;
          case -4:
            nodew[tw].ch = 'B';
            break;
          case -5:
            nodew[tw].ch = 'N';
            break;
          default:
            break;
        }
      }
    }
  }

  sort(nodeb + 1, nodeb + 1 + tb, cmpb);
  sort(nodew + 1, nodew + 1 + tw, cmpw);

  cout << "White: ";
  for (int i = 1; i <= tb; ++i) {
    if (nodeb[i].pow != 6) cout << nodeb[i].ch;
    cout << nodeb[i].col << nodeb[i].row;
    if (i != tb) cout << ',';
  }
  cout << endl;
  cout << "Black: ";
  for (int i = 1; i <= tw; ++i) {
    if (nodew[i].pow != 6) cout << nodew[i].ch;
    cout << nodew[i].col << nodew[i].row;
    if (i != tw) cout << ',';
  }
  cout << endl;
}

int main(void) {
  for (int i = 1; i <= 8; ++i) {
    cin >> ss[i];
    cin >> s[i];
  }
  cin >> ss[9];
  work();

  return 0;
}
