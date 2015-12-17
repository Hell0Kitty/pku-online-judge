#include <stdio.h>
#include <math.h>
#include <iostream>
//#include <cmath>
using namespace std;
double p=(sqrt((double)5)+1)/double(2);

inline int myabs(int para){
    if( para < 0 ) return -1 * para;
    return para;
}

int main (){
    int a,b,c;
        while(scanf("%d%d",&a,&b)!=EOF){
        c = myabs(a-b);
        a=a>b?b:a;
        if(a==(int)(p*c)) printf("0\n");
        else printf("1\n");
    }
    return 0;
}
