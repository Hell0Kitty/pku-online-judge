#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int monthday[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                       {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

bool isleapyear(int y) {
  if (y % 100 == 0 && y % 400 != 0) return false;
  return y % 4 == 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int h, min, s, d, mon, y;
    scanf("%d:%d:%d %d.%d.%d", &h, &min, &s, &d, &mon, &y);
    long long totalsec = h * 3600 + min * 60 + s;
    totalsec = totalsec * 100000 / (3600 * 24);
    printf("%lld:%lld:%lld", totalsec / 10000, totalsec % 10000 / 100,
           totalsec % 100);
    int totalday = 0;
    if (y != 2000)
      totalday = 366 + 365 * (y - 1 - 2000) + (y - 1 - 2000) / 4 -
                 (y - 1 - 2000) / 100 + (y - 1 - 2000) / 400;
    bool leap = isleapyear(y);
    for (int i = 1; i < mon; i++) totalday += monthday[leap][i];
    totalday += d - 1;
    printf(" %d.%d.%d\n", totalday % 100 + 1, totalday % 1000 / 100 + 1,
           totalday / 1000);
  }
  return 0;
}
