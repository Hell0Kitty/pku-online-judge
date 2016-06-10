#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double x1,x2,x3,y1,y2,y3,h;
	while(cin>>x1>>y1>>x2>>y2>>x3>>y3>>h){
		double a=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
		double b=(x3-x1)*(x3-x1)+(y3-y1)*(y3-y1);
		double c=(x3-x2)*(x3-x2)+(y3-y2)*(y3-y2);
		double s=a+b+c;
		double x=(x1*c+x2*b+x3*a)/s;
		double y=(y1*c+y2*b+y3*a)/s;
		cout<<fixed<<setprecision(2)<<x<<' '<<y<<endl;
	}
	return 0;
}



