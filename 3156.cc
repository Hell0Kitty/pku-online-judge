#include <string.h>
#include <stdio.h>
#include <algorithm>
#define MAXN 50
#define INF 0x3f3f3f3f
#define MOD 100007
struct sta {
  int x[30], flag;
  double val;
  void clear() { memset(x, 0, sizeof x); }
  void sort() { std::sort(x, x + 30); }
  int hashme() {
    int v = 0;
    for (int i = 29, b = 1; i >= 1 && x[i]; i--)
      v += x[i] * b, v %= MOD, b *= 30, b %= MOD;
    return v;
  }
  bool operator==(sta b) {
    for (int i = 0; i < 30; i++)
      if (x[i] != b.x[i]) return false;
    return true;
  }
  bool operator!=(sta b) { return *this == b ? false : true; }

} st, hh[MOD];
int n, m, tu, tv;
int p[MAXN], tot[MAXN];
int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
void inshash(sta st) {
  int x = st.hashme();
  while (hh[x].flag == 1) {
    if (++x == MOD) x = 0;
  }
  hh[x] = st, hh[x].flag = 1;
}
double gethash(sta st) {
  int x = st.hashme();
  while (hh[x].flag == 1 && hh[x] != st) {
    if (++x == MOD) x = 0;
  }
  return hh[x] == st ? hh[x].val : -1;
}

double dp(sta ost) {
  if (ost.hashme() == n) return 0;
  double x = gethash(ost);
  if (x != -1.0) return x;
  //不会改变连通的方案
  double tmp = 0, ans = 0;
  for (int i = 0; i < 30; i++) tmp += (ost.x[i] * (ost.x[i] - 1)) / 2;
  //会把两个非连通子图连通的方案
  for (int i = 0; i < 30; i++) {
    for (int j = i + 1; j < 30; j++) {
      if (ost.x[i] == 0 || ost.x[j] == 0) continue;
      sta stt = ost;
      stt.x[i] += stt.x[j], stt.x[j] = 0;
      stt.sort();
      ans += ost.x[i] * ost.x[j] * dp(stt);
    }
  }
  ans /= (n * (n - 1) / 2), ans++;
  ans /= (1 - tmp / (n * (n - 1) / 2));
  ost.val = ans;
  inshash(ost);
  return ans;
}
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    for (int i = 0; i < MOD; i++) hh[i].flag = 0;
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 0; i < m; i++) {
      scanf("%d%d", &tu, &tv);
      p[find(tu)] = find(tv);
    }
    st.clear();
    int xs = 0;
    memset(tot, 0, sizeof tot);
    for (int i = 1; i <= n; i++) tot[find(i)]++;
    for (int i = 1; i <= n; i++)
      if (tot[i]) st.x[xs++] = tot[i];
    st.sort();
    printf("%.10f\n", dp(st));
  }
  return 0;
}
