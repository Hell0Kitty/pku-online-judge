#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

multiset<int> s;  //增加cost的储存
vector<int> v;    //删除cost的储存
multiset<int>::iterator it;
int policy;

void a()  //增加
{
  int cost;
  cin >> cost;
  s.insert(cost);
}

void re(int pp)  //删除
{
  if (pp == 1) {
    if (s.empty())
      cout << "-1" << endl;
    else {
      it = s.begin();
      v.push_back((*it));
      s.erase(it);
    }
  } else if (pp == 2) {
    if (s.empty())
      cout << "-1" << endl;
    else {
      int size = s.size();
      for (it = s.begin(); it != s.end(); it++) {
        size--;
        if (size == 0) {
          break;
        }
      }
      v.push_back((*it));
      s.erase(it);
    }
  }
}

void p()  // policy的类型
{
  int p;
  cin >> p;
  policy = p;
}

int main() {
  int maxcost, len, i, count;
  char request;
  bool flag;
  while (cin >> maxcost >> len) {
    int *r = new int[len];
    for (i = 0; i < len; i++) cin >> r[i];
    flag = false;
    s.clear();
    v.clear();
    count = 0;
    policy = 1;
    while (1) {
      cin >> request;
      if (request == 'a') {
        a();
      } else if (request == 'r') {
        re(policy);
      } else if (request == 'p') {
        p();
      } else if (request == 'e') {
        flag = true;
        break;
      }
    }
    for (i = 0; i < len; i++) cout << v[r[i] - 1] << endl;
    cout << endl;
    if (flag) continue;
  }
}
