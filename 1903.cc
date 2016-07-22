#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cmath>
#include<map>
#include<algorithm>
#define ll long long
using namespace std;  
struct node
{
      int w[25],num;
}ans; 
char s[25][105]; 
int n;
map<int,node> mymap;
void dfs1(int i,int x,node h)
{ 
      int l,j; 
      if (mymap.find(x)==mymap.end()) mymap[x]=h; 
      if (mymap[x].num<h.num) mymap[x]=h;
      if (i>n/2) return;
      dfs1(i+1,x,h);
      l=strlen(s[i]);
      for (j=0;j<l;j++) x^=1<<(int)(s[i][j]-'A'); 
      h.w[++h.num]=i;
      dfs1(i+1,x,h);
      return;
}
void dfs2(int i,int x,node h)
{
      int l,j; 
      if (mymap.find(x)!=mymap.end() && mymap[x].num+h.num>ans.num)
      {
               ans=mymap[x];
               for (j=1;j<=h.num;j++) ans.w[++ans.num]=h.w[j];
      }
      if (i>n) return;
      dfs2(i+1,x,h);
      l=strlen(s[i]);
      for (j=0;j<l;j++) x^=1<<(int)(s[i][j]-'A'); 
      h.w[++h.num]=i;
      dfs2(i+1,x,h);
      return;
}
int main()
{    
      int i;
      node h;
      scanf("%d",&n);
      for (i=1;i<=n;i++) scanf("%s",s[i]);
      h.num=0;
      mymap.clear();
      dfs1(1,0,h);
      ans.num=0;
      dfs2(n/2+1,0,h);
      printf("%d\n",ans.num);
      for (i=1;i<=ans.num;i++) printf("%d ",ans.w[i]);
      return 0;
}



