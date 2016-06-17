#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int cow[20010];
int main()
{
 int N,L,cnt=0,i,j;
 scanf("%d%d",&N,&L);
 for(i=0;i<N;i++)
  scanf("%d",&cow[i]);
 sort(cow,cow+N);
 for(i=0;i<N-1;i++)
 {
  if(cow[i]+cow[i+1]>L)
   break;
  for(j=i+1;j<N;j++)
  {
   if(cow[i]+cow[j]<=L)
   {
    cnt++;
   }
   else 
    break;
  }
 }
 printf("%d\n",cnt);
 return 0;
}


