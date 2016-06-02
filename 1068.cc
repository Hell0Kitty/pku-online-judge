#include<iostream>
#include<string.h>
using namespace std;
int a[101];
int main()
{
    int n,m,bf,x,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        bf=0;
        memset(a,0,sizeof(a));
        while(n--)
        {
           cin>>m;
           bf=m;
           while(a[m])
           {
             m-=a[m];
             a[bf]+=a[m];
           }
           a[bf]++;
           cout<<a[bf]<<' ';

        }
        cout<<endl;
    }
}


