#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#define N 5050

using namespace std;

int n,m,x,y,x2,y2;

struct node {
    int x1,x2;
    int y1,y2;
} a[N];
int ans[N];

bool cmp(node a,node b) {
    if(a.x1==b.x1)return a.x2<b.x2;
    return a.x1<b.x1;
}

int okleft(int i,int x,int y) {
    return (a[i].x1 - x) * (a[i].y2 - y) - (a[i].x2 - x) * (a[i].y1 - y);
}

int serch(int x,int y) {
    int l=0,r=n;
    int mid;
    while(l<r) {
        mid=(l+r)/2;
        if(okleft(mid,x,y)<0)
            r=mid;
        else
            l=mid+1;
    }
    return r;
}

int main() {
    while(~scanf("%d",&n)&&n) {
        scanf("%d%d%d%d%d",&m,&x,&y,&x2,&y2);
        for(int i=0; i<n; i++) {
            scanf("%d%d",&a[i].x1,&a[i].x2);
            a[i].y1=y;
            a[i].y2=y2;
        }
        sort(a,a+n,cmp);
        a[n].x1=x2,a[n].x2=x2;
        memset(ans,0,sizeof ans);
        int xm,ym;
        while(m--) {
            scanf("%d%d",&xm,&ym);
            int id=serch(xm,ym);
            ans[id]++;
        }
        for(int i=0; i<=n; i++)
            printf("%d: %d\n",i,ans[i]);
        printf("\n");
    }
    return 0;
}




