nclude<cstdio>

#include <cstring>

#include <algorithm>

    using namespace std;

const double eps = 1e-8;

struct data

    {
  int h, m, s;

  double tot, speed;

  data(int _h, int _m, int _s)

  {
    h = _h;
    m = _m;
    s = _s;

    tot = _h * 60 + _m + _s / 60.0;

    speed = 0;
  }

  data() {}

  void print()

  {
    if (speed < eps)

      printf("-\n");

    else

    {
      speed += 1 / 120.0;

      int a = (int)speed, b = (int)(60.0 * (speed - (int)speed));

      printf("%d:", a);

      if (b < 10)

        printf("0%d min/km\n", b);

      else

        printf("%d min/km\n", b);
    }
  }

  data operator+(const data &b) const

  {
    data a;

    a.h = h + b.h;

    a.m = m + b.m;

    a.s = s + b.s;

    a.tot = a.h * 60.0 + a.m + a.s / 60.0;

    a.speed = 0;

    return a;
  }
};

int main()

{
  int n, id;

  double d;

  scanf("%d%lf", &n, &d);

  while (scanf("%d", &id) != EOF)

  {
    data a(0, 0, 0);

    int h, m, s;

    printf("%3d: ", id);

    bool flag = false;

    for (int i = 0; i < n; i++)

    {
      char ss[30];

      scanf("%s", ss);

      if (ss[0] == '-' || flag)

      {
        flag = true;

        continue;
      }

      sscanf(ss, "%d:%d:%d", &h, &m, &s);

      a = a + data(h, m, s);
    }

    if (!flag) a.speed = a.tot / d;

    a.print();
  }

  return 0;
}
