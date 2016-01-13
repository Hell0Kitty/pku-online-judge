#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#define inf 1e-8
using namespace std;
int n;
struct rectangle  //存储矩形
    {
  double x, y;
  double m, n, z;
} data[105];
struct node  //存储点与答案
    {
  double x, y, z;
} data2[420], ans[105];
struct line  //存储竖线
    {
  double x, y, m, n, z;
} data3[210];
bool findl(node a, line b, node& temp)  //寻找直线temp 若不存在返回false
{
  if (a.z == b.z) return false;
  temp.y = b.z * a.y / a.z;
  temp.z = b.z;
  temp.x = b.x;
  if (temp.y - b.y > -inf && temp.y - b.n < inf) return true;
  return false;
}
bool solve(node a, node b, rectangle c,
           node& temp)  //解决直线是否与矩形相交 不相交返回false
{
  if (a.z == c.z) {
    temp = a;
    return true;
  }
  if (b.z == c.z) {
    temp = b;
    return true;
  }
  temp.x = (c.z - b.z) * (b.x - a.x) / (b.z - a.z) + b.x;
  temp.y = (c.z - b.z) * (b.y - a.y) / (b.z - a.z) + b.y;
  temp.z = c.z;
  if (temp.x - c.x > -inf && c.m - temp.x > -inf && temp.y - c.y > -inf &&
      c.n - temp.y > -inf)
    return true;
  return false;
}
int main() {
  int i, j, k, flag;
  node temp, a;
  // freopen("in.txt","r",stdin);
  while ((scanf("%d", &n)) != EOF) {
    for (i = 0; i < n; i++) {
      scanf("%lf%lf%lf%lf%lf", &data[i].x, &data[i].y, &data[i].m, &data[i].n,
            &data[i].z);
      data3[i * 2].x = data2[i * 4].x = data[i].x;
      data3[i * 2].y = data2[i * 4].y = data[i].y;
      data3[i * 2].m = data2[i * 4 + 1].x = data[i].x;
      data3[i * 2].n = data2[i * 4 + 1].y = data[i].n;
      data3[i * 2 + 1].x = data2[i * 4 + 2].x = data[i].m;
      data3[i * 2 + 1].y = data2[i * 4 + 2].y = data[i].y;
      data3[i * 2 + 1].m = data2[i * 4 + 3].x = data[i].m;
      data3[i * 2 + 1].n = data2[i * 4 + 3].y = data[i].n;
      data3[i * 2].z = data3[i * 2 + 1].z = data2[i * 4].z =
          data2[i * 4 + 1].z = data2[i * 4 + 2].z = data2[i * 4 + 3].z =
              data[i].z;
    }
    flag = 0;
    for (i = 0; i < n * 4; i++) {
      for (j = 0; j < n * 2; j++) {
        if (findl(data2[i], data3[j], temp)) {
          a = data2[i];
          for (k = 0; k < n; k++) {
            if (!solve(a, temp, data[k], ans[k])) break;
            if (k == n - 1) {
              flag = 1;
              break;
            }
          }
        }
        if (flag == 1) break;
      }
      if (flag == 1) break;
    }
    if (flag == 1) {
      printf("SOLUTION\n");
      printf("%.6f\n", temp.x - (temp.z * (a.x - temp.x) / (a.z - temp.z)));
      for (i = 0; i < n; i++) {
        printf("%.6f %.6f %.6f\n", ans[i].x, ans[i].y,
               ans[i].z);  // G++要用%f 不用%lf
      }
    } else
      printf("UNSOLVABLE\n");
  }
  return 0;
}
