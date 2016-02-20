#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
const int MAX = 111;
char org[MAX][MAX];
bool neat[MAX][MAX];
int totstar = 0;
int N;
int a[MAX][MAX], an, am;
int b[MAX][MAX], bn, bm;
int bit[MAX][MAX], len[MAX];
int pa[MAX], pb[MAX];
int press[MAX];
int upleft[MAX], upright[MAX];
int downleft[MAX], downright[MAX];
int Vmax;
const int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool fd = false;

void out(int p[], char s[], int n, int m) {
  printf("%s start\n", s);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((1 << j) & p[i])
        printf("1");
      else
        putchar('0');
    }
    puts("");
  }
  printf("%s end\n", s);
}

int split(int r, int n, int m, int bit[]) {
  int i, len = 0;
  for (i = 0; i < m; i++) {
    if (neat[r][i]) bit[len++] = i;
  }
  return len;
}

int GetState(int s, int bit[], int len) {
  int ret = 0;
  for (int i = 0; i < len; i++) {
    if (s & (1 << i)) ret |= (1 << bit[i]);
  }
  return ret;
}

bool zerocol(int s[], int n, int col) {
  int i;
  col = 1 << col;
  for (i = 0; i < n; i++)
    if (col & s[i]) return false;
  return true;
}

void PressState(int dest[], int src[], int n, int m, int &pn, int &pm) {
  int i, j;
  pn = n;
  pm = m;
  for (i = 0; i < pn; i++) dest[i] = src[i];

  while (true) {
    if (zerocol(dest, pn, 0)) {
      for (i = 0; i < pn; i++) dest[i] >>= 1;
      pm--;
    } else
      break;
  }

  while (true) {
    if (zerocol(dest, n, pm - 1))
      pm--;
    else
      break;
  }

  while (dest[pn - 1] == 0) pn--;
  for (j = 0; dest[j] == 0; j++)
    ;
  for (i = 0; j < pn; i++, j++) dest[i] = dest[j];
  pn = i;
  while (i < Vmax) {
    dest[i] = 0;
    i++;
  }
}

void rot(int p[], int &n, int &m) {
  int c[MAX] = {0};
  int i, j;
  for (i = 0; i < m; i++) {
    int t = 1 << i;
    int v = 0;
    for (j = n - 1; j >= 0; j--) {
      if (t & p[j]) c[i] |= 1 << v;
      v++;
    }
  }
  for (i = 0; i < Vmax; i++) p[i] = 0;
  for (i = 0; i < m; i++) p[i] = c[i];
  swap(n, m);
}
bool FillFull(int i, int j, int x, int y, int pa[], int pb[], int pan, int pam,
              int pbn, int pbm) {
  int c[MAX] = {0};
  int t;
  for (t = 0; t < pan; t++) {
    c[t + i] |= pa[t] << j;
  }
  for (t = 0; t < pbn; t++) {
    if (c[t + x] & (pb[t] << y)) return false;
    c[t + x] |= pb[t] << y;
  }
  for (i = 0; i < N; i++) {
    if (c[i] != (1 << N) - 1) return false;
  }
  return true;
}
bool merge(int pa[], int pb[], int pan, int pam, int pbn, int pbm) {
  int i, j, x, y;
  for (i = 0; i + pan - 1 < N; i++) {
    for (j = 0; j + pam - 1 < N; j++) {
      for (x = 0; x + pbn - 1 < N; x++) {
        for (y = 0; y + pbm - 1 < N; y++) {
          if (FillFull(i, j, x, y, pa, pb, pan, pam, pbn, pbm)) return true;
        }
      }
    }
  }
  return false;
}
bool ok(int x, int n) { return x >= 0 && x < n; }
void spread(int p[], int n, int m, int x, int y) {
  int tx, ty;
  p[x] ^= 1 << y;
  for (int i = 0; i < 4; i++) {
    tx = x + dir[i][0];
    ty = y + dir[i][1];
    if (ok(tx, n) && ok(ty, m) && (p[tx] & (1 << ty))) {
      spread(p, n, m, tx, ty);
    }
  }
}
bool connect(int p[], int n, int m) {
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (p[i]) {
      for (int j = 0; j < m; j++) {
        if (p[i] & (1 << j)) {
          cnt++;
          if (cnt > 1) return false;
          spread(p, n, m, i, j);
        }
      }
    }
  }
  return cnt == 1;
}
bool judge(int uprow, int downrow, int n, int m) {
  int i, j;
  int leftb = MAX, rightb = -1;
  int upb = MAX, downb = -1;
  bool flag = false;

  if (uprow > 0) {
    upb = 0;
    leftb = min(leftb, upleft[uprow - 1]);
    rightb = max(rightb, upright[uprow - 1]);
  }
  if (downrow + 1 < n) {
    leftb = min(leftb, downleft[downrow + 1]);
    rightb = max(rightb, downright[downrow + 1]);
    downb = n - 1;
  }
  if (rightb - leftb + 1 > N) return false;
  if (downb - upb + 1 > N) return false;
  for (i = 0; i < n; i++) {
    pb[i] = press[i] ^ pa[i];
    if (pb[i]) {
      upb = min(upb, i);
      downb = max(downb, i);
      for (j = 0; j < N; j++) {
        if (pb[i] & (1 << j)) {
          rightb = max(rightb, j);
          leftb = min(leftb, j);
        }
      }
    }
  }
  if (rightb - leftb + 1 > N) return false;
  if (downb - upb + 1 > N) return false;

  flag = false;
  for (i = 0; i < n; i++)  //判B连通
  {
    if (flag && pb[i] != 0) {
      if ((pb[i] & pb[i - 1]) == 0) return false;
    }
    if (pb[i]) flag = true;
  }
  int pressa[MAX], pressb[MAX];
  int pan, pam, pbn, pbm;
  PressState(pressa, pa, n, m, pan, pam);
  PressState(pressb, pb, n, m, pbn, pbm);
  if (!connect(pressa, pan, pam)) return false;
  if (!connect(pressb, pbn, pbm)) return false;

  PressState(pressa, pa, n, m, pan, pam);
  PressState(pressb, pb, n, m, pbn, pbm);
  for (int cnt = 0; cnt < 4; cnt++) {
    if (merge(pressa, pressb, pan, pam, pbn, pbm)) return true;
    rot(pressa, pan, pam);
  }
  return false;
}
void GetLeftRight(int &cleft, int &cright, int s, int m) {
  int i;
  for (i = 0; i < m; i++) {
    if (s & (1 << i)) {
      cleft = min(cleft, i);
      cright = max(cright, i);
    }
  }
}
bool DFS(int uprow, int downrow, int cleft, int cright, int n, int m, int Bleft,
         int Bright, bool Bflag) {
  if (cright - cleft + 1 > N) return false;
  if (Bright - Bleft + 1 > N) return false;
  if (judge(uprow, downrow, n, m)) {
    fd = true;
    return true;
  }
  downrow++;
  if (downrow - uprow + 1 > N) return false;
  int v = 1 << len[downrow];

  for (int i = 1; i < v; i++) {
    pa[downrow] = GetState(i, bit[downrow], len[downrow]);
    if ((pa[downrow] & pa[downrow - 1]) == 0) continue;
    int cl = MAX, cr = -1;
    GetLeftRight(cl, cr, pa[downrow], m);
    cl = min(cleft, cl);
    cr = max(cright, cr);
    pb[downrow] = press[downrow] ^ pa[downrow];
    bool tBflag = Bflag;
    if (Bflag && (pb[downrow] & pb[downrow - 1]) == 0) continue;
    if (pb[downrow]) tBflag = true;
    int tBleft = Bleft, tBright = Bright;
    GetLeftRight(tBleft, tBright, pb[downrow], m);
    DFS(uprow, downrow, cl, cr, n, m, tBleft, tBright, tBflag);
    if (fd) return true;
  }
  pa[downrow] = 0;
  pb[downrow] = 0;
  return false;
}
void FillChar(int p[], int n, int m, int up, int left, char x) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if ((1 << j) & p[i]) {
        org[up + i][left + j] = x;
      }
    }
  }
}

