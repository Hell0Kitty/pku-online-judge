#include<iostream>
using namespace std;
inline __int64 len(__int64 k)//计算长度
{
 __int64 l=0;
 while(k)
 {
  l++;
  k/=10;
 }
 return l;
}
inline __int64 rank(__int64 k)//计算本来应该排在哪里
{
 if(k==1)
  return 1;
 __int64 re=0,i,l=len(k),t=1;
 for(i=0;i<l-1;i++)t*=10;
 re=k-t;
 while(t)
 {
  t/=10;
  k/=10;
  re+=(k-t+1);
 }
 return re;
}
inline bool f10(__int64 k)//是不是10的n次方的数字）
{
 __int64 kk=1,i;
 __int64 l=len(k);
 for(i=0;i<l-1;i++)kk*=10;
 if(kk==k)return true;
 return false;
}
bool mainn()
{
 __int64 k,m,t;
 if(EOF==scanf("%I64d%I64d",&k,&m))return false;
 t=rank(k);//至少应该在的位置
// printf("----%I64d\n",t);
 if(m<t)//如果比至少在的位置还靠前。不行
 {
  printf("0\n");
  return true;
 }
 if(m==t)
 {
  printf("%I64d\n",k);
  return true;
 }
 if(m>t)
 {
  if(f10(k))//是 10000这种的话 位置永远不变的
  {
   printf("0\n");
   return true;
  }
  __int64 p=1,l=len(k),i,kk,mm;//这个地方开始很绕人。。想了好久才出来的代码。
  for(i=0;i<l-1;i++)p*=10;
  mm=m-t-1;
  kk=k;
  while(1)
  { 
   if(kk*10-p*10>mm)break;
   kk*=10;
   p*=10;
   mm-=(kk-p);   
  }
  p*=10;
  p+=mm;
  printf("%I64d\n",p);
 }
 return true;
}
int main()
{
 bool mainn();
 while(mainn());
 return 0;
}



