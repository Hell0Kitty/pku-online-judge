

#include <string.h>
#include <memory.h>

#include <iostream>
#include <memory>
#define MAX_N 105
using namespace std;
#define INT_MIN 0

bool tag[MAX_N + 1][MAX_N + 1][MAX_N + 1];
int dir[5][2] = {{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int res[MAX_N + 1][2];  // -1, all one -2, not unique zero, >=1 unique position
int W, H, T, N, ti, LI, TI, RI, BI, lastT = INT_MIN;

bool inRange(int curH, int curW) {
  return (curH >= 1 && curH <= H && curW >= 1 && curW <= W);
}

// true: this should be zero
bool check(int curH, int curW, int curT, int pT) {
  if (tag[curT][curH][curW]) return false;
  int d, nH, nW;
  for (d = 0; d < 5; d++) {
    nH = curH + dir[d][0];
    nW = curW + dir[d][1];
    if (inRange(nH, nW)) {
      if (!tag[pT][nH][nW]) return false;
    }
  }
  tag[curT][curH][curW] = true;
  return true;
}
int main() {
  int i, r, c, d, seq = 0;
  while (cin >> W >> H >> T && !(W == 0 && H == 0 && T == 0)) {
    cin >> N;
    seq++;
    lastT = INT_MIN;
    memset(tag, false, sizeof(tag));
    for (i = 1; i <= N; i++) {
      cin >> ti >> LI >> TI >> RI >> BI;
      for (r = TI; r <= BI; r++) {
        for (c = LI; c <= RI; c++) tag[ti][r][c] = true;
      }
      if (ti > lastT) lastT = ti;
    }
    bool changed = true;
    for (d = 0; d < 2; d++) {
      for (i = 1; i <= T; i++) {
        for (r = 1; r <= H; r++) {
          for (c = 1; c <= W; c++) {
            if (d == 0 && i != 1)
              check(r, c, i, i - 1);
            else if (d == 1)
              check(r, c, T - i + 1, T - i + 2);
          }
        }
      }
    }
    bool allOne = true, allallOne = true, allMult = true;
    memset(res, 0, sizeof(res));
    for (i = 1; i <= T; i++) {
      allOne = true;
      bool con = true;
      for (r = 1; r <= H && con; r++) {
        for (c = 1; c <= W && con; c++) {
          if (!tag[i][r][c]) {
            allOne = false;
            if (res[i][0] == 0) {
              res[i][0] = r;
              res[i][1] = c;
            } else if (res[i][0] >= 1) {
              res[i][0] = -2;
              con = false;
            }
          }
        }
      }
      if (allOne) {
        res[i][0] = -1;
      } else
        allallOne = false;

      if (res[i][0] != -2) allMult = false;
    }
    cout << "Robbery #" << seq << ":" << endl;
    if (allallOne)
      cout << "The robber has escaped." << endl;
    else if (allMult)
      cout << "Nothing known." << endl;
    else {
      for (i = 1; i <= T; i++) {
        if (res[i][0] >= 1) {
          cout << "Time step " << i << ": ";
          cout << "The robber has been at " << res[i][1] << "," << res[i][0]
               << "." << endl;
        }
      }
    }
    cout << endl;
  }
  return 0;
}