#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct node {
  int p;  //解题数目
  int s;  //得分
  int y;  //优先级，把Steve的设为最高，在最后排序时使用
  char name[10];  //姓名
};
bool cmp(node a, node b) {
  if (a.p != b.p) return a.p > b.p;  //解题数目多的在前
  if (a.s != b.s) return a.s < b.s;  //得分少的在前
  return a.y < b.y;  //当解题数目和得分相同时，把Steve排在最前面
}
int main() {
  int n, n2, totaltime, num, a[30], i, timeused, testcase = 0;
  node p[3];
  scanf("%d", &n);  //测试组数
  n2 = n;
  while (n2--) {
    testcase++;
    timeused = 0;
    scanf("%d%d", &totaltime, &num);  //比赛时间，题目数量
    memset(p, 0, sizeof(p));
    p[0].y = p[2].y = 1;
    strcpy(p[0].name, "Bill");
    strcpy(p[1].name, "Steve");
    strcpy(p[2].name, "Linus");
    for (i = 0; i < num; i++)  //输入每道题所花费的时间
      scanf("%d", &a[i]);
    for (i = 0; i < num; i++) {  // Bill得分
      timeused = timeused + a[i];
      if (timeused > totaltime) break;
      p[0].p++;
      p[0].s = p[0].s + timeused;
    }
    sort(a, a + num);  //把题目按时间升序
    timeused = 0;
    for (i = 0; i < num; i++) {  // Steve得分
      timeused = timeused + a[i];
      if (timeused > totaltime) break;
      p[1].p++;
      p[1].s = p[1].s + timeused;
    }
    timeused = 0;
    for (i = num - 1; i >= 0; i--) {  // Linus得分
      timeused = timeused + a[i];
      if (timeused > totaltime) break;
      p[2].p++;
      p[2].s = p[2].s + timeused;
    }
    sort(p, p + 3, cmp);  //排序，排完后第一名在p[0]
    printf("Scenario #%d:\n", testcase);
    printf("%s wins with %d solved problems and a score of %d.\n", p[0].name,
           p[0].p, p[0].s);
    if (testcase < n) printf("\n");
  }
  return 0;
}