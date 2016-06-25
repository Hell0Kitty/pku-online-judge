#include <cstdio>
#include <cstring>
#define lch(i) ((i) << 1)
#define rch(i) ((i) << 1 | 1)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define N 50010
#define INF 0x3f3f3f3f

struct node {
  int l, r;
  int mark;
  int tlen, llen, rlen;
  int mid() { return (l + r) >> 1; }
  int cal_len() { return r - l + 1; }
  void updata_len() { tlen = llen = rlen = (mark ? 0 : cal_len()); }
} t[4 * N];

void build(int l, int r, int rt) {
  t[rt].l = l;
  t[rt].r = r;
  t[rt].tlen = t[rt].llen = t[rt].rlen = t[rt].cal_len();
  t[rt].mark = 0;
  if (l == r) return;
  int mid = t[rt].mid();
  build(l, mid, lch(rt));
  build(mid + 1, r, rch(rt));
  return;
}

int query(int w, int rt) {
  if (t[rt].l == t[rt].r && w == 1)  //叶子特判
    return t[rt].l;
  if (t[rt].mark != -1)  //延迟标记，父亲信息传递给儿子
  {
    t[lch(rt)].mark = t[rch(rt)].mark = t[rt].mark;
    t[rt].mark = -1;
    t[lch(rt)].updata_len();  //传递信息后更新孩子的区间覆盖情况
    t[rch(rt)].updata_len();  //传递信息后更新孩子的区间覆盖情况
  }
  if (t[lch(rt)].tlen >= w)  //左孩子的可用区间可以满足，那么一定在左孩子区间内
    return query(w, lch(rt));
  else if (t[lch(rt)].rlen + t[rch(rt)].llen >=
           w)  //横跨左右孩子且连续的区间可以满足，那么可以直接返回下标
    return (t[lch(rt)].r - t[lch(rt)].rlen + 1);
  else if (t[rch(rt)].tlen >= w)  //右孩子的可用区间可以满足，那么去右孩子处找
    return query(w, rch(rt));
  else  //找不到可用的区间
    return 0;
}

void updata(int l, int r, int val, int rt) {
  if (t[rt].l == l && t[rt].r == r) {
    t[rt].mark = val;
    t[rt].updata_len();
    return;
  }
  if (t[rt].mark != -1)  //延迟标记，父亲信息传递给儿子
  {
    t[lch(rt)].mark = t[rch(rt)].mark = t[rt].mark;
    t[rt].mark = -1;
    t[lch(rt)].updata_len();  //传递信息后更新孩子的区间覆盖情况
    t[rch(rt)].updata_len();  //传递信息后更新孩子的区间覆盖情况
  }
  int mid = t[rt].mid();
  if (l > mid)  //修改的区间在右孩子
    updata(l, r, val, rch(rt));
  else if (r <= mid)  //修改的区间在左孩子
    updata(l, r, val, lch(rt));
  else {
    updata(l, mid, val, lch(rt));
    updata(mid + 1, r, val, rch(rt));
  }
  int tmp = max(t[lch(rt)].tlen, t[rch(rt)].tlen);
  t[rt].tlen = max(tmp, t[lch(rt)].rlen + t[rch(rt)].llen);
  t[rt].llen = t[lch(rt)].llen;
  t[rt].rlen = t[rch(rt)].rlen;
  if (t[lch(rt)].tlen == t[lch(rt)].cal_len()) t[rt].llen += t[rch(rt)].llen;
  if (t[rch(rt)].tlen == t[rch(rt)].cal_len()) t[rt].rlen += t[lch(rt)].rlen;
  return;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  build(1, n, 1);
  while (m--) {
    int choose;
    scanf("%d", &choose);
    if (choose == 1) {
      int w;
      scanf("%d", &w);
      int index = query(w, 1);
      printf("%d\n", index);
      if (index) updata(index, index + w - 1, 1, 1);
    } else {
      int l, len;
      scanf("%d%d", &l, &len);
      updata(l, l + len - 1, 0, 1);
    }
  }
  return 0;
}
