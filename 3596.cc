#include <cstdio>
#include <cmath>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const long double PI2=asin((long double)1);
const long double eps=1e-11;

long double xx1,yy1,zz1,r;
long double xx2,yy2,zz2,R;
long double xx3,yy3,zz3;
long double a,b,c;
long double xx,yy,alpha,beta;

long double len(long double xx,long double yy,long double zz=0) {
	return sqrt(xx*xx+yy*yy+zz*zz);
}
long double calAlpha() {
	if (R>r) return PI2+asin((R-r)/a);
	else acos((r-R)/a);
}
void calPos() {
	long double p=(a+b+c)/2;
	long double s=sqrt(p*(p-a)*(p-b)*(p-c));
	long double h=s*2/a;
	long double l=sqrt(c*c-h*h);
	yy=h;
	if (a*a+c*c-b*b>0) {
		xx=l;
	} else {
		xx=-l;
	}
}
long double calBeta() {
	return atan2(yy,xx)-acos(r/c);
}

int main() {
	cin >> xx1 >> yy1 >> zz1 >> r;
	cin >> xx2 >> yy2 >> zz2 >> R;
	cin >> xx3 >> yy3 >> zz3;
	a=len(xx1-xx2,yy1-yy2,zz1-zz2);
	b=len(xx3-xx2,yy3-yy2,zz3-zz2);
	c=len(xx1-xx3,yy1-yy3,zz1-zz3);
	alpha=calAlpha();
	calPos();
	beta=calBeta();
	if (c<=r+eps) cout << "No" << endl;
	else if (alpha>beta+eps) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}



