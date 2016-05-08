#include <stdio.h>
#include <vector>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
struct node {
  int t, r, id, d, m;
  char name[255];
  bool operator<(const node &pos) const {
    if (t != pos.t)
      return t < pos.t;
    else if (r != pos.r)
      return r > pos.r;
    else
      return id < pos.id;
  }
};
vector<node> day[400];

int main() {
  int year, c = 0;
  scanf("%d", &year);
  int time[13];
  time[0] = 0;
  for (int i = 1; i <= 12; i++)
    if (i <= 7 && i % 2 || i > 7 && !(i % 2))
      time[i] = 31;
    else
      time[i] = 30;
  if (year % 4 == 0)
    time[2] = 29;
  else
    time[2] = 28;
  for (int i = 2; i <= 12; i++) time[i] += time[i - 1];
  bool flag = false;
  while (true) {
    char jud[5];
    scanf("%s", jud);
    if (jud[0] == '#')
      break;
    else if (jud[0] == 'A') {
      int d, m, l;
      scanf("%d%d%d", &d, &m, &l);
      char str[300];
      gets(str);
      while (str[0] == ' ')
        for (int i = 0; i < strlen(str); i++) str[i] = str[i + 1];
      for (int i = max(1, time[m - 1] + d - l); i <= time[m - 1] + d; i++) {
        node tmp;
        strcpy(tmp.name, str);
        tmp.id = c;
        tmp.d = d;
        tmp.m = m;
        if (i != time[m - 1] + d)
          tmp.r = l - (time[m - 1] + d - i - 1);
        else
          tmp.r = 8;
        tmp.t = time[m - 1] + d;
        day[i].push_back(tmp);
      }
      for (int i = time[12] + time[m - 1] + d - l; i <= time[12]; i++) {
        node tmp;
        strcpy(tmp.name, str);
        tmp.id = c;
        tmp.d = d;
        tmp.m = m;
        tmp.r = l - (time[m - 1] + d - 1 + time[12] - i + 1 - 1);
        tmp.t = time[m - 1] + d + time[12];
        day[i].push_back(tmp);
      }
      c++;
    } else {
      if (!flag) {
        flag = true;
        for (int i = 0; i <= time[12]; i++) sort(day[i].begin(), day[i].end());
      }
      int d, m;
      scanf("%d%d", &d, &m);
      printf("Today is:%3d%3d\n", d, m);
      for (int i = 0; i < day[time[m - 1] + d].size(); i++) {
        printf("%3d%3d ", day[time[m - 1] + d][i].d, day[time[m - 1] + d][i].m);
        if (day[time[m - 1] + d][i].t == time[m - 1] + d)
          printf("*TODAY*");
        else {
          for (int j = 0; j < day[time[m - 1] + d][i].r; j++) printf("*");
          for (int j = day[time[m - 1] + d][i].r + 1; j < 8; j++) printf(" ");
        }
        printf(" %s\n", day[time[m - 1] + d][i].name);
      }
      printf("\n");
    }
  }
  return 0;
}
