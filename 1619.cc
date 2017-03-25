#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=1000000+5;

inline void debug()
{
    printf("where is wrong?\n");
}

inline int max(int a,int b)
{
    return a>b?a:b;
}

inline int min(int a,int b)
{
    return a<b?a:b;
}

int res[maxn]={0};
int a[maxn];
int b[maxn]={0};

inline void make_table()
{
   int i,j,n,cur,k,an,p;
   res[1]=1;
   res[2]=2;

   for(i=0;i<maxn;i++)
    a[i]=i;
    a[2]=4;

   for(i=2;i<maxn;i++)
   {
      if(b[i]==0)
      {
        for(j=1;i*j<maxn;j++)
        {
            if(b[i*j]==0)
                b[i*j]=i;
        }
      }
   }

   cur=2;
   for(n=2;n<maxn;n++)
   {
     k=cur;
     cur=maxn;
     while(k!=1)
     {
         p=b[k];
         while(res[a[p]]!=0&&a[p]+p<maxn)//更新a[]
          a[p]+=p;
         cur=cur>a[p]?a[p]:cur;
         while(k%p==0)    //去除k的最小因子，继续比较
         k=k/p;
     }
     res[cur]=n+1;
   }
}

int main()
{
   int n;
   make_table();
   while(scanf("%d",&n)&&n)
   {
     printf("The number %d appears in location %d.\n",n,res[n]);
   }
   return 0;
}



