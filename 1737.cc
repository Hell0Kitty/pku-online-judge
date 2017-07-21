#include <iostream>
#include <cstdio>

using namespace std;

const int base = 10000;
const int maxn = 1000;

int n, c[51][51][maxn], a[51][maxn], pr[1230][maxn];

void repair(int *a);
void let(int *a, int val);
void output(int *a);
void add(int *a, int *b);
void mul(int *a, int *b);
void mul(int *a, int val);
void sub(int *a, int *b);
void copy(int *a, int *b);

int main() {
  int t[maxn];
  let(pr[0], 1);
  for (int i = 1; i < 1230; i++) {
    copy(pr[i], pr[i - 1]);
    mul(pr[i], 2);
  }
  let(c[0][0], 1);

  for (int i = 1; i <= 50; i++) {
    let(c[i][0], 1);
    let(c[i][i], 1);
    for (int j = 1; j < i; j++) {
      let(c[i][j], 0);
      add(c[i][j], c[i - 1][j]);
      add(c[i][j], c[i - 1][j - 1]);
    }
  }
  let(a[1], 1);
  let(a[2], 1);
  let(a[3], 4);
  for (int i = 4; i <= 50; i++) {
    copy(a[i], pr[i * (i - 1) / 2]);
    for (int j = 1; j < i; j++) {
      copy(t, a[j]);
      mul(t, c[i - 1][j - 1]);
      mul(t, pr[(i - j) * (i - j - 1) / 2]);
      sub(a[i], t);
    }
  }

  while (true) {
    scanf("%d", &n);
    if (n == 0) break;
    output(a[n]);
    printf("\n");
  }
  return 0;
}

void repair(int *a) {
  for (int i = 1; i <= a[0]; i++) {
    if (a[i] >= base) {
      if (i == a[0]) a[0]++;
      a[i + 1] += a[i] / base;
      a[i] %= base;
    } else if (a[i] < 0) {
      while (a[i] < 0) {
        a[i + 1]--;
        a[i] += base;
      }
    }
  }

  for (int i = a[0]; i >= 2; i--) {
    if (a[i] == 0)
      a[0]--;
    else
      break;
  }
}

void let(int *a, int val) {
  a[0] = 1;
  a[1] = val;
  for (int i = 2; i < maxn; i++) a[i] = 0;
  repair(a);
}

void output(int *a) {
  printf("%d", a[a[0]]);
  for (int i = a[0] - 1; i >= 1; i--) printf("%04d", a[i]);
}

void add(int *a, int *b) {
  if (a[0] < b[0]) a[0] = b[0];
  for (int i = 1; i <= b[0]; i++) a[i] += b[i];
  repair(a);
}

void sub(int *a, int *b) {
  for (int i = 1; i <= b[0]; i++) a[i] -= b[i];
  repair(a);
}

void copy(int *a, int *b) {
  for (int i = 0; i <= b[0]; i++) a[i] = b[i];
}

void mul(int *a, int *b) {
  int tmp[maxn];
  let(tmp, 0);
  for (int i = 1; i <= b[0]; i++) {
    for (int j = 1; j <= a[0]; j++) tmp[i + j - 1] += b[i] * a[j];
    tmp[0] = i * a[0];
    repair(tmp);
  }
  copy(a, tmp);
}

void mul(int *a, int val) {
  for (int i = 1; i <= a[0]; i++) a[i] *= val;
  repair(a);
}