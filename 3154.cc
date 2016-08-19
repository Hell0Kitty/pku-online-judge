#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define F 10000
using namespace std;

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        double ans=0;
        for(int i=1;i<n;i++){
            double pos=(double)i/n*(n+m);//计算每个需要移动的雕塑的坐标
            ans+=fabs(pos-floor(pos+0.5))/(n+m);//累加移动距离
        }
        printf("%.4lf\n",ans*F);//等比例扩大坐标
    }
    return 0;
}



