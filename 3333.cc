#include <stdio.h>
#include <string.h>

int t,n;

struct str{
 int a,b,c;
};

str st[110];
bool jud[110];
int ans;

void dfs(int k, int now)
{
 if (k == n)
 {
 if (now > ans)
 ans = now;
 return;
 }
 if (jud[k])
 dfs(k + 1, now + st[k].a);
 else
 {
 if (st[k].c > k)
 {
 jud[k] = 1;
 dfs(k + 1, now + st[k].a);
 jud[k] = 0;
 }
 jud[k] = 1;
 dfs(st[k].c, now + st[k].b);
 jud[k] = 0;
 }
}

int main()
{
 int i,j,k;
 scanf("%d", &t);
 for (k = 1;k <= t;k++)
 {
 scanf("%d", &n);
 for (i = 0;i < n;i++)
 {
 scanf("%d%d%d", &st[i].a, &st[i].b, &st[i].c);
 st[i].c--;
 }
 memset(jud,0,sizeof(jud));
 ans = 0;
 dfs(0,0);
 printf("%d\n", ans);
 }
 return 0;
}



