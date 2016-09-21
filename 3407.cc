#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
char s[100],s1[100];
const double pi=acos(-1.0);
double solve(double a,double c,char s[])
{
	a=a+c/60;
	if(s[0]=='S' || s[0]=='W')
		a=-a;
	a=a*pi/180;
	return a;
}
int main()
{
	double a,b,c,d;
	double p1x,p2x,p1y,p2y;
	while(~scanf("%lf%lf%s%lf%lf%s",&a,&b,s1,&c,&d,s))
	{
		p1x=solve(a,b,s1);
		p1y=solve(c,d,s);
		scanf("%lf%lf%s%lf%lf%s",&a,&b,s1,&c,&d,s);
		p2x=solve(a,b,s1);
		p2y=solve(c,d,s);
		double xx= acos(sin(p1x) * sin(p2x) + cos(p1x) * cos(p2x) * cos(p2y - p1y)) * 6370;
		printf("%.3lf\n",xx);
	}
	return 0;
}



