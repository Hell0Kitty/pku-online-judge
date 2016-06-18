#include <iostream>
#include <cmath>
using namespace std;
int main()
{double rate,b[13],sum,q;
 int n,i,a[13],k,cae=0;
 cin>>n;
 while (n!=-1)
 {rate=0.000;k=6;q=0.1;
  for (i=0;i<=n;i++)
  cin>>a[i]>>b[i];
  while (k)
  {rate=rate+q+1.0;
   sum=0;
   for (i=0;i<n;i++)
    sum=sum+b[i]*pow(rate,a[n]-a[i]+1);
   rate=rate-1.0;
   if (sum-b[n]>1e-8) {rate=rate-q;
                       k--;
        q=q/10;}
  }
  cout<<"Case "<<++cae<<": ";
  printf("%.5f",rate);
  cout<<endl;cin>>n;
  if (n!=-1) cout<<endl;

 }
 return 0;
}



