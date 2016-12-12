#include <iostream>
using namespace std;
int str[300];
int ans[300];
int N;
int sovel(int n)
{
 int i;
 memcpy(ans,str,sizeof(int)*(N+1));
 for(i = 1; i <= n; i++)
 {
  ans[2*i-1] = (str[i]+str[i+n])/2;
  ans[2*i] = str[i] - ans[2*i-1];
 }
 memcpy(str,ans,sizeof(int)*(N+1));
 return n*2;
}
int main() {
 int i,k;
 while(scanf("%d",&N) &&N)
 {
  for(i  =1; i <= N; i++)
  {
   scanf("%d",str+i);
  }
  k = 1;
  while(k != N)
   k = sovel(k);
  for(i =1; i <= N-1; i++)
  {
   printf("%d ",str[i]);
  }
  printf("%d\n",str[i]);
 }
 return 0;
}


