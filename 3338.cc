#include <stdio.h>
#include <string.h>

const int step[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int n,m,t;
bool mp[22][22][4];
bool jud[22][22];

void dfs(int x,int y)
{
     jud[x][y] = 1;
     int i,j,p,q;
     for (i = 0;i < 4;i++)
     {
         if (i < 2)
            j = 1 - i;
         else
             j = 5 - i;
         p = x + step[i][0];
         q = y + step[i][1];
         if (p >= 0 && p < n && q >= 0 && q < m && !jud[p][q] && mp[x][y][i] == 0 && mp[p][q][j] == 0)
            dfs(p,q);
     }
}

int main()
{
    int i,j,k;
    int x1,y1,x2,y2,temp;
    while (scanf("%d%d", &m, &n) != EOF && (n || m))
    {
          scanf("%d", &t);
          memset(mp,0,sizeof(mp));
          for (k = 0;k < t;k++)
          {
              scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
              if (x1 > x2)
              {
                     temp = x1;
                     x1 = x2;
                     x2 = temp;
              }
              if (y1 > y2)
              {
                     temp = y1;
                     y1 = y2;
                     y2 = temp;
              }
              for (i = x1;i < x2;i++)
              {
                  mp[i][y1][3] = 1;
                  mp[i][y2 - 1][2] = 1;
              }
              for (j = y1;j < y2;j++)
              {
                  mp[x1][j][1] = 1;
                  mp[x2 - 1][j][0] = 1;
              }

          }
          memset(jud,0,sizeof(jud));
          int ans = 0;
          for (i = 0;i < n;i++)
          {
              for (j = 0;j < m;j++)
              {
                  if (!jud[i][j])
                  {
                                 dfs(i,j);
                                 ans++;
                  }
              }
          }
          printf("%d\n", ans);
    }
    return 0;
}


