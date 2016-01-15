#include <stdio.h>
#include <iostream>
using namespace std;
char a[10][81];
int n, r, c;  // n--num of symbols, r/c--num of rows/cols in each grid
int upper_bound;
bool search(int x) {
  int begin = x * (c + 1);
  int end = begin + c - 1;  // inclusive
  for (int i = 0; i < r; i++) {
    for (int j = begin; j <= end; j++) {
      if (a[i][j] == 'o') {
        int k = j;  // forward,backward
        while (k >= c + 1) {
          k -= (c + 1);
        }
        for (; k <= upper_bound; k += c + 1) {
          if (a[i][k] != '.' && k != j) {
            break;
          }
        }
        if (k <= upper_bound) {  // find another
          continue;
        } else {
          a[i][j] = '#';
          return true;
        }
      }
    }
  }
  // check 2#...
  //
  for (int i = 0; i < r; i++) {
    for (int j = begin; j <= end; j++) {
      if (a[i][j] != 'o') {
        continue;
      }
      for (int s = i; s < r; s++) {
        for (int t = (s == i ? j + 1 : begin); t <= end; t++) {
          if (a[s][t] != 'o') {
            continue;
          }
          int k1 = j, k2 = t;  // forward,backward
          while (k1 >= c + 1) {
            k1 -= (c + 1);
            k2 -= (c + 1);
          }
          for (; k1 <= upper_bound; k1 += c + 1, k2 += c + 1) {
            if (a[i][k1] != '.' && a[s][k2] != '.' && k1 != j) {
              break;
            }
          }
          if (k1 <= upper_bound) {  // find another
            continue;
          } else {
            a[i][j] = '#';
            a[s][t] = '#';
            return true;
          }
        }
      }
    }
  }
  return false;
}
int main() {
  int i;
  int cnt = 1;
  while (scanf("%d%d%d\n", &n, &r, &c) != EOF && n != 0) {
    printf("Test %d\n", cnt++);
    upper_bound = (c + 1) * (n - 1) + c - 1;  // last element
    for (i = 0; i < r; i++) {
      fgets(a[i], 81, stdin);
    }
    for (i = 0; i < n; i++) {
      if (!search(i)) {  // check whether symbol i has unique #
        printf("impossible\n");
        break;
      }
    }
    if (i == n) {
      for (i = 0; i < r; i++) {
        printf("%s", a[i]);
      }
    }
  }
  return 0;
}
