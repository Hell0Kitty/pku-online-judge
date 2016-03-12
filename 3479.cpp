#include "iostream"
#include "string.h"
#include "memory.h"
#include "stdlib.h"
using namespace std;
#define M 25
#define N 1020
typedef struct
{
int p;
int q;
}com1;
com1 a[N][N];
char s[N][M],s1[M],c;
int t,n,b,sptr,ptr[N],money;
int init()
{
int i,j,k;
bool judge;
memset(a,0,sizeof(a));
memset(s,0,sizeof(s));
memset(s1,0,sizeof(s1));
memset(ptr,0,sizeof(ptr));
sptr = 0;
scanf("%d%d",&n,&b);
getchar();
for (i = 1;i <= n;i ++)
{
scanf("%s",s1);
judge = 0;
for (j = 1;j <= sptr;j ++)
if (strcmp(s[j],s1) == 0)
{
judge = 1;
k = j;
break;
}
if (judge == 0)
{
sptr ++;
strcpy(s[sptr],s1);
k = sptr;
}
scanf("%s",&s);
ptr[k] ++;
scanf("%d%d",&a[k][ptr[k]].p,&a[k][ptr[k]].q);
getchar();
}
return 0;
}
int cmp(const void * a,const void * b)
{
return (((com1 *)a)->p) - (((com1 *)b)->p);
}
int solve()
{
int i,j;
for (i = 1;i <= sptr;i ++)
qsort(a[i] + 1,ptr[i],sizeof(com1),cmp);
int min,mid,max;
min = 0;
max = 1000000000;
bool judge,judge2;
while (max - min >= 2)
{
mid = (min + max) / 2;
money = 0;
judge2 = 1;
for (i = 1;i <= sptr;i ++)
{
judge = 0;
for (j = 1;j <= ptr[i];j ++)
{
if (a[i][j].q >= mid)
{
money += a[i][j].p;
judge = 1;
break;
}
}
if (judge == 0)
judge2 = 0;
}
if (judge2 == 0)
{
max = mid;
continue;
}
if (money > b)
max = mid;
if (money <= b)
min = mid;
}
mid = min + 1;
money = 0;
judge2 = 1;
for (i = 1;i <= sptr;i ++)
{
judge = 0;
for (j = 1;j <= ptr[i];j ++)
{
if (a[i][j].q > mid)
{ money += a[i][j].p;
judge = 1;
break;
}
}
if (judge == 0)
judge2 = 0;
}
if (money > b)
judge2 = 0;
if (judge2 == 1)
min ++;
printf("%d\n",min);
return 0;
}
int main()
{
// freopen("3.txt","r",stdin);
scanf("%d",&t);
while(t-- > 0)
{
init();
solve();
}
return 0;
}
 
