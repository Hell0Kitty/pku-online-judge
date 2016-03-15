#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
#include <map>
#include <queue>
#include<cmath>
#include<vector>
#define maxn 32000+10
#define maxm 100010
#define mod 1000000000000000000
#define INF 0x3f3f3f3f
using namespace std;
struct node{
    double x;
    char name[1010];
    bool operator < (const node & a)const{
        return fabs(x)<fabs(a.x);
    }
}a[maxn];
int main (){
    int n;
    char ch[10];
    while(scanf("%d",&n)!=EOF){
        if(n==0)break;
        double l,v;
        scanf("%lf%lf",&l,&v);
        gets(ch);
        for(int i=0;i<n;++i){
            char dir[10];
            scanf("%s %lf %s",dir,&a[i].x,&a[i].name);
            gets(ch);
            if(dir[0]=='n'||dir[0]=='N'){
                a[i].x*=-1;
            }
        }
        sort(a,a+n);
        double ans =0;
        int ansid=0;
        bool flag =true;
        for(int i=0;i<n;++i){
            double last = (a[i].x<0?0:l)-a[i].x;
            if(last>ans+1e-6){
                ans=last;
                ansid=i;
                flag = a[i].x>0.0;
            }
        }
        int cnt=0;
        if(flag){
            for(int i=ansid;i<n;++i){
                if(a[i].x<0.0)cnt++;
            }
            ansid+=cnt;
        }
        else {
            for(int i=ansid;i>=0;--i){
                if(a[i].x>0.0)cnt++;
            }
            ansid-=cnt;
        }
        ans/=v;
        ans = (int)(ans*100)/100.0;
        printf("%13.2f %s\n",ans,a[ansid].name);
    }
}


