#include<stdio.h>
#include<iostream>
using namespace std;
main()
{
    int M,N;
    while(scanf("%d%d",&M,&N)!=EOF)
    {
        if (M==1||N==1) cout<<(M+N)/2<<endl;

          else cout<<((M*N)%3?1:2)<<endl;
    }

          return 0;

}



