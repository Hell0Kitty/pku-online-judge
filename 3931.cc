#include <iostream>

using namespace std;

__int64 min(__int64 m,__int64 k)  

{

  if(m>k) return k;

  else return m;

}

__int64 max(__int64 m,__int64 k) 

{

  if(m<k) return k;

  else return m;

}

__int64 count(__int64 m,__int64 k)  

{

  __int64 n,n1,n2;

  if(m==1)    return 2*k-1;  

  else if(m%2==0) 

  {

    n=m/2-1+k;

    if(n>=m) return n;

    else return 0;

  }

  else

  {

    n1=count((m+1)/2,k)*2;    

    n2=count((m-1)/2,k)*2+1;     

if(n2==1) n2=0;

    if(n1>0&&n2>0) return min(n1,n2);

    else return max(n1,n2);

  }

}

int main()

{

  __int64 m,k,n;

  while(1)

  {

  scanf("%I64d%I64d",&m,&k);

  if(m==0&&k==0) break;

  n=count(m,k);

  if(n) printf("%I64d\n",n);

  else printf("Impossible\n");

  }

  return 0;

}


