#include<iostream>
using namespace std;

int quick_mod(int a,int b,int m)  
{
   a=a%m;
   int ans=1;
   while(b)
   {
     if(b&1)
     {
        ans=(ans*a)%m;
     }
     b>>=1;
     a=(a*a)%m;
   }

   return ans;
}

int main()
{
   int size;
   cin>>size;
   int m, h, a, b;
   while(cin>>m>>h)
   {
      int ans=0;
        for(int i=0;i<h;i++)
        {
            cin>>a>>b;
          ans=(ans+quick_mod(a,b,m))%m;
        }
      cout<<ans<<endl;
   }
}



