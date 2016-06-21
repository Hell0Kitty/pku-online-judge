#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define ll long long

ll K,M;
int main(){
    ll i,j,k,cnt;
    while(~scanf("%lld%lld",&M,&K)){
        cnt=0;
        ll ten=1, temp=K, tt;
        while(K>=ten) ten*=10;
        ten/=10;
        cnt+=K-ten+1;
        tt=ten;
        temp/=10;
        tt/=10;
        while(temp>0){
            cnt+=temp-tt+1;
            temp/=10;
            tt/=10;
        }
        if(cnt>M) printf("0\n");
        else {
            if(cnt==M) {
                printf("%lld\n", K);
                continue;
            }
            temp=K*10,ten*=10;
            if(temp-ten==0){
                printf("0\n");
                continue;
            }
            while(cnt-ten+temp<M){
                cnt=cnt-ten+temp;
                temp*=10;
                ten*=10;
            }
            ten+=M-cnt-1;
            printf("%lld\n", ten);
        }
    }
    return 0;
}



