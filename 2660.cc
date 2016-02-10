#include <iostream>
#include <cmath>
using namespace std;
const double pi=acos(-1.0);
const double radius=20000.0/pi;

struct P
{
	double x,y,z,angle;
}satellite[128];

double dist(double x,double y,double z)
{
	return sqrt(x*x+y*y+z*z);
}

bool judge(double x,double y,double z,int k)
{
	for(int i=0;i<k;++i){
		double a=dist(x,y,z);
		double b=dist(satellite[i].x,satellite[i].y,satellite[i].z);
		double c=dist(satellite[i].x-x,satellite[i].y-y,satellite[i].z-z);
		double tmp_angle=acos((a*a+b*b-c*c)/(2*a*b));		
		if(tmp_angle<satellite[i].angle)
			return true;
	}
	return false;
}
int main()
{
	int k,m;
	while(scanf("%d%d",&k,&m)==2){
		if(k==0&&m==0)
			break; 
		int cnt=0;
		for(int i=0;i<k;++i){
			scanf("%lf%lf%lf",&satellite[i].x,&satellite[i].y,&satellite[i].z);
			satellite[i].angle=acos(radius/dist(satellite[i].x,satellite[i].y,satellite[i].z));
		}
		for(int i=0;i<m;++i){
			double x,y,z;
			scanf("%lf%lf%lf",&x,&y,&z);
			if(judge(x,y,z,k))
				++cnt;
		}
		printf("%d\n",cnt);
	}	
	return 0;	
}



