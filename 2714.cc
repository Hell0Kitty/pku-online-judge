#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int N=105;
double mx,my,cx,cy;

struct V{
	double x,y;
	bool operator < (const V &a) const{
		double t=atan2(y,x);
		double at=atan2(a.y,a.x);
		return t<at;
	}
}v[N<<1];

int main(){
	int n,i,ci,end;
	double x,y;
	while(~scanf("%d",&n)&&n){
		for(i=0;i<n;i++){
			scanf("%lf%lf",&x,&y);
			v[i<<1].x=x;
			v[i<<1].y=y;
			v[i<<1|1].x=-x;
			v[i<<1|1].y=-y;
		}
		sort(v,v+(n<<1));
		cx=cy=0;
		for(i=0;i<n;i++){
			cx+=v[i].x;
			cy+=v[i].y;
		}
		mx=cx;my=cy;
		for(i=0,end=n<<1;i<end;i++){
			ci=(i+n)%end;
			cx+=v[ci].x-v[i].x;
			cy+=v[ci].y-v[i].y;
			if(cx*cx+cy*cy>mx*mx+my*my)
				mx=cx,my=cy;
		}
		printf("Maximum distance = %.3f meters.\n",sqrt((double)mx*mx+my*my));
	}
	return 0;
}



