#include <iostream>
#include<cstdio>
using namespace std;

long long a[1200][200]={0},b[1200][120]={0};

int main()
{
    int i,j,n,m,k;
    long long inf,x;
    inf=1;
    for(i=0;i<18;i++)
    {
        inf=inf*10;
    }
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        b[i][1]=0;
        a[i][1]=1;
        for(j=2;j<=m;j++)
        {
            if(j>i)
            {
                a[i][j]=a[i][j-1];
                b[i][j]=b[i][j-1];
                continue;
            }
            a[i][j]=a[i][j-1];
            b[i][j]=b[i][j-1];
            for(k=1;k*j<=i;k++)
            {
                if(i-j*k==0)
                {
                    a[i][j]++;
                    b[i][j]+=a[i][j]/inf;
                    a[i][j]=a[i][j]%inf;
                }
                else {
                    b[i][j]+=b[i-j*k][j-1];
                    a[i][j]+=a[i-j*k][j-1];
                    b[i][j]+=a[i][j]/inf;
                    a[i][j]=a[i][j]%inf;
                }
            }
        }
    }
    if(b[n][m]!=0)
    {
        cout<<b[n][m];
    }
    cout<<a[n][m]<<endl;
    return 0;
}



