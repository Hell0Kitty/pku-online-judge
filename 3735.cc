#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 110

struct Matrix {
  long long x, y;
  long long a[maxn][maxn];
} f, temp;

long long n, m, r;

Matrix mul(Matrix &a, Matrix &b) {
  Matrix ret;
  memset(ret.a, 0, sizeof(ret.a));
  ret.x = a.x;
  ret.y = b.y;
  for (int i = 0; i < a.x; i++)
    for (int k = 0; k < a.y; k++)
      if (a.a[i][k])
        for (int j = 0; j < b.y; j++) ret.a[i][j] += a.a[i][k] * b.a[k][j];
  return ret;
}

Matrix power(Matrix &a, long long n) {
  Matrix m = a;
  Matrix ret;
  memset(ret.a, 0, sizeof(ret.a));
  for (int i = 0; i < a.x; i++) ret.a[i][i] = 1;
  ret.x = ret.y = a.x;
  while (n > 0) {
    if (1 & n) ret = mul(ret, m);
    m = mul(m, m);
    n >>= 1;
  }
  return ret;
}

void input() {
  memset(f.a, 0, sizeof(f.a));
  for (int i = 0; i <= n; i++) f.a[i][i] = 1;
  f.x = f.y = n + 1;
  for (int i = 0; i < m; i++) {
    int a, b;
    char ch[2];
    scanf("%s", ch);
    if (ch[0] == 'g') {
      scanf("%d", &a);
      f.a[0][a]++;
    } else if (ch[0] == 'e') {
      scanf("%d", &a);
      for (int j = 0; j <= n; j++) f.a[j][a] = 0;
    } else {
      scanf("%d%d", &a, &b);
      for (int j = 0; j <= n; j++) swap(f.a[j][a], f.a[j][b]);
    }
  }
}

void work() {
  Matrix ans;
  memset(ans.a, 0, sizeof(ans.a));
  ans.x = 1;
  ans.y = n + 1;
  ans.a[0][0] = 1;
  ans = mul(ans, f);
  printf("%lld", ans.a[0][1]);
  for (int i = 2; i <= n; i++) printf(" %lld", ans.a[0][i]);
  putchar('\n');
}

int main() {
  while (scanf("%lld%lld%lld", &n, &r, &m), n | r | m) {
    input();
    f = power(f, r);
    work();
  }
  return 0;
}
