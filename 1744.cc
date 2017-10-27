#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;
bool vis[30005];
int max_fl;
bool judge(int t) {
  int i, j;
  int num = 0;         //电梯已停靠次数
  i = t / 20 + 2;      //在t时间内，t/20+2层以下的人可以走楼梯
  while (i <= max_fl)  //每次把i作为最后一个人的目标楼层
  {
    while (i <= max_fl && !vis[i])  //将i增加至某个人要去的目标楼层
      i++;
    if (10 * num + 4 * (i - 1) > t)
      return false;  //最后一个人到达目标楼层所用时间超过t，则这个t不可取，返回
    j = (t - 10 * num + 20 * i + 4) /
        24;  //设在j层停，此时j>i，因为把i作为最后一个人的目标楼层，则满足等式t-10*num-4(j-1)-20*(j-i)=0
    i = (t - 10 * num + 16 * j + 4) / 20 +
        1;  //这时i为满足等式t-10*num-4(j-1)-20(i-j)=0的下一个楼层的位置，此时i>j
    num++;  //停靠次数+1
  }
  return true;
}
int main() {
  int n, fl;
  while (cin >> n, n) {
    max_fl = 0;
    memset(vis, false, sizeof(vis));
    while (n--) {
      cin >> fl;
      vis[fl] = true;
      max_fl = max(max_fl, fl);
    }
    int low = 0, high = 20 * (max_fl - 1);
    int mid;
    while (low <= high) {
      mid = (low + high) >> 1;
      if (judge(mid))
        high = mid - 1;
      else
        low = mid + 1;
    }
    cout << low << endl;
  }
  return 0;
}