int main() {
  int n, m;
  int orgn = 0;
  int i, j;
  int left = MAX, right = -1, up = MAX, down = -1;
  memset(org, 0, sizeof(org));
  while (gets(org[orgn])) orgn++;
  for (i = 0; i < orgn; i++) {
    for (j = 0; org[i][j]; j++) {
      if (org[i][j] == '*') {
        if (i < up) up = i;
        if (i > down) down = i;
        if (j < left) left = j;
        if (j > right) right = j;
      }
    }
  }
  memset(neat, false, sizeof(neat));
  n = down - up + 1;
  m = right - left + 1;
  totstar = 0;
  Vmax = max(n, m);
  for (i = 0; i < n; i++) {
    press[i] = 0;
    for (j = 0; j < m; j++) {
      if (org[i + up][j + left] == '*') {
        neat[i][j] = true;
        press[i] |= (1 << j);
        totstar++;
      }
    }
  }

  N = 0;
  while (N * N != totstar) N++;
  for (i = 0; i < n; i++) {
    len[i] = split(i, n, m, bit[i]);
  }

  upleft[0] = bit[0][0];
  upright[0] = bit[0][len[0] - 1];
  for (i = 1; i < n; i++) {
    upleft[i] = upleft[i - 1];
    upright[i] = upright[i - 1];
    if (len[i] > 0) {
      upleft[i] = min(upleft[i], bit[i][0]);
      upright[i] = max(upright[i], bit[i][len[i] - 1]);
    }
  }

  downleft[n - 1] = bit[n - 1][0];
  downright[n - 1] = bit[n - 1][len[n - 1] - 1];
  for (i = n - 2; i >= 0; i--) {
    downleft[i] = downleft[i + 1];
    downright[i] = downright[i + 1];
    if (len[i] > 0) {
      downleft[i] = min(downleft[i], bit[i][0]);
      downright[i] = max(downright[i], bit[i][len[i] - 1]);
    }
  }

  bool flag = false;
  fd = false;
  memset(pa, 0, sizeof(pa));
  memset(pb, 0, sizeof(pb));
  for (i = 0; i < n; i++) {
    int tl = len[i];
    j = i + N;
    if (j < n) {
      if (downright[j] - downleft[j] + 1 > N) continue;
      if (i > 0 && n > N) continue;
    }
    int Bleft = MAX, Bright = -1;
    bool Bflag = false;
    if (i > 0) {
      Bleft = upleft[i - 1];
      Bright = upright[i - 1];
      Bflag = true;
    }
    for (j = 1; j < (1 << tl); j++)  //不超过N行，l,r不超过N
    {
      pa[i] = GetState(j, bit[i], len[i]);

      int cleft = MAX, cright = -1;
      GetLeftRight(cleft, cright, pa[i], m);
      pb[i] = press[i] ^ pa[i];
      GetLeftRight(Bleft, Bright, pb[i], m);
      if (pb[i]) Bflag = true;
      DFS(i, i, cleft, cright, n, m, Bleft, Bright, Bflag);
      if (fd) break;
    }
    if (fd) break;
    pa[i] = 0;
    pb[i] = press[i];
  }
  FillChar(pa, n, m, up, left, 'A');
  FillChar(pb, n, m, up, left, 'B');
  for (i = 0; i < orgn; i++) puts(org[i]);
  return 0;
}
