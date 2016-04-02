#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int m;
        cin>>m;
        if(m<=3) cout<<0<<endl;
        else
        {
            if(m%2==0) cout<<((m-3)*2+(m-4)*(m-2))/2 <<endl;
            else cout<<m*(m-3)/2<<endl;
        }

    }
}


