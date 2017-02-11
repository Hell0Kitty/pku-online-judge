#include <iostream>

using namespace std;

int n;

struct e {
  int s, t;
};

e a[10001];

int cmp(const void *a, const void *b) {
  e *s = (e *)a;

  e *t = (e *)b;

  if (s->s != t->s)

    return s->s - t->s;

  else

    return s->t - t->t;
}

int b[10001];

int find(int s, int value) {
  int i = 0, k;

  while (i <= s)

  {
    k = (i + s) >> 1;

    if (b[k] > value)
      s = k - 1;

    else
      i = k + 1;
  }

  return s;
}

void read() {
  int i, j, k;

  while (cin >> n) {
    if (n == 0) break;

    for (i = 0; i < n; i++) cin >> a[i].s >> a[i].t;

    qsort(a, n, sizeof(e), cmp);

    int m = 0;

    b[0] = a[0].t;

    for (i = 1; i < n; i++)

    {
      j = find(m, a[i].t);

      b[j + 1] = a[i].t;

      if (j + 1 > m) m = j + 1;
    }

    cout << m + 1 << endl;
  }

  cout << '*' << endl;
}

int main() {
  read();

  return 0;
}
