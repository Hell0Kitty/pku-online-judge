#include<iostream>
#include<cstdio>
#include<cmath>
#define N 1000005
using namespace std;
int prime[N];
void isprime(){
    int i;
    for(i=0;i<N;i++)
        prime[i]=1;
    for(i=3;i<1000;i+=2){
        if(!prime[i]) continue;
        for(int j=i;j<=N/i;j+=2)
            prime[i*j]=0;
    }
}
int main(){
    isprime();
    while(1){
        int n;
        scanf("%d",&n);
        if(n==0)  break;
        for(int i=3;i<n;i+=2){
            if(prime[i]&&prime[n-i]){
                printf("%d = %d + %d\n",n,i,n-i);
                break;
            }
        }
    }
    return 0;
}



