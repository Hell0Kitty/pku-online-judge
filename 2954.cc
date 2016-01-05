#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
using namespace std;
typedef double DB;

inline int Gcd(int a,int b){return b==0? a:Gcd(b,a%b);}
inline int ABS(int x){return x<0? (-x):x;}

int main(){
    int a1,a2,a3,b1,b2,b3,B=0,I=0;
    double Area=0.0;
    while(1){
        scanf("%d%d%d%d%d%d",&a1,&b1,&a2,&b2,&a3,&b3);
		if(!a1 && !a2 && !a3 && !b1 && !b2 && !b3)break;
		Area=0.0; B=I=0;
		Area+=a1*b2-a2*b1; Area+=a2*b3-a3*b2; Area+=a3*b1-a1*b3;
		Area=fabs(Area/2.0);
		B+=Gcd(ABS(a2-a1),ABS(b2-b1));
		B+=Gcd(ABS(a3-a2),ABS(b3-b2));
		B+=Gcd(ABS(a1-a3),ABS(b1-b3));
		I=(int)Area+1-B/2;
		printf("%d\n",I);
	}
    return 0;
}



