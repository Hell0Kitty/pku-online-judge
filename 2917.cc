#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
    int T, i, n, ans, cas=1;
    scanf("%d", &T);
    while(T--){
        if(cas>1)printf("\n");
        scanf("%d", &n);
        ans=1;
        for(i=2; i<=sqrt(1.0*n); i++){
            if(n%i==0){
                int t=0;
                while(n%i==0){
                    n/=i;t++;
                }
                ans*=(2*t+1);
            }
        }
        if(n!=1)ans*=3;     
        printf("Scenario #%d:\n%d\n", cas++, (ans+1)/2);
    }
    return 0;
}



