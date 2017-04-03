#include <iostream>

#include <queue>

#include <stack>

#include <stdio.h>

#include <string.h>

using namespace std;

int a[7005], vist[7005], flg;

int gcd(int m, int n)

{
  if (m < n)

  {
    int tmp = m;

    m = n;

    n = tmp;
  }

  int r;

  while (m % n != 0)

  {
    r = m % n;

    m = n;

    n = r;
  }

  return n;
}

void digui(int b[], int c[], int d[], int num, int n)

{
  if (b[flg] == num)

  {
    d[flg] = c[num];

    vist[flg] = 1;

    return;
  }

  int i = 1;

  for (; i <= n; i++)

    if (b[i] == num) break;

  digui(b, c, d, i, n);

  d[i] = c[num];

  vist[i] = 1;
}

int main()

{
  int n;

  while (scanf("%d", &n) > 0 && n)

  {
    queue<int> Q;

    stack<int> s1;

    stack<int> s2;

    stack<int> s3;

    for (int i = 1; i <= n; i++)

    {
      a[i] = i;

      Q.push(a[i]);
    }

    int i = 1;

    while (1)

    {
      if (i > 1440) break;

      int tmp = Q.front();

      Q.pop();

      if (i % 5 != 0)

        s1.push(tmp);

      else

      {
        s1.push(tmp);

        int tmp1 = s1.top();

        s1.pop();

        s2.push(tmp1);

        while (!s1.empty())

        {
          int tmp2 = s1.top();

          s1.pop();

          Q.push(tmp2);
        }
      }

      if (i % 60 == 0)

      {
        int tmp1 = s2.top();

        s2.pop();

        s3.push(tmp1);

        while (!s2.empty())

        {
          int tmp2 = s2.top();

          s2.pop();

          Q.push(tmp2);
        }
      }

      if (i % 720 == 0)

      {
        int tmp1 = s3.top();

        s3.pop();

        while (!s3.empty())

        {
          int tmp2 = s3.top();

          s3.pop();

          Q.push(tmp2);
        }

        Q.push(tmp1);
      }

      i++;
    }

    int b[7005], c[7005], d[7005];

    int j = 1;

    while (!Q.empty())

    {
      int tmp1 = Q.front();

      Q.pop();

      c[j] = b[j] = tmp1;

      j++;
    }

    memset(a, -1, sizeof(a));

    for (i = 1; i <= n; i++)

      if (b[i] == i) a[i] = 1;

    int w = 1;

    while (1)

    {
      for (i = 1; i <= n; i++)

        if (a[i] == -1) break;

      if (i > n) break;

      i = 1;

      memset(vist, 0, sizeof(vist));

      while (i <= n)

      {
        if (!vist[i])

        {
          flg = i;

          digui(b, c, d, i, n);
        }

        i++;
      }

      w++;

      j = 1;

      for (; j <= n; j++)

      {
        c[j] = d[j];

        if (a[j] == -1 && d[j] == j)

        {
          a[j] = w;
        }
      }
    }

    int tmp = a[1];

    for (i = 2; i <= n; i++)

    {
      tmp = tmp * a[i] / gcd(tmp, a[i]);
    }

    printf("%d balls cycle after %d days.\n", n, tmp);
  }

  return 0;
}
