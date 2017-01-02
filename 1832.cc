#include <iostream>

#include <stdio.h>

#include <math.h>

#include <string.h>

using namespace std;

int s[1000], t[1000], f[200][200], ht[200], hs[200];

char str[2][205];

int main()

{
  int text;

  scanf("%d", &text);

  memset(f, 0, sizeof(f));

  f[1][199] = 1;

  for (int i = 2; i <= 128; i++)

  {
    for (int j = 199; j >= 1; j--)

    {
      f[i][j] = f[i - 1][j] * 2;
    }

    for (int j = 199; j >= 1; j--)

      if (f[i][j] > 9)

      {
        f[i][j - 1] += f[i][j] / 10;

        f[i][j] %= 10;
      }
  }

  while (text--)

  {
    int n;

    scanf("%d", &n);

    int sums = 0, sumt = 0;

    for (int i = 1; i <= n; i++)

    {
      scanf("%d", &s[i]);

      sums += s[i];
    }

    for (int i = 1; i <= n; i++)

    {
      scanf("%d", &t[i]);

      sumt += t[i];
    }

    for (int i = n; i >= 1; i--)

    {
      sums -= s[i];

      sumt -= t[i];

      if (sums % 2 == 1)

      {
        if (s[i] == 1)

          s[i] = 0;

        else

          s[i] = 1;
      }

      if (sumt % 2 == 1)

      {
        if (t[i] == 1)

          t[i] = 0;

        else

          t[i] = 1;
      }
    }

    memset(ht, 0, sizeof(ht));

    memset(hs, 0, sizeof(hs));

    for (int i = n, j = 1; i >= 1; i--, j++)

    {
      if (s[i] == 1)

      {
        for (int k = 199; k >= 1; k--)

        {
          hs[k] += f[j][k];

          if (hs[k] > 9)

          {
            hs[k - 1] += hs[k] / 10;

            hs[k] %= 10;
          }
        }
      }

      if (t[i] == 1)

      {
        for (int k = 199; k >= 1; k--)

        {
          ht[k] += f[j][k];

          if (ht[k] > 9)

          {
            ht[k - 1] += ht[k] / 10;

            ht[k] %= 10;
          }
        }
      }
    }

    for (int k = 199; k >= 1; k--)

    {
      if (hs[k] > 9)

      {
        hs[k - 1] += hs[k] / 10;

        hs[k] %= 10;
      }

      if (ht[k] > 9)

      {
        ht[k - 1] += ht[k] / 10;

        ht[k] %= 10;
      }
    }

    int w = 0;

    memset(str, 0, sizeof(str));

    str[0][0] = str[1][0] = '0';

    for (int i = 1; i <= 199; i++)

    {
      str[0][i - 1] = hs[i] + '0';

      str[1][i - 1] = '0' + ht[i];
    }

    if (strcmp(str[0], str[1]) > 0)

    {
      for (int k = 199; k >= 1; k--) hs[k] -= ht[k];

      for (int k = 199; k >= 1; k--)

        if (hs[k] < 0)

        {
          hs[k - 1]--;

          hs[k] += 10;
        }

    }

    else

    {
      for (int k = 199; k >= 1; k--) ht[k] -= hs[k];

      for (int k = 199; k >= 1; k--)

        if (ht[k] < 0)

        {
          ht[k - 1]--;

          ht[k] += 10;
        }

      w = 1;
    }

    if (w == 0)

    {
      int i;

      for (i = 1; i <= 199; i++)

        if (hs[i] != 0) break;

      for (; i <= 198; i++) printf("%d", hs[i]);

      printf("%d\n", hs[i]);

    }

    else

    {
      int i;

      for (i = 1; i <= 199; i++)

        if (ht[i] != 0) break;

      for (; i <= 198; i++) printf("%d", ht[i]);

      printf("%d\n", ht[i]);
    }
  }

  return 0;
}
