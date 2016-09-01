#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 50000+5
struct point{
	int landmark,distance;
}p[MAX];
bool cmp(point a,point b){
	if (a.distance<b.distance)
		return true;
	return false;
}
int main(){
	int t,n;
	while (cin>>t>>n){
		for (int i=0;i<n;i++){
			cin>>p[i].landmark;
			p[i].distance=p[i].landmark>0?p[i].landmark:(-p[i].landmark);
		}
		sort(p,p+n,cmp);

		int last=0,i;
		for (i=0;i<n;i++){
			int d=p[i].landmark-last>0?(p[i].landmark-last):(last-p[i].landmark);
			if (t>=d){
				t-=d;
				last=p[i].landmark;
			}
			else
				break;
		}
		cout<<i<<endl;
	}
	return 0;
}



