#include <iostream>
#include <string>

using namespace std;
int main()
{
 string a[1000],b[1000];
 int n;
 int j,k;
 int t;
 while(cin>>n&&n)
 {
  j=k=0;
  for(int i=0;i<n;i++)
  {
   cin>>a[i];
  }
  for(int i=0;i<n;i++)
   if(i%2==0)
  {
   
   b[j]=a[i];
   j++;
  }
  else
  {   
  
  b[n-k-1] = a[i];
                k++;
    }
     cout << "SET " << ++t << endl;
     for(int i=0; i<n; i++)
     cout << b[i] << endl;
  
  
 }
 return 0;
 
 
} 
