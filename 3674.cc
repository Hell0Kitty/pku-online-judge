#include <stdio.h>
#include <string.h>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int d[12][310],c[12],num[12],vis[12],v[12];
int ma,ml;
struct node {
 int p,e;
};
node ski[12];
int cmp2(node a,node b)
{
 return a.e>b.e;
}
int dfs(int p)
{
 int i;
 if(p>ml)
 {
  int tmp,tmpp,nexte;
  for(i=1;i<=ml-1;i++) ski[i].p=i , ski[i].e=c[i];
  sort(ski+1,ski+ml,cmp2);
  memset(vis,0,sizeof(vis));
  for(i=1;i<=ml-1;i++)
  {
   tmpp=ski[i].p;
   nexte=c[tmpp+1];
   num[tmpp+1]=d[nexte][ ++vis[nexte] ];
  }
  num[1]=d[ c[1] ][ ++vis[c[1]] ];
  tmp=0;
  for(i=1;i<=ml;i++)
   tmp=tmp+num[i]/10*(10+c[i-1]);
  if(tmp>ma) ma=tmp;
  return 0;
 }
 for(i=0;i<=10;i++)
 {
  if(v[i])
  {
   c[p]=i;
   v[i]--;
   dfs(p+1);
   v[i]++;
  }
 }
 return 0;
}
int cmp(int a,int b)
{
 return a>b;
}
int main()
{
 int n,i,a,b;
 while(scanf("%d",&n)!=EOF)
 {
  memset(d,0,sizeof(d));
  memset(v,0,sizeof(v));
  memset(c,0,sizeof(c));
  for(i=1;i<=n;i++)
  {
   scanf("%d%d",&a,&b);
   d[b][ ++d[b][0] ]=a;
  }
  for(i=0;i<=10;i++)
   if(d[i][0]) sort(d[i]+1,d[i]+1+d[i][0],cmp);
  for(i=0;i<=10;i++) v[i]=d[i][0];

  if(n<=6) ml=n;
  else ml=6;
  ma=0;
  dfs(1);
  printf("%d\n",ma);
 }
    return 0;
}



