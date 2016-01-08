#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define pi 3.14159

bool reachable(int x, int y, int z, int &ans) {
  if (360 - z < z) z = 360 - z;
  if (z == 0) {
    ans = y;
    return true;
  }
  double dist = 2 * pi * x * z / 360;
  double fuel_need = dist * 2 / 5;
  if (y >= fuel_need) {
    ans = y - fuel_need;
    return true;
  }
  ans = y * 5;
  return false;
}

int main() {
  char st[20];
  int x, y, z;
  int ans;
  while (1) {
    gets(st);
    if (st[0] == 'E') break;
    scanf("%d%d%d", &x, &y, &z);
    if (reachable(x, y, z, ans))
      printf("YES %d\n", ans);
    else
      printf("NO %d\n", ans);
    gets(st);
    gets(st);
  }
  return 0;
}
