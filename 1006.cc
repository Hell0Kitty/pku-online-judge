#include<iostream>
using namespace std;
int main()
{
    int i,p,e,d,w,ci=1;
    cin>>p>>e>>i>>d;
    
        while(p!=-1)
        {
            p%=23;
            e%=28;
            i%=33;
            w=(5544*p+14421*e+1288*i)%21252;
            if(w<=d)
                w+=(21252-d);
            else
                w-=d;
            printf("Case %d: the next triple peak occurs in %d days.\n",ci++,w);

cin>>p>>e>>i>>d;
    
    }
        return 0;
}

