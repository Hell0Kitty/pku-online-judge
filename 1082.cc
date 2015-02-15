#include <iostream>
#include <stdio.h>

#include <memory.h>
using namespace std;

struct Date {
  int y, m, d;
} date;

bool state[102][13][32];
bool leapFlag;
int month[] = {31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leapYear(int y)  //是否为闰年
{
  if (y % 4 == 0) {
    if (y % 400 != 0) return false;
    return true;
  }
  return false;
}

bool getDayBefore()  //获取前一天的日期
{
  bool loopFlag = true;
  if (date.d > 1) {
    date.d--;
    return loopFlag;
  }
  if (date.m == 3) {
    date.m--;
    if (leapFlag)
      date.d = 29;
    else
      date.d = 28;
  } else if (date.m == 1) {
    date.y--;
    date.m = 12;
    date.d = month[12];
    loopFlag = false;
  } else {
    date.m--;
    date.d = month[date.m];
  }
  return loopFlag;
}

bool isValidNextMonth()  //判断下个月的这天是否有效
{
  //<span style="white-space:pre">  </span>
  if (date.y >= 101 && ((date.m == 10 && date.d > 4) || (date.m > 10)))
    return false;
  if (date.d <= month[(date.m + 1) % 12])
    return true;  //将month[0]=31 便可用 %12
  if (leapFlag && date.m == 1 && date.d < 30) return true;
  return false;
}

void init() {
  memset(state, 0, 102 * 13 * 32);
  date.y = 101;
  date.m = 11;
  date.d = 3;
  Date time = {101, 11, 4};
  bool loopFlag;
  while (date.y >= 0) {
    leapFlag = is_leapYear(date.y + 1900);
    loopFlag = true;
    while (loopFlag) {
      if (!state[time.y][time.m][time.d]) {
        state[date.y][date.m][date.d] = true;
      } else {
        if (isValidNextMonth()) {
          if (date.m == 12) {
            if (!state[date.y + 1][1][date.d])
              state[date.y][date.m][date.d] = true;
          } else if (!state[date.y][date.m + 1][date.d])
            state[date.y][date.m][date.d] = true;
        }
      }
      time = date;
      loopFlag = getDayBefore();
    }
  }
}

int main() {
  // freopen("in.txt","r",stdin);
  int i, n;
  int y, m, d;
  cin >> n;
  init();
  for (i = 0; i < n; i++) {
    cin >> y >> m >> d;
    if (state[y - 1900][m][d])
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}