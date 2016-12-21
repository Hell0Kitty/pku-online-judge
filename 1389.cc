#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

///宏定义
const int INF = 20000000;
const int maxn = 10010;
const int MAXN = 10010;
///全局变量 和 函数
int yypos[MAXN];
struct line {
  int x;
  int y1, y2;

  int flag;
} lines[MAXN];  //扫描线段

struct node {
  int lc, rc;

  int len;   //区间长度
  int flag;  //区间标记
} tree[MAXN];

int xx1, yy1, xx2, yy2;
int cmp(line l1, line l2) { return l1.x < l2.x; }

//建树 插入 删除
void buildtree(int l, int r, int pos) {
  tree[pos].lc = l;
  tree[pos].rc = r;
  tree[pos].len = tree[pos].flag = 0;
  if (l + 1 == r) return;
  int mid = (l + r) / 2;
  buildtree(l, mid, pos * 2);
  buildtree(mid, r, pos * 2 + 1);
}
void update(int pos) {
  if (tree[pos].flag > 0)
    tree[pos].len = yypos[tree[pos].rc] - yypos[tree[pos].lc];
  else if (tree[pos].lc + 1 == tree[pos].rc)
    tree[pos].len = 0;
  else
    tree[pos].len = tree[pos * 2].len + tree[pos * 2 + 1].len;
}
void insert(line e, int pos) {
  if (e.y1 == yypos[tree[pos].lc] && e.y2 == yypos[tree[pos].rc])
    tree[pos].flag += e.flag;
  else {
    int mid = (tree[pos].lc + tree[pos].rc) / 2;
    if (e.y2 <= yypos[mid])
      insert(e, pos * 2);
    else if (e.y1 >= yypos[mid])
      insert(e, pos * 2 + 1);
    else {
      line temp;
      temp = e;
      temp.y2 = yypos[mid];
      insert(temp, pos * 2);
      temp = e;
      temp.y1 = yypos[mid];
      insert(temp, pos * 2 + 1);
    }
  }
  update(pos);
}

int main() {
  ///
  int i, j;
  int line_cnt;
  int ynums;
  ///变量定义
  while (1) {
    line_cnt = 0;
    cin >> xx1 >> yy1 >> xx2 >> yy2;
    if (xx1 == -1 && yy1 == -1 && xx2 == -1 && yy2 == -1) break;
    lines[line_cnt].x = xx1;
    lines[line_cnt].y1 = yy1;
    lines[line_cnt].y2 = yy2;
    lines[line_cnt].flag = 1;
    yypos[line_cnt++] = yy1;

    lines[line_cnt].x = xx2;
    lines[line_cnt].y1 = yy1;
    lines[line_cnt].y2 = yy2;
    lines[line_cnt].flag = -1;
    yypos[line_cnt++] = yy2;

    while (1) {
      cin >> xx1 >> yy1 >> xx2 >> yy2;
      if (xx1 == -1 && yy1 == -1 && xx2 == -1 && yy2 == -1) break;
      lines[line_cnt].x = xx1;
      lines[line_cnt].y1 = yy1;
      lines[line_cnt].y2 = yy2;
      lines[line_cnt].flag = 1;
      yypos[line_cnt++] = yy1;

      lines[line_cnt].x = xx2;
      lines[line_cnt].y1 = yy1;
      lines[line_cnt].y2 = yy2;
      lines[line_cnt].flag = -1;
      yypos[line_cnt++] = yy2;
    }
    ynums = line_cnt;
    sort(yypos, yypos + ynums);
    ynums = unique(yypos, yypos + ynums) - yypos;  //去重，STL的unique函数
    sort(lines, lines + line_cnt, cmp);

    //建树
    buildtree(0, ynums - 1, 1);

    int ans = 0;
    insert(lines[0], 1);

    for (i = 1; i < line_cnt; i++) {
      ans += (lines[i].x - lines[i - 1].x) * tree[1].len;
      insert(lines[i], 1);
    }

    cout << ans << endl;
  }

  ///运行部分

  ///结束
  return 0;
}
