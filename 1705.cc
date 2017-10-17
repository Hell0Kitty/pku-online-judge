#include <iostream>
#include <list>
using namespace std;
struct abc {
  int add;
  bool ref;
};
list<abc> a[15];
bool e[15];
int n;

void solve(int s) {
  int i;
  list<abc>::iterator j;
  for (i = 0; i < n; i++)
    for (j = a[i].begin(); j != a[i].end(); j++)
      if (s == j->add) {
        j->ref = true;
        return;  //找到了，set ref，然后返回
      }

  abc now;  //当前地址
  now.add = s;
  now.ref = false;
  for (i = n - 1; i >= 0; i--)  //记录每个队列是否为空
    if (a[i].empty())
      e[i] = true;
    else
      e[i] = false;
  a[n - 1].push_back(now);  //将新的地址加入到最高级队列的尾部
  for (i = n - 1; i >= 0; i--) {
    if (e[i]) continue;    //空的就不用作了
    abc f = a[i].front();  //取出当前队列的头元素
    if (f.ref) {           //如果处理过
      f.ref = false;       //设成没处理
      if (i < n - 1) {     //加到比它高级的队列的尾部
        a[i + 1].push_back(f);
        a[i].pop_front();
      } else {  //本身就是最高级队列
        a[i].push_back(f);
        a[i].pop_front();
      }
    } else {  //加到比它低级的队列的尾部
      if (i > 0) a[i - 1].push_back(f);
      a[i].pop_front();
    }
  }
}

int main() {
  int i, d, sum;
  list<abc>::iterator j;
  char str[15];
  cin >> n;
  while (n != 0) {
    for (i = 0; i < n; i++) a[i].clear();  // list初始化
    cin >> str;
    while (strcmp(str, "#") != 0) {
      cin >> d;
      sum = 0;
      i = 2;
      while (str[i] != 0) {
        int temp = 0;
        if (str[i] >= 'a') str[i] = str[i] - 'a' + 'A';
        if (str[i] >= 'A')
          temp = str[i] - 'A' + 10;
        else
          temp = str[i] - '0';
        sum = sum * 10 + temp;
        i++;
      }
      if (d > 2) d = 2;
      while (d--) {
        solve(sum);
      }
      cin >> str;
    }
    for (i = 0; i < n; i++) {
      cout << i << ":";
      for (j = a[i].begin(); j != a[i].end(); j++)
        cout << " "
             << "0x" << j->add;
      cout << endl;
    }
    cout << endl;
    cin >> n;
  }
  return 0;
}
