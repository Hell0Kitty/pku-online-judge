#include <stdio.h>
#include <string.h>

int n,m,p;
int a[130],b[130];

int main()
{
    int i,j,k;
    while (scanf("%d", &n) != EOF && n != -1)
    {
          scanf(",%d,%d", &m, &p);
          for (i = 0;i < m;i++)
              a[i] = 0;
          for (;i < n;i++)
              a[i] = 1;
          for (k = 1;k <= p;k++)
          {
              if (k % 2)
              {
                    for (i = 0;i < n - 1;i++)
                    {
                        if (a[i] == a[i + 1])
                           b[i] = 1;
                        else
                            b[i] = 0;
                    }
                    if (a[n - 1] == a[0])
                       b[n - 1] = 1;
                    else
                        b[n - 1] = 0;
              }
              else
              {
                    for (i = 0;i < n - 1;i++)
                    {
                        if (b[i] == b[i + 1])
                           a[i] = 1;
                        else
                            a[i] = 0;
                    }
                    if (b[n - 1] == b[0])
                       a[n - 1] = 1;
                    else
                        a[n - 1] = 0;
              }
          }
          int ct=  0;
          if (p % 2)
          {
                for (i = 0;i < n;i++)
                {
                    if (b[i] == 0)
                       ct++;
                }
          }
          else
          {
                for (i = 0;i < n;i++)
                {
                    if (a[i] == 0)
                       ct++;
                }
          }
          printf("%d,%d,%d: %d\n", n, m, p, ct);
    }
    return 0;
}



