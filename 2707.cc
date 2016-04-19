#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<cmath>

using namespace std;

int A,B,C,D;
int main(){
    int i,j,k;
    while(scanf("%d%d%d%d",&A,&B,&C,&D), A||B||C||D){
        double a = min((double)C/A,(double)D/B);
        double b = min((double)C/B,(double)D/A);
        double ans = max(a,b);
        if(ans > 1) ans = 1;
        printf("%d%%\n",(int)(ans*100));
    }
    return 0;
}



