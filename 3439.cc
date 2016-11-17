#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
using namespace std;

int n, start, en;
double len1, len2;
struct point {
  double x, y;
  int num;
} points[1010];
double getdis(int i, int j) {
  return sqrt((points[i].x - points[j].x) * (points[i].x - points[j].x) +
              (points[i].y - points[j].y) * (points[i].y - points[j].y));
}
int que[10100];
bool rem[1010];
int main() {
  int t;
  cin >> t;
  while (t--) {
    memset(rem, 0, sizeof rem);
    scanf("%d%d%d%lf%lf", &n, &start, &en, &len1, &len2);
    start--, en--;
    for (int i = 0; i < n; i++)
      scanf("%lf%lf", &points[i].x, &points[i].y), points[i].num = 0;
    que[0] = start;
    rem[start] = 1;
    int left = 0, right = 1;
    while (left < right) {
      int t = que[left];
      left++;
      bool flag = true;
      for (int i = 0; i < n; i++) {
        if (!rem[i] && getdis(i, t) <= len1 + len2) {
          que[right++] = i, points[i].num = points[t].num + 1;
          if (i == en) flag = false;
          rem[i] = 1;
        }
      }
      if (!flag) break;
    }
    if (left >= right)
      cout << "Impossible\n";
    else
      cout << points[en].num << endl;
  }
  return 0;
}
