#include<iostream>
#include<algorithm>
#include<string.h>
#include<stack>
#include<set>
#include<queue>
#include<math.h>
#include<cstdio>

#define mm(a,b) memset(a,b,sizeof(a))
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const int MAXN = 105;

struct Point
{
    double x, y;
    int id;         
    Point() { }
    Point( double x, double y ):x(x), y(y) { }
    Point( double x, double y, int id ):x(x), y(y), id(id) { }
};

struct Circle
{
    Point c;   
    double r;  
    Circle() {}
    Circle( Point c, double r ): c(c), r(r) {}
    Point getPoint( double theta )   
    {
        return Point( c.x + cos(theta)*r, c.y + sin(theta)*r );
    }
};
int cnt;

typedef Point Vector;

Vector operator+( Vector A, Vector B )      
{
    return Vector( A.x + B.x, A.y + B.y );
}

Vector operator-( Vector A, Vector B )       
{
    return Vector( A.x - B.x, A.y - B.y );
}

Vector operator*( Vector A, double p )    
{
    return Vector( A.x * p, A.y * p );
}

Vector operator/( Vector A, double p )     
{
    return Vector( A.x / p, A.y / p );
}

int dcmp( double x )    
{
    if ( fabs(x) < eps ) return 0;
    else return x < 0 ? -1 : 1;
}

bool operator<( const Point& A, const Point& B )   
{
    return dcmp( A.x - B.x) < 0 || ( dcmp(A.x - B.x ) == 0 && dcmp( A.y - B.y ) < 0 );
}

bool operator>( const Point& A, const Point& B )  
{
    return dcmp( A.x - B.x) > 0 || ( dcmp(A.x - B.x ) == 0 && dcmp( A.y - B.y ) > 0 );
}

bool operator==( const Point& a, const Point& b )  
{
    return dcmp( a.x - b.x ) == 0 && dcmp( a.y - b.y ) == 0;
}

double Cross( Vector A, Vector B )   
{
    return A.x * B.y - A.y * B.x;
}

double PointDis( Point a, Point b ) 
{
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

double dist(Point a,Point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));	
}
int graham( Point *p, int n, Point *ch )
{
    if ( n <= 2 ) return 0;
    int top = 0;
    sort( p, p + n );

    ch[ top ] = p[0];
    ch[ ++top ] = p[1];
    ch[ ++top ] = p[2];

    top = 1;

    for ( int i = 2; i < n; ++i )
    {
        while ( top && dcmp( Cross( ch[top] - ch[top - 1], p[i] - ch[top - 1] ) ) <= 0 ) --top;
        ch[++top] = p[i];
    }
    int len = top;
    ch[++top] = p[n - 2];
    for ( int i = n - 3; i >= 0; --i )
    {
        while ( top > len && dcmp( Cross( ch[top] - ch[top - 1], p[i] - ch[top - 1] ) ) <= 0 ) --top;
        ch[++top] = p[i];
    }
    return top;
}
bool getTangentPoints( Point p, Circle C, Point *tps, int idd )
{
    double dis = sqrt( PointDis( p, C.c ) );
    int aa = dcmp( dis - C.r );
    if ( aa < 0 ) return 0;  
    else if ( aa == 0 ) 
        return 0;
    double base = atan2( p.y - C.c.y, p.x - C.c.x );
    double ang = acos( C.r / dis );

    tps[cnt] = C.getPoint( base - ang ), tps[cnt++].id=idd;
    tps[cnt] = C.getPoint( base + ang ), tps[cnt++].id=idd;
    return 1;
}
void makeCircle( Circle c1, Circle c2, Point *p , int idd )
{
    double d = sqrt( PointDis(c1.c, c2.c) ), dr = c1.r - c2.r;
    double b = acos(dr / d);
    double a = atan2( c2.c.y - c1.c.y, c2.c.x - c1.c.x );
    double a1 = a - b, a2 = a + b;
    p[cnt] = Point(cos(a1) * c1.r, sin(a1) * c1.r) + c1.c;
    p[cnt++].id = idd;
	p[cnt] = Point(cos(a2) * c1.r, sin(a2) * c1.r) + c1.c;
    p[cnt++].id = idd;
}

