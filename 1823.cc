#include <iostream>
#include <cmath>
using namespace std;
#define MAXN 16001
struct node {
  int lmax, rmax, max;
  int left, right;
  int flag;
};
node tree[MAXN * 4];
void build(int i) {
  tree[i].lmax = tree[i].rmax = tree[i].max = tree[i].right - tree[i].left + 1;
  tree[i].flag = 0;
  if (tree[i].left == tree[i].right) return;
  int mid = (tree[i].left + tree[i].right) / 2;
  tree[2 * i].left = tree[i].left;
  tree[2 * i].right = mid;
  tree[2 * i + 1].left = mid + 1;
  tree[2 * i + 1].right = tree[i].right;
  build(2 * i);
  build(2 * i + 1);
}

void insert(int i, int x, int y, int c) {
  // cout<<i<<" "<<x<<" "<<y<<" "<<c<<" "<<tree[i].left<<"
  // "<<tree[i].right<<endl;
  if (tree[i].left == x && tree[i].right == y) {
    tree[i].flag = c;
    if (c == 1)
      tree[i].lmax = tree[i].rmax = tree[i].max = 0;
    else
      tree[i].lmax = tree[i].rmax = tree[i].max =
          tree[i].right - tree[i].left + 1;
    return;
  }
  if (tree[i].flag == 0) {
    tree[2 * i].flag = tree[2 * i + 1].flag = 0;
    tree[2 * i].lmax = tree[2 * i].rmax = tree[2 * i].max =
        tree[2 * i].right - tree[2 * i].left + 1;
    tree[2 * i + 1].lmax = tree[2 * i + 1].rmax = tree[2 * i + 1].max =
        tree[2 * i + 1].right - tree[2 * i + 1].left + 1;
  }
  if (tree[i].flag == 1) {
    tree[2 * i].flag = tree[2 * i + 1].flag = 1;
    tree[2 * i].lmax = tree[2 * i].rmax = tree[2 * i].max = 0;
    tree[2 * i + 1].lmax = tree[2 * i + 1].rmax = tree[2 * i + 1].max = 0;
  }
  int mid = (tree[i].left + tree[i].right) / 2;
  if (y <= mid)
    insert(2 * i, x, y, c);
  else if (x > mid)
    insert(2 * i + 1, x, y, c);
  else {
    insert(2 * i, x, mid, c);
    insert(2 * i + 1, mid + 1, y, c);
  }
  if (tree[2 * i].flag == 0 && tree[2 * i + 1].flag == 0) {
    tree[i].flag = 0;
    tree[i].lmax = tree[i].rmax = tree[i].max =
        tree[i].right - tree[i].left + 1;
  } else if (tree[2 * i].flag == 0 && tree[2 * i + 1].flag == 1) {
    tree[i].flag = 2;
    tree[i].lmax = tree[i].max = tree[2 * i].max;
    tree[i].rmax = 0;
  } else if (tree[2 * i].flag == 1 && tree[2 * i + 1].flag == 0) {
    tree[i].flag = 2;
    tree[i].rmax = tree[i].max = tree[2 * i + 1].max;
    tree[i].lmax = 0;
  } else if (tree[2 * i].flag == 1 && tree[2 * i + 1].flag == 1) {
    tree[i].flag = 1;
    tree[i].lmax = tree[i].rmax = tree[i].max = 0;
  } else {
    tree[i].flag = 2;
    tree[i].max = max(tree[2 * i].max, tree[2 * i + 1].max);
    tree[i].max = max(tree[i].max, tree[2 * i].rmax + tree[2 * i + 1].lmax);
    if (tree[2 * i].flag == 0)
      tree[i].lmax = tree[2 * i].max + tree[2 * i + 1].lmax;
    else
      tree[i].lmax = tree[2 * i].lmax;
    if (tree[2 * i + 1].flag == 0)
      tree[i].rmax = tree[2 * i].rmax + tree[2 * i + 1].max;
    else
      tree[i].rmax = tree[2 * i + 1].rmax;
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  tree[1].left = 1;
  tree[1].right = n;
  build(1);
  int i;
  int x, y, c;
  for (i = 1; i <= m; i++) {
    scanf("%d", &c);
    if (c == 3) printf("%d\n", tree[1].max);
    if (c == 1) {
      scanf("%d%d", &x, &y);
      insert(1, x, x + y - 1, 1);
    }
    if (c == 2) {
      scanf("%d%d", &x, &y);
      insert(1, x, x + y - 1, 0);
    }
  }
  return 0;
}
