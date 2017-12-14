#include <iostream>

using namespace std;

int n, m, num;

struct e {
  char c[20];

  int sum;
};

e a[101];

int cmp(const void *a, const void *b) {
  e s, t;

  s = *(e *)a;
  t = *(e *)b;

  if (s.sum != t.sum)

    return s.sum - t.sum;

  else

    return strcmp(s.c, t.c);
}

void read() {
  int i, j, k, s, t;

  cin >> k;

  for (int cas = 1; cas <= k; cas++)

  {
    printf("Case %d\n", cas);

    cin >> n >> m >> num;

    for (i = 0; i < num; i++)

    {
      char c;

      int top = 0;

      while (cin >> c)

      {
        if (c == ':') break;

        a[i].c[top++] = c;
      }

      a[i].c[top] = '\0';

      cin >> s >> c >> t;

      int n1 = n, m1 = m;

      int ans = 0;

      while (n1 / 2 >= m)

      {
        ans += min(t, (n1 - n1 / 2) * s);

        n1 /= 2;
      }

      while (n1 != m)

      {
        ans += s;

        n1--;
      }

      a[i].sum = ans;
    }

    qsort(a, num, sizeof(e), cmp);

    for (i = 0; i < num; i++) cout << a[i].c << ' ' << a[i].sum << endl;
  }
}

int main() {
  read();

  return 0;
}
