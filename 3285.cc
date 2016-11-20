#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include<map>
#include<ctime>
using namespace std;
const double eps=1e-6;
const double inf=1e9;
bool dy(double x,double y)  {   return x > y + eps;} // x > y   
bool xy(double x,double y)  {   return x < y - eps;} // x < y   
bool dyd(double x,double y) {   return x > y - eps;} // x >= y   
bool xyd(double x,double y) {   return x < y + eps;}     // x <= y   
bool dd(double x,double y)  {   return fabs( x - y ) < eps;}  // x == y  
const int NUM=20;
const int RAD=1000;
struct point
{
	double x,y,val;
	point(){}
	point(double _x,double _y):x(_x),y(_y){}
}p[3],May[NUM],e1,e2;
int n;
double X,Y;
double dis(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double judge(point t)//评价函数，得到点t的评价值val
{
	double Sin[3],avg,sum=0.0;
	for(int i=0;i<3;i++){ Sin[i]=p[i].val/dis(t,p[i]);sum+=Sin[i];}
	avg=(sum)/3.0;
	sum=0.0;
	for(int i=0;i<3;i++) sum+=sqrt(10*(Sin[i]-avg)*(Sin[i]-avg));
	return sum;
}
double Rand(){return rand()%(RAD+1)/(1.0*RAD);}//随机产生0-1的浮点数
point Rand_point(point a,point b)//在a,b框定的四边形内随机生成点
{
	double xx=a.x+(b.x-a.x)*Rand();
	double  yy=a.y+(b.y-a.y)*Rand();
	point tmp=point(xx,yy);
	tmp.val=judge(tmp);
	return tmp;
}
void solve(double D)
{
	for(int i=0;i<NUM;i++)
	May[i]=Rand_point(e1,e2);//步骤2
	while(D>0.001)//步骤 3
	{
		for(int i=0;i<NUM;i++)
		for(int j=0;j<NUM;j++)
		{
			point tmp=Rand_point(point(max(e1.x,May[i].x-D),max(e1.y,May[i].y-D)),point(min(e2.x,May[i].x+D),min(e2.y,May[i].y+D)));
			if(tmp.val<May[i].val)
			{
				May[i]=tmp;
			}
		}
		D*=0.9;
	}
	point ans;
	ans.val=inf;
	for(int i=0;i<NUM;i++)
	if(ans.val>May[i].val)
	ans=May[i];
	if(ans.val<eps)
	printf("%.2f %.2f\n",ans.x,ans.y);
	else 
	puts("No solution");
}
int main()
{
	srand(time(0));
	while(1)
	{
	e2=point(-inf,-inf);
	e1=point(inf,inf);
		int num=0;
		for(int i=0;i<3;i++)
		{
		scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].val);
		e1.x=min(p[i].x,e1.x);
		e1.y=min(p[i].y,e1.y);
		e2.x=max(p[i].x,e2.x);
		e2.y=max(p[i].y,e2.y);
		if(dd(p[i].x,0.0)&&dd(p[i].y,0.0)&&dd(p[i].val,0.0))
		num++;
		}
		if(num==3)break;
		solve(max(e2.x-e1.x,e2.y-e1.y));
	}
}



