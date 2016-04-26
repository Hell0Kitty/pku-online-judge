#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define min(a, b) ((a) > (b) ? (b) : (a))
int pile1 = 0, pile2 = 1;
void drop(int num, int wash[]) {
  if (num != 0) {
    printf("DROP %d %d\n", pile1 + 2, num);
    wash[pile1] = wash[pile1] + num;
  }
}
void take(int num, int wash[]) {
  if (num != 0) {
    printf("TAKE %d %d\n", pile2, num);
  }
  wash[pile2] = wash[pile2] - num;
}
void move(int wash[]) {
  if (wash[pile1] != 0) {
    printf("MOVE %d->%d %d\n", pile1 + 2, pile2, wash[pile1]);
  }
  wash[pile2] = wash[pile2] + wash[pile1];
  wash[pile1] = 0;
}
int main() {
  int wash[2];
  char str[6];
  int total, num, temp, flag = 0;
  while (cin >> num, num) {
    if (flag++) printf("\n");
    wash[0] = 0;
    wash[1] = 0;
    while (num--) {
      cin >> str >> total;
      if (str[0] == 'D')
        drop(total, wash);
      else {
        temp = min(wash[pile2], total);
        take(temp, wash);
        total = total - temp;
        if (total > 0) {
          move(wash);
          take(total, wash);
        }
      }
    }
  }
  return 0;
}
