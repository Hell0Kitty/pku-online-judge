#include <cstring>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

int a[15] = {15,12,9,7,6,5,4,3,2,1};
struct da
{
       char name[100],gongju[100];
       int g[100],biao,score,vote;
}fuck[100];
bool ck[100],sb[100],dasb[100];

int Min(int x,int y)
{
    return x>y?y:x;
}

bool cmp(da xx, da yy)
{
     if (xx.score > yy.score) return true;
     if (xx.score < yy.score) return false;
     if (xx.vote > yy.vote) return true;
     if (xx.vote < yy.vote) return false;
     if (xx.biao < yy.biao) return true;
     else return false;
}

int main()
{ 
    int i,j,m,n,k,nn;
    char ch[100];

    k = 0;
    while (scanf("%d",&n) != EOF)
    {
          if (n < 0) break;
          scanf("%d",&m);
          memset(fuck,0,sizeof(fuck));
          memset(sb,0,sizeof(sb));
          memset(dasb,0,sizeof(dasb));
          for (i=1;i<=n;i++)
          {
              scanf("%s %s %s",ch,fuck[i].name,fuck[i].gongju);
              fuck[i].biao = (ch[0] - '0')*10 + ch[1]-'0';
              dasb[fuck[i].biao] = true;
          }
          dasb[0] = true;
          for (i=1;i<=m;i++)
          {
              scanf("%s",ch);
              nn = strlen(ch);
              memset(ck,0,sizeof(ck));
              for (j=0;j<nn;j+=2)
              {
                  k = (ch[j]-'0') * 10 + (ch[j+1] - '0');
                  if ((ck[k] && k > 0) || !dasb[k]) break;
                  else ck[k] = true;
              }
              if (j >= nn)
              {
                    for (j=0;j<nn;j+=2)
                    {
                        k = (ch[j]-'0') * 10 + (ch[j+1] - '0');
                        for (int x=1;x<=n;x++)
                          if (fuck[x].biao == k) 
                          {
                                        fuck[x].score += a[j/2];
                                        fuck[x].vote++;
                                        fuck[x].g[j/2 + 1]++;
                          }
                    }
              }
          }
         sort(fuck+1,fuck+n+1,cmp);
         for (i=1;i<=Min(10,n);i++)
         {
             printf("%-4d%02d  %-14s %-37s%6d%6d",i,fuck[i].biao,fuck[i].name,fuck[i].gongju,fuck[i].score,fuck[i].vote);
             for (j=1;j<=10;j++)
             printf("%6d",fuck[i].g[j]);
             printf("\n");
         }
    }

    return 0;
}



