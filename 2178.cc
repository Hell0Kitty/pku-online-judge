#include <cstdio>
#include <cstring>

const int N = 12;
const int HPH = 100 + 10;
const int MPH = 50 + 10;
const int HPM = 12;
const int NM = 12;

struct MOVE {
  int act, p;
};

int n, hph, mph, hpm, nm, v, dh;
int L[N];
int ans[MPH][HPM * NM][N][2];
MOVE nxt[MPH][HPM * NM][N][2];

inline int min(int a, int b) {
  if (a < b)
    return a;
  else
    return b;
}

inline int max(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}

int dp(int b, int c, int d, int e) {
  int r, tmp, a, i;
  if (ans[b][c][d][e] != -1) return ans[b][c][d][e];
  if (e == 0)  // hero's turn
  {
    if (b <= 0 && c > 0) {
      nxt[b][c][d][e].act = -1;
      return ans[b][c][d][e] = hph + 1;
    }
    if (c <= 0) {
      nxt[b][c][d][e].act = 3;
      return ans[b][c][d][e] = 1;
    }
    r = hph + 1;
    nxt[b][c][d][e].act = -1;
    if (dp(b - 1, max(c - L[d], 0), d, 1 - e) < r) {
      nxt[b][c][d][e].act = 0;
      r = ans[b - 1][max(c - L[d], 0)][d][1 - e];
    }
    for (i = 1; i <= n; i++)
      if (dp(b - 1, c, i, 1 - e) < r) {
        nxt[b][c][d][e].act = 1;
        nxt[b][c][d][e].p = i;
        r = ans[b - 1][c][i][1 - e];
      }
    if (dp(b - 1, c, d, 1 - e) <= hph) {
      if (max(ans[b - 1][c][d][1 - e] - dh, 1) < r) {
        nxt[b][c][d][e].act = 2;
        r = max(ans[b - 1][c][d][1 - e] - dh, 1);
      }
    }
    if (r == -1) r = -1;
    return ans[b][c][d][e] = r;
  } else  // monster's turn
  {
    if (b <= 0 && c > 0) {
      nxt[b][c][d][e].act = 1;
      return ans[b][c][d][e] = hph + 1;
    }
    if (c <= 0) {
      nxt[b][c][d][e].act = -1;
      return ans[b][c][d][e] = 1;
    }
    tmp = d;
    d = d - min(v, d - 1);
    a = 0;
    if (d == 1) {
      if (c % hpm == 0)
        a = c / hpm;
      else
        a = c / hpm + 1;
    }
    nxt[b][c][tmp][e].act = 0;
    return ans[b][c][tmp][e] = a + dp(b, c, d, 1 - e);
  }
}

void print_act(int b, int c, int d, int e) {
  if (b < 0 || c < 0 || d < 0 || e < 0)
    while (1)
      ;
  if (e == 0) {
    if (nxt[b][c][d][e].act == 3) return;
    if (nxt[b][c][d][e].act == 0) {
      printf("L\n");
      print_act(b - 1, max(c - L[d], 0), d, 1 - e);
    } else if (nxt[b][c][d][e].act == 1) {
      printf("T %d\n", nxt[b][c][d][e].p);
      print_act(b - 1, c, nxt[b][c][d][e].p, 1 - e);
    } else {
      printf("H\n");
      print_act(b - 1, c, d, 1 - e);
    }
  } else {
    if (nxt[b][c][d][e].act == -1) return;
    d = d - min(v, d - 1);
    print_act(b, c, d, 1 - e);
  }
}

int main() {
  int i;
  scanf("%d %d %d %d %d %d %d", &n, &hph, &mph, &hpm, &nm, &v, &dh);
  for (i = 1; i <= n; i++) scanf("%d", &L[i]);
  memset(ans, -1, sizeof(ans));
  if (dp(mph, hpm * nm, n, 0) > hph)
    printf("DEFEATED\n");
  else {
    printf("VICTORIOUS\n");
    print_act(mph, hpm * nm, n, 0);
  }
  return 0;
}
