#include <iostream>

using namespace std;
int a[3000]={2};
int b[10002]={0};
int is_ss(int x)
{
    int i,n=1;
    if(x%2==0)return 0;
    for(i=3;i*i<=x;i=i+2)
    {
        if(x%i==0){n=0;break;}
    }
    return n;
}
int main()
{
    int i,k,cou,t;
    for(i=3,cou=1;i<10001;i++)
    if(is_ss(i)==1)a[cou]=i,cou++;
    for(i=0;a[i]!=0;i++)
    {
        k=i;cou=a[k];
        while(cou<=10000)
        {
            b[cou]++;
            k++;
            cou+=a[k];
        }
    }
    while(cin>>t)
    {
        if(t==0)break;
        else cout<<b[t]<<endl;
    }
    return 0;
}



