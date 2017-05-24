#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

const int N = 55;
const int M = N * N;
map<int, int> xid, yid;
bool blx[M >> 1][M >> 1], vis[M >> 1][M >> 1];
typedef long long LL;
typedef pair<int, int> PII;

int L, W;
int rx[M], ry[M], xn, yn, pn[N];
PII poly[N][N];

void fix(int id) {
  int mk = 0;
  for (int i = 0; i < pn[id]; i++)
    if (poly[id][mk] < poly[id][i]) mk = i;
  rotate(poly[id], poly[id] + mk, poly[id] + pn[id]);
}

const int dx[5] = {-1, -1, 0, 1, 0};
const int dy[5] = {1, 0, 1, 0, -1};

inline LL cross(PII a, PII b) {
  return (LL)a.first * b.second - (LL)a.second * b.first;
}
PII operator-(PII a, PII b) {
  return PII(a.first - b.first, a.second - b.second);
}

bool inPoly(PII pt, int id) {
  int wn = 0;
  poly[id][pn[id]] = poly[id][0];
  for (int i = 0; i < pn[id]; i++) {
    LL k = cross(poly[id][i + 1] - poly[id][i], pt - poly[id][i]);
    int d1 = poly[id][i].second - pt.second;
    int d2 = poly[id][i + 1].second - pt.second;
    if (k > 0 && d1 <= 0 && d2 > 0) wn++;
    if (k < 0 && d2 <= 0 && d1 > 0) wn--;
  }
  return wn != 0;
}

int qx[M * M >> 2], qy[M * M >> 2];
inline bool inMat(int x, int y) { return 0 <= x && x < xn && 0 <= y && y < yn; }

void fill(int id) {
  int cx = xid[poly[id][0].first] - 1;
  int cy = yid[poly[id][0].second] - 1;
  blx[cx][cy] = true;
  int qh, qt, nx, ny;
  qh = qt = 0;
  qx[qt] = cx, qy[qt++] = cy;
  while (qh < qt) {
    cx = qx[qh], cy = qy[qh++];
    for (int i = 1; i < 5; i++) {
      nx = cx + dx[i], ny = cy + dy[i];
      if (inMat(nx, ny) && !blx[nx][ny] &&
          inPoly(PII(rx[nx] + rx[nx + 1] >> 1, ry[ny] + ry[ny + 1] >> 1), id)) {
        blx[nx][ny] = true;
        qx[qt] = nx, qy[qt++] = ny;
      }
    }
  }
}

LL work(int n) {
  int cx = xn - 1, cy = 0;
  LL sum = 0;
  int qh, qt, nx, ny;
  memset(vis, 0, sizeof(vis));
  qh = qt = 0;
  if (!blx[cx][cy]) {
    qx[qt] = cx, qy[qt++] = cy;
    vis[cx][cy] = true;
  }
  while (qh < qt) {
    cx = qx[qh], cy = qy[qh++];
    for (int i = 1; i < 3; i++) {
      nx = cx + dx[i], ny = cy + dy[i];
      if (inMat(nx, ny) && !blx[nx][ny] && !vis[nx][ny]) {
        vis[nx][ny] = true;
        qx[qt] = nx, qy[qt++] = ny;
      }
    }
  }
  for (int i = 0; i < xn; i++) {
    for (int j = 0; j < yn; j++) {
      if (vis[i][j] || blx[i][j]) continue;
      sum += (LL)(rx[i + 1] - rx[i]) * (ry[j + 1] - ry[j]);
    }
  }
  return sum >> 2;
}

void PRE(int n) {
  sort(rx, rx + xn);
  xn = unique(rx, rx + xn) - rx;
  xid.clear();
  for (int i = 0; i < xn; i++) xid[rx[i]] = i;
  sort(ry, ry + yn);
  yn = unique(ry, ry + yn) - ry;
  yid.clear();
  for (int i = 0; i < yn; i++) yid[ry[i]] = i;
  xn--, yn--;

  memset(blx, 0, sizeof(blx));
  for (int i = 0; i < n; i++) fix(i);

  for (int i = 0; i < n; i++) fill(i);
}

int main() {
  int T, n, x, y;
  cin >> T;
  while (T-- && cin >> L >> W) {
    xn = yn = 0;
    L <<= 1, W <<= 1;
    rx[xn++] = L, ry[yn++] = W;
    rx[xn++] = 0, ry[yn++] = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> pn[i];
      for (int j = 0; j < pn[i]; j++) {
        scanf("%d%d", &poly[i][j].first, &poly[i][j].second);
        poly[i][j].first <<= 1, poly[i][j].second <<= 1;
        rx[xn++] = poly[i][j].first, ry[yn++] = poly[i][j].second;
      }
    }
    PRE(n);
    cout << work(n) << endl;
  }
  return 0;
}
