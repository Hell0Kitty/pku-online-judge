#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <iostream>
#include <cstring>
#define INF 9999999

using namespace std;

struct Seg {
  int l;
  int r;
  int y;
  int v;

  Seg(int L, int R, int Y, int V) : l(L), r(R), y(Y), v(V) {}
  Seg() {}

  bool operator<(const Seg& s) const {
    if (y != s.y)
      return y < s.y;
    else
      return v > s.v;
  }

} ss[50050 << 2];

int length[50050 << 2];
int nLayer[50050 << 2];

void calc(int index, int l, int r) {
  if (nLayer[index])
    length[index] = r - l + 1;
  else if (l == r)
    length[index] = 0;
  else
    length[index] = length[index << 1] + length[index << 1 | 1];
}

void PullUp(int index, int l, int r) {
  if (nLayer[index << 1] && nLayer[index << 1 | 1]) {
    int tmp = (nLayer[index << 1] < nLayer[index << 1 | 1])
                  ? nLayer[index << 1]
                  : nLayer[index << 1 | 1];
    nLayer[index] = tmp;
    nLayer[index << 1] -= tmp;
    nLayer[index << 1 | 1] -= tmp;
    int mid = (l + r) >> 1;
    calc(index << 1, l, mid);
    calc(index << 1 | 1, mid + 1, r);
  }
}

void PushDown(int index, int l, int r) {
  if (nLayer[index]) {
    nLayer[index << 1] += nLayer[index];
    nLayer[index << 1 | 1] += nLayer[index];
    int mid = (l + r) >> 1;
    calc(index << 1, l, mid);
    calc(index << 1 | 1, mid + 1, r);
    nLayer[index] = 0;
    calc(index, l, r);
  }
}

void update(int a, int b, int v, int l, int r, int index) {
  if (a <= l && r <= b) {
    nLayer[index] += v;
    calc(index, l, r);
    return;
  }
  PushDown(index, l, r);
  int mid = (l + r) >> 1;
  if (a <= mid) update(a, b, v, l, mid, index << 1);
  if (b > mid) update(a, b, v, mid + 1, r, index << 1 | 1);
  PullUp(index, l, r);
  calc(index, l, r);
}

int main() {
  int N;
  while (scanf("%d", &N) && N) {
    int m = 0;
    memset(length, 0, sizeof(length));
    memset(nLayer, 0, sizeof(nLayer));
    for (int i = 0; i < N; ++i) {
      int x1, y1, x2, y2, x3, y3, x4, y4;
      scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
      ss[m++] = Seg(x1, x2, y1, 1);
      ss[m++] = Seg(x3, x4, y3, -1);
      ss[m++] = Seg(x3, x4, y4, 1);
      ss[m++] = Seg(x1, x2, y2, -1);
    }
    sort(ss, ss + m);
    unsigned int ans = 0;
    for (int i = 0; i < m - 1; ++i) {
      update(ss[i].l, ss[i].r - 1, ss[i].v, 0, 50000, 1);
      ans += length[1] * (ss[i + 1].y - ss[i].y);
    }
    cout << ans << endl;
  }
}
