#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

int su[340000];
void prime2(int n)
{for(int i=1;i<=n;i++)
        su[i]=1;
    su[1]=0;
    for(int i=4;i<=n;i=i+2)
        su[i]=0;
    int m1=sqrt(n+0.0);
    for(int j=3;j<=m1;j=j+2){
        if(su[j]==1){
            int m2=n/j;
            for(int k=j;k<=m2;k++){
                su[k*j]=0;
            }
        }
    }
}

int main()
{
    prime2(33000);
    int p;
    while(cin>>p){
        if(p==0)
            break;
        int ans=0;
        for(int i=2;i<p/2;i++){
            if(su[i]&&su[p-i])
                ans++;
        }
        if(su[p/2])
            ans++;
        cout<<ans<<endl;
    }
    return 0;
}


