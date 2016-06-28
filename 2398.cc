
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N=5050;
const int INF=0x3f3f3f3f;
int n,m,x,y,x2,y2;
int ans[N],Ans[N];

struct P{
	int x1,x2;
	int y1,y2;
}a[N];

bool cmp(P a,P b){
	return a.x1==b.x1?a.x2<b.x2:a.x1<b.x1;
}

int det(int i,int x,int y){
	return (a[i].x1-x)*(a[i].y2-y)-(a[i].x2-x)*(a[i].y1-y);
}

int searchans(int x,int y){
	int l=0,r=n;
	int mid;
	while(l<r){
		mid=l+(r-l)/2;
		if(det(mid,x,y)<0)
			r=mid;
		else l=mid+1;
	}
	return r;
}

int main()
{
	while(~scanf("%d",&n)&&n){
		scanf("%d%d%d%d%d",&m,&x,&y,&x2,&y2);
		for(int i=0;i<n;i++){
			scanf("%d%d",&a[i].x1,&a[i].x2);
			a[i].y1=y;
			a[i].y2=y2;
		}
		sort(a,a+n,cmp);
		a[n].x1=x2,a[n].x2=x2;
		memset(ans,0,sizeof(ans));
		int xm,ym;
		while(m--){
			scanf("%d%d",&xm,&ym);
			int id=searchans(xm,ym);
			ans[id]++;
		}
		printf("Box\n");

		for(int i=1;i<=n;i++){
                int number=0;
            for(int j=0;j<=n;j++)
                if(ans[j]==i) number++;
            if(number) printf("%d: %d\n",i,number);
            }
		}
	return 0;
}



