#include <stdio.h>
#include <memory.h>

#include <iostream>
#include <memory>
#define MAX_N 75
#define Q_SIZE 10000
#define INT_MAX 0x7fffffff

using namespace std;

char map[MAX_N + 5][MAX_N + 5];

int queue[Q_SIZE + 5][4];  // dir up:0, down:1, left:2, right:3
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int head, tail;

int minSeg[MAX_N + 5][MAX_N + 5];
int w, h, x1, y1, x2, y2;
int minLen = INT_MAX;

void initSeg() {
  int i, j;
  for (i = 0; i <= h + 1; i++)
    for (j = 0; j <= w + 1; j++) minSeg[i][j] = INT_MAX;
}

bool inRange(int x, int y) {
  return (x >= 0 && x <= h + 1 && y >= 0 && y <= w + 1 &&
          (map[x][y] == ' ' || (x == x2 && y == y2)));
}
void bfs() {
  head = tail = 1;
  queue[tail][0] = x1;
  queue[tail][1] = y1;
  queue[tail][2] = -1;
  tail = tail % Q_SIZE + 1;
  queue[tail][3] = 0;

  int curX, curY, newX, newY, curDir, curSeg, newSeg;
  while (head != tail) {
    curX = queue[head][0];
    curY = queue[head][1];
    curDir = queue[head][2];
    curSeg = queue[head][3];

    head = head % Q_SIZE + 1;

    if (curX == x2 && curY == y2) {
      if (curSeg < minLen) minLen = curSeg;
      continue;
    }

    for (int d = 0; d < 4; d++) {
      newX = curX + dir[d][0];
      newY = curY + dir[d][1];
      if (newX == x1 && newY == y1) continue;
      if (inRange(newX, newY)) {
        if (curDir == -1)
          newSeg = 1;
        else {
          if (curDir != d)
            newSeg = curSeg + 1;
          else
            newSeg = curSeg;
        }
        if (newSeg <= minSeg[newX][newY])  //Õ¸Ì¼µÊÓÔÒ¼2£
        {
          minSeg[newX][newY] = newSeg;
          queue[tail][0] = newX;
          queue[tail][1] = newY;
          queue[tail][2] = d;
          queue[tail][3] = newSeg;
          tail = tail % Q_SIZE + 1;
        }
      }
    }
  }
}

int main() {
  int i, j, seq = 0;
  char ch;
  while (cin >> w >> h && !(w == 0 && h == 0)) {
    getchar();
    seq++;
    for (i = 0; i <= h + 1; i++) {
      for (j = 0; j <= w + 1; j++) {
        if (i >= 1 && i <= h && j >= 1 && j <= w)
          ch = getchar();
        else
          ch = ' ';
        map[i][j] = ch;
        if (i >= 1 && i <= h && j == w) getchar();
      }
    }
    cout << "Board #" << seq << ":" << endl;
    int qSeq = 0;
    while (cin >> y1 >> x1 >> y2 >> x2 &&
           !(x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0)) {
      minLen = INT_MAX;
      initSeg();
      bfs();
      qSeq++;
      cout << "Pair " << qSeq << ": ";
      if (minLen == INT_MAX)
        cout << "impossible." << endl;
      else
        cout << minLen << " segments." << endl;
    }
    cout << endl;
  }
  return 0;
}