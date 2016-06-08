#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

struct Item {
  int qnum, t, period;
  Item(int qq, int tt, int pp) : qnum(qq), t(tt), period(pp) {}
};

bool operator<(const Item &a, const Item &b) {
  if (a.t != b.t) return a.t > b.t;
  return a.qnum > b.qnum;
}

priority_queue<Item> q;

int main() {
  char st[100];
  while (scanf("%s", st) && st[0] != '#') {
    int a, b;
    scanf("%d%d", &a, &b);
    q.push(Item(a, b, b));
  }
  int n;
  scanf("%d", &n);
  while (n--) {
    Item temp = q.top();
    q.pop();
    q.push(Item(temp.qnum, temp.t + temp.period, temp.period));
    printf("%d\n", temp.qnum);
  }
  return 0;
}
