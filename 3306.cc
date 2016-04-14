#include <cstdio>
#include <queue>
#include <cstdlib>
#include <vector>
#include <cstring>
using namespace std;
struct Time {
  int s, m, h, ms;
  Time(char *str) {
    h = atoi(strtok(str, ":"));
    m = atoi(strtok(NULL, ":"));
    s = atoi(strtok(NULL, "."));
    ms = atoi(strtok(NULL, "."));
  }
  Time() {}
  void print() {
    printf("%s%d:%s%d:%s%d.", h < 10 ? "0" : "", h, m < 10 ? "0" : "", m,
           s < 10 ? "0" : "", s);
    if (ms < 10)
      printf("00");
    else if (ms < 100)
      printf("0");
    printf("%d", ms);
  }
  bool operator>(const Time &a) const {
    if (h != a.h)
      return h > a.h;
    else if (m != a.m)
      return m > a.m;
    else if (s != a.s)
      return s > a.s;
    else
      return ms > a.ms;
  }
  bool operator!=(const Time &a) const {
    return s != a.s || m != a.m || h != a.h || ms != a.ms;
  }
  Time operator+(const Time &a) {
    Time tmp = *this;
    tmp.ms += a.ms;
    tmp.s += a.s;
    tmp.h += a.h;
    tmp.m += a.m;
    tmp.s += tmp.ms / 1000;
    tmp.ms %= 1000;
    tmp.m += tmp.s / 60;
    tmp.s %= 60;
    tmp.h += tmp.m / 60;
    tmp.m %= 60;
    return tmp;
  }
};
struct Date {
  Time t;
  int y, m, d;
  Date() {}
  Date(char *str, const Time &tt) {
    t = tt;
    d = atoi(strtok(str, "/")) - 1;
    m = atoi(strtok(NULL, "/")) - 1;
    y = atoi(strtok(NULL, "/"));
  }
  void print() {
    printf("%s%d/%s%d/%d ", d + 1 < 10 ? "0" : "", d + 1, m + 1 < 10 ? "0" : "",
           m + 1, y);
    t.print();
  }
  bool operator>(const Date &a) const {
    if (y != a.y)
      return y > a.y;
    else if (m != a.m)
      return m > a.m;
    else if (d != a.d)
      return d > a.d;
    else
      return t > a.t;
  }
  bool operator!=(const Date &a) const {
    return y != a.y || m != a.m || d != a.d || t != a.t;
  }
  bool leap() {
    switch (y % 33) {
      case 1:
        return 1;
      case 5:
        return 1;
      case 9:
        return 1;
      case 13:
        return 1;
      case 17:
        return 1;
      case 22:
        return 1;
      case 30:
        return 1;
      default:
        return 0;
    };
  }
  int maxday() {
    if (m < 6)
      return 31;
    else if (m < 11)
      return 30;
    else
      return leap() ? 30 : 29;
  }
  Date add(const Time &a) {
    Date tmp = *this;
    tmp.t = tmp.t + a;
    tmp.d += tmp.t.h / 24;
    tmp.t.h %= 24;
    tmp.m += tmp.d / maxday();
    tmp.d %= maxday();
    tmp.y += tmp.m / 12;
    tmp.m %= 12;
    return tmp;
  }
};
struct entry {
  bool type;  // 0 起飞 1 降落
  int id;
  Date t1, t2;
  entry() {}
  bool operator<(const entry &a) const {
    if (t1 != a.t1)
      return t1 > a.t1;
    else if (type != a.type)
      return type < a.type;
    else
      return id > a.id;
  }
  void print() {
    printf("%d ", id);
    t1.print();
  }
};

priority_queue<entry> timetable;
int main() {
  int testcase;
  Time ten;
  ten.h = ten.s = ten.ms = 0;
  ten.m = 10;
  scanf("%d", &testcase);
  for (int test = 1; test <= testcase; test++) {
    int num, left;
    printf("Report for Test-Case #%d:\n", test);
    scanf("%d%d", &num, &left);
    while (num--) {
      char date[255], time[255];
      entry tmp;
      tmp.type = 0;
      scanf("%d %s %s", &tmp.id, date, time);
      tmp.t1 = Date(date, Time(time));
      scanf("%s", time);
      tmp.t2 = tmp.t1.add(Time(time));
      timetable.push(tmp);
    }
    while (!timetable.empty()) {
      entry top = timetable.top();
      timetable.pop();
      if (top.type == 1) {
        top.print();
        printf(" LANDED\n");
        left++;
      } else {
        if (left > 0) {
          left--;
          top.print();
          printf(" ACCEPTED\n");
          top.t1 = top.t2;
          top.type = 1;
          timetable.push(top);
        } else {
          top.print();
          printf(" POSTPONED\n");
          top.t1 = top.t1.add(ten);
          top.t2 = top.t2.add(ten);
          timetable.push(top);
        }
      }
    }
    printf("\n");
  }
  return 0;
}
