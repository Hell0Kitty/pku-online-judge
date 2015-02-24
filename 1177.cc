Source Code

    Problem : 1177 User : freebsdx Memory : 572K Time : 16MS Language
                          : G++ Result : Accepted Source Code
#include <stdio.h>
#include <math.h>
#include <algorithm>
#define L(x) (x << 1)
#define R(x) ((x << 1) + 1)
#define M 5050
                                         using namespace std;

struct tree {
  int l, r;
  int lb, rb;  //左右端点是否被覆盖
  int count, line,
      len;  // count 被覆盖的次数  line 所包含区间的数量 len 是区间长度（测度）
} node[M * 3];

struct data {
  int x, y1, y2;
  int flag;  // flag 1表示为入边，-1表示为出边
} seg[M * 2];

int y[M * 2];  //记录y坐标

bool cmp(data a, data b)  // x升序 x相同时 入边在前
{
  if (a.x < b.x) return true;
  if (a.x == b.x && a.flag > b.flag) return true;
  return false;
}
void BuildTree(int left, int right, int u) {
  node[u].l = left;
  node[u].r = right;
  node[u].len = node[u].line = node[u].count = 0;
  if (left + 1 == right) return;
  int mid = (left + right) >> 1;
  BuildTree(left, mid, L(u));
  BuildTree(mid, right, R(u));
}
void updata(int u)  //更新测度 和 line的值
{                   //获得以当前接点为根的树被覆盖的区间总长度 被覆盖区间的总数
  if (node[u].count > 0)

  {
    node[u].len = y[node[u].r] - y[node[u].l];
    node[u].line = node[u].lb = node[u].rb = 1;
  } else if (node[u].l + 1 == node[u].r) {
    node[u].len = 0;
    node[u].line = node[u].lb = node[u].rb = 0;
  } else  //由左右结点的值 确定父亲结点的值
  {
    node[u].len = node[L(u)].len + node[R(u)].len;
    node[u].lb = node[L(u)].lb;
    node[u].rb = node[R(u)].rb;
    node[u].line =
        node[L(u)].line + node[R(u)].line - node[L(u)].rb * node[R(u)].lb;
  }
}
void query(int left, int right, int flag, int u) {
  if (y[node[u].l] == left && y[node[u].r] == right) {
    node[u].count += flag;
    updata(u);
    return;
  }
  int mid = y[(node[u].l + node[u].r) >> 1];
  if (right <= mid)
    query(left, right, flag, L(u));
  else if (left >= mid)
    query(left, right, flag, R(u));
  else {
    query(left, mid, flag, L(u));
    query(mid, right, flag, R(u));
  }
  updata(u);
}
int main() {
  int n, m, i, j;
  int x1, y1, x2, y2;
  while (~scanf("%d", &n)) {
    m = 0;
    for (i = 0; i < n; i++) {
      scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
      seg[m].x = x1, seg[m].y1 = y1, seg[m].y2 = y2;
      seg[m].flag = 1, y[m++] = y1;
      seg[m].x = x2, seg[m].y1 = y1, seg[m].y2 = y2;
      seg[m].flag = -1, y[m++] = y2;
    }
    sort(y, y + m);
    sort(seg, seg + m, cmp);
    int cnt = unique(y, y + m) - y;  //离散化
    BuildTree(0, cnt - 1, 1);
    int pmt = 0, now_m = 0, now_l = 0;  // pmt 周长
    for (i = 0; i < m; i++) {
      query(seg[i].y1, seg[i].y2, seg[i].flag, 1);
      if (i > 0) pmt += 2 * now_l * (seg[i].x - seg[i - 1].x);  //水平x的长度
      pmt += fabs(node[1].len - now_m);  // y的长度
      now_m = node[1].len;
      now_l = node[1].line;
    }
    printf("%d\n", pmt);
  }
  return 0;
}