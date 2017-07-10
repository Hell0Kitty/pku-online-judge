#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
typedef struct {
  int num;  //编号，从0开始
  int x;  // x坐标
  int y;  // y坐标
} Point;

int n;
char s[250001];
Point *list;
int ans_len, ans_b, ans_e;
char ans_d;

int cmp_x(const void *a, const void *b) {
  Point *p1, *p2;
  p1 = (Point *)a;
  p2 = (Point *)b;
  if (p1->x != p2->x)
    return p1->x - p2->x;
  else
    return p1->y - p2->y;
}

void findShortcut(char d1, char d2) {
  int len, b, e, s, t;
  char d;

  s = 0;
  t = 1;
  while (s <= n) {
    while (t <= n && list[t].x == list[s].x) t++;
    if (t - s > 1) {
      while (s < t - 1) {
        if (abs(list[s].num - list[s + 1].num) > 1)  //找到一个shortcut
        {
          len = abs(list[s].y - list[s + 1].y);
          if (list[s].num < list[s + 1].num) {
            b = list[s].num;
            e = list[s + 1].num;
            if (list[s].y < list[s + 1].y)
              d = d1;
            else
              d = d2;
          } else {
            b = list[s + 1].num;
            e = list[s].num;
            if (list[s].y < list[s + 1].y)
              d = d2;
            else
              d = d1;
          }

          if (len < ans_len || (len == ans_len && b < ans_b) ||
              (len == ans_len && b == ans_b && e > ans_e)) {
            ans_len = len;
            ans_b = b;
            ans_e = e;
            ans_d = d;
          }
        }
        s++;
      }
    }
    s = t;
    t++;
  }
}

int main() {
  int i, x, y, temp;

  scanf("%d", &n);
  scanf("%s", s);
  //一共有n+1个点
  list = (Point *)malloc(sizeof(Point) * (n + 1));
  // home
  list[0].num = 0;
  list[0].x = 0;
  list[0].y = 0;
  x = y = 0;
  //初始化点
  for (i = 0; i < n; i++) {
    list[i + 1].num = i + 1;
    switch (s[i]) {
      case 'N':
        y++;
        break;
      case 'E':
        x++;
        break;
      case 'S':
        y--;
        break;
      case 'W':
        x--;
        break;
    }
    list[i + 1].x = x;
    list[i + 1].y = y;
  }

  ans_len = 250000;

  //找垂直方向的shortcut
  qsort(list, n + 1, sizeof(Point), cmp_x);
  findShortcut('N', 'S');
  //交换x,y
  for (i = 0; i <= n; i++) {
    temp = list[i].x;
    list[i].x = list[i].y;
    list[i].y = temp;
  }
  //找水平方向的shortcut
  qsort(list, n + 1, sizeof(Point), cmp_x);
  findShortcut('E', 'W');

  printf("%d %d %d %c\n", ans_len, ans_b, ans_e, ans_d);
  return 0;
}