double DisOnCircle( Point a, Point b, Circle c )  
{
    Point o = c.c;
    double A = sqrt( PointDis( o, a ) );
    double B = sqrt( PointDis( o, b ) );
    double C = sqrt( PointDis( a, b ) );
    double alpha = acos( ( A*A + B*B - C*C ) / ( 2.0*A*B ) );
    if ( dcmp( Cross( o-a, o-b ) ) < 0 ) return alpha * c.r;
    else return ( 2.0*PI - alpha ) * c.r;
}

double getarea(Point *p, int n)
{
	double area=0;
	p[n]=p[0];
	for(int i=0;i<n;i++)
		area+=p[i].x*p[i+1].y-p[i+1].x*p[i].y;
	return area*0.5;
}

double getarea2(Point a,Point b,Point c,Point d)
{
	double area=0;	
	area+=Cross(a,b)+Cross(b,c)+Cross(c,d)+Cross(d,a);
	return area*0.5;
}

int main()
{
	int n,cntc,m,nn,e;
	double x,y,r,area;
	set<Point> st;

	Point pp[MAXN*MAXN],res[MAXN*MAXN],pnt[MAXN],point[MAXN];
	Circle cc[MAXN];
	bool vis[MAXN*MAXN];

	while(~scanf("%d",&m))
	{	
		cnt=0;
		e=0;
		n=nn=0;
		if(m==0) { puts("0.0000"); continue; }
		for(int i=0;i<m;i++)	
		{
			scanf("%lf %lf %lf",&x,&y,&r);
			if(r>eps)
				cc[n].c.x=x,cc[n].c.y=y,cc[n++].r=r;
			else point[nn].x=x,point[nn].y=y,point[nn++].id=-1;
		}
		cc[n]=cc[0];
		if(nn>0)
		{
			for(int i=0;i<nn;i++)
			{	
				pp[cnt++]=point[i];
				for(int j=0;j<n;j++)
					getTangentPoints( point[i], cc[j], pp, j );
			}			
		}
		double maxr=0;
		for(int i=0;i<n;i++)
		{
			maxr=max(maxr,cc[i].r);
			for(int j=0;j<n;j++)
				if(i!=j)
				{
					if(dist(cc[i].c,cc[j].c)>fabs(cc[i].r-cc[j].r))
						makeCircle(cc[i],cc[j],pp,i);
				}
		}
		int cnt_cv=graham(pp,cnt,res);
		res[cnt_cv]=res[0];
		area=0;
		for(int i=0;i<cnt_cv;i++)
		{	
			if(res[i].id==-1)
			{
				if(st.find(res[i])==st.end())
				{

					st.insert(res[i]);
					pnt[e++]=res[i];
				}
			}
			else
			{
				if(st.find(cc[res[i].id].c)==st.end())
				{

					st.insert(cc[res[i].id].c);
					pnt[e++]=cc[res[i].id].c;
				}
			}
			if(res[i].id==res[i+1].id && res[i].id!=-1)	
			{
				double tmp1=DisOnCircle(res[i],res[i+1],cc[res[i].id]);
				double tmp2=DisOnCircle(res[i+1],res[i],cc[res[i].id]);
				double tmp=min(tmp1,tmp2);
				area+=0.5*tmp*cc[res[i].id].r;
			}		
			else if(res[i].id!=-1 && res[i+1].id!=-1 && res[i].id!=res[i+1].id)
			{
				area+=getarea2(cc[res[i].id].c,res[i],res[i+1],cc[res[i+1].id].c);
			}
			else if(res[i].id!=-1 && res[i+1].id==-1)
			{
				double tmp=Cross(res[i],res[i+1])+Cross(res[i+1],cc[res[i].id].c)+Cross(cc[res[i].id].c,res[i]);
				area+=tmp*0.5;	
			}
			else if(res[i].id==-1 && res[i+1].id!=-1)
			{
				double tmp=Cross(res[i],res[i+1])+Cross(res[i+1],cc[res[i+1].id].c)+Cross(cc[res[i+1].id].c,res[i]);
				area+=tmp*0.5;	
			}
			else continue;
		}
		area+=getarea(pnt,e);
		double tmp_area=PI*maxr*maxr;
		if(area-tmp_area<eps) 
			area=tmp_area;
		printf("%.4lf\n",area);	
		st.clear();
	}
	return 0;	
}



