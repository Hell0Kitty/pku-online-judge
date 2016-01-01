#include <queue>
#include <stack>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 110;
struct point{ double x,y;};		//点 
struct polygon{ point c[MAX],a; double area; int n;};
struct segment{ point a,b;};		// 线段 
const double eps = 1e-6;
bool dy(double x,double y)	{	return x > y + eps;}	// x > y 
bool xy(double x,double y)	{	return x < y - eps;}	// x < y 
bool dyd(double x,double y)	{ 	return x > y - eps;}	// x >= y 
bool xyd(double x,double y)	{	return x < y + eps;} 	// x <= y 
bool dd(double x,double y) 	{	return fabs( x - y ) < eps;}  // x == y
polygon king[MAX];
point c[MAX];
double crossProduct(point a,point b,point c)//向量 ac 在 ab 的方向 
{
	return (c.x - a.x)*(b.y - a.y) - (b.x - a.x)*(c.y - a.y);
}
double disp2p(point a,point b) 
{
	return sqrt( ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y ) );
}
double area_polygon(point p[],int n)
{
	double s = 0.0;
	for(int i=0; i<n; i++)
		s += p[(i+1)%n].y * p[i].x - p[(i+1)%n].x * p[i].y;
	return fabs(s)/2.0;
}
bool cmp(point a,point b)  // 排序   
{  
    double len = crossProduct(c[0],a,b);  
    if( dd(len,0.0) )  
        return xy(disp2p(c[0],a),disp2p(c[0],b));  
    return xy(len,0.0);  
}
bool onSegment(point a, point b, point c)
{
	double maxx = max(a.x,b.x);
	double maxy = max(a.y,b.y);
	double minx = min(a.x,b.x);
	double miny = min(a.y,b.y);
	if( dd(crossProduct(a,b,c),0.0) && dyd(c.x,minx) && xyd(c.x,maxx) && dyd(c.y,miny) && xyd(c.y,maxy) )
		return true;
	return false;
}
bool segIntersect(point p1,point p2, point p3, point p4) 
{
	double d1 = crossProduct(p3,p4,p1);
	double d2 = crossProduct(p3,p4,p2);
	double d3 = crossProduct(p1,p2,p3);
	double d4 = crossProduct(p1,p2,p4);
	if( xy(d1 * d2,0.0) && xy(d3 * d4,0.0) )	return true;
	if( dd(d1,0.0) && onSegment(p3,p4,p1) )		return true;//如果不判端点相交，则下面这四句话不需要 
	if( dd(d2,0.0) && onSegment(p3,p4,p2) )		return true;
	if( dd(d3,0.0) && onSegment(p1,p2,p3) )		return true;
	if( dd(d4,0.0) && onSegment(p1,p2,p4) )		return true;
	return false;
}
bool point_inPolygon(point pot,point p[],int n) 
{
	int count = 0;
	segment l;
	l.a = pot;
	l.b.x = 1e10*1.0;
	l.b.y = pot.y;
	p[n] = p[0];
	for(int i=0; i<n; i++)
	{
		if( onSegment(p[i],p[i+1],pot) )
			return true;
		if( !dd(p[i].y,p[i+1].y) )
		{
			int tmp = -1;
			if( onSegment(l.a,l.b,p[i]) )
				tmp = i;
			else
				if( onSegment(l.a,l.b,p[i+1]) )
					tmp = i+1;
			if( tmp != -1 && dd(p[tmp].y,max(p[i].y,p[i+1].y)) )
				count++;
			else
				if( tmp == -1 && segIntersect(p[i],p[i+1],l.a,l.b) )
					count++;
		}
	}
	if( count % 2 == 1 )
		return true;
	return false;
} 
point stk[MAX];
int top;
double Graham(int n)
{
    int tmp = 0;  
    for(int i=1; i<n; i++)
    	if( xy(c[i].x,c[tmp].x) || dd(c[i].x,c[tmp].x) && xy(c[i].y,c[tmp].y) )
    		tmp = i;
    swap(c[0],c[tmp]);
    sort(c+1,c+n,cmp);
    stk[0] = c[0]; stk[1] = c[1];
    top = 1;
	for(int i=2; i<n; i++)
	{
		while( xyd( crossProduct(stk[top],stk[top-1],c[i]), 0.0 ) && top >= 1 )
			top--;
		stk[++top] = c[i];
	}
	return area_polygon(stk,top+1);
}
int main()
{
	int n;
	int i = 0;
	double x,y;
	while( ~scanf("%d",&n) && n != -1 )
	{
		king[i].n = n;
		for(int k=0; k<n; k++)
			scanf("%lf %lf",&king[i].c[k].x,&king[i].c[k].y);
		king[i].a = king[i].c[0];
		i++;
	}

	double sum = 0.0;
	for(int k=0; k<i; k++)
	{
		memcpy(c,king[k].c,sizeof(king[k].c));
		king[k].area = Graham(king[k].n);
		memcpy(king[k].c,stk,sizeof(stk));
		king[k].n = top+1;
	}
	point pot;
	bool die[MAX];
	memset(die,false,sizeof(die));
	while( ~scanf("%lf %lf",&pot.x,&pot.y) )
	{
		for(int k=0; k<i; k++)
			if( point_inPolygon(pot,king[k].c,king[k].n) && !die[k] )
			{
				die[k] = true;
				sum += king[k].area;
			}
	}

	printf("%.2lf\n",sum);
return 0;
}


