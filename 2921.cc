#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const double pi=acos(-1);
const int maxn=10010;
double a[maxn];
int n;
int bi_search(double x){
    int l=0,mid,r=n-1;
    if(a[r]<x)return n-1;
    if(a[l]>x)return 0;
    while(l<=r){
        mid=(l+r)/2;
        if(a[mid]>x)r=mid-1;
        else l=mid+1;

    }
    return r;

}
int main(){
    int cas;
    scanf("%d",&cas);
    for(int ii=1;ii<=cas;ii++){
        double p,q,x=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&p,&q);
            a[i]=2.0*pi*p/q;
        }
        sort(a,a+n);

        for(int i=0;i<n;i++){
            if(a[i]<=pi){
                int j=bi_search(a[i]+pi);
                p=a[j]-a[i];
            }
            else{
                int j=bi_search(a[i]-pi);
                p=a[i]-a[j];
            }
            x=sqrt(2.0*(1-cos(x)))>sqrt(2.0*(1-cos(p)))?x:p;
        }
        printf("Scenario #%d:\n%.2f\n\n",ii,sqrt(2.0*((double)n*(double)n)*(1-cos(x))));

    }
    return 0;
}


