#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>

#define esp 1e-6

using namespace std;

typedef struct pnode
{
	double x,y;
	int    id;
	pnode( double a, double b ){x = a;y = b;}
	pnode( double a, double b, int i ){x = a;y = b;id = i;}
	pnode(){}
}point;

typedef struct lnode
{
	double x,y,dx,dy;
	lnode( point a, point b ){x = a.x;y = a.y;dx = b.x-a.x;dy = b.y-a.y;}
	lnode(){}
}line;

typedef struct snode
{
	point p1,p2;
	int   id;
	snode( point a, point b, int i ){p1 = a;p2 = b;id = i;}
	snode(){}
}segment;

typedef struct cnode
{
	point   p[8];
	segment s[8];
}car;

car madecar( double x, double y, double u, double v, double w )
{
	car Car;
	Car.p[0] = point( x, y, 1 );
	Car.p[2] = point( u, v, 2 );
	double d = sqrt((x-u)*(x-u)+(y-v)*(y-v));
	point  r = point( (v-y)*w/d, (x-u)*w/d );
	Car.p[4] = point( u+r.x, v+r.y, 3 );
	Car.p[6] = point( x+r.x, y+r.y, 4 );
	for ( int i = 0 ; i < 8 ; i += 2 ) {
		point m;
		m.x  = (Car.p[i].x+Car.p[(i+2)%8].x)/2;
		m.y  = (Car.p[i].y+Car.p[(i+2)%8].y)/2;
		m.id = min(Car.p[i].id,Car.p[(i+2)%8].id);
		Car.p[i+1] = m;
	}
	for ( int i = 0 ; i < 8 ; ++ i ) {
		Car.s[i] = segment( Car.p[i], Car.p[(i+1)%8], 0 );
		Car.s[i].id = (i+1)%8/2+1;
	}
	return Car;
}

double dist( point a, point b )
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool lcrossl( line a, line b )  
{  
    double t1 = b.dx*(a.y-b.y)-b.dy*(a.x-b.x);  
    double t2 = b.dx*(a.y+a.dy-b.y)-b.dy*(a.x+a.dx-b.x);  
    return (t1-esp)*(t2-esp) <= 0;  
}

point crosspoint( line l, line m )  
{  
	point a = point( m.x, m.y );
	point b = point( m.x+m.dx, m.y+m.dy );
    if ( m.dx*l.dy == m.dy*l.dx ) {  
        if ( dist( point( l.x, l.y ), a ) < dist( point( l.x, l.y ), b ) )  
            return a;  
        else return b;  
    }else {  
        double a1 = -l.dy,b1 = l.dx,c1 = l.dx*l.y-l.dy*l.x;  
        double a2 = -m.dy,b2 = m.dx,c2 = m.dx*m.y-m.dy*m.x;  
        double x = (c1*b2-c2*b1)/(a1*b2-a2*b1);  
        double y = (c1*a2-c2*a1)/(b1*a2-b2*a1);  
        return point( x, y );  
    }   
}  

typedef struct anode
{
	int    id1,id2;
	double dis;
	anode( int a, int b, double d ){id1 = a;id2 = b;dis = d;}
}answer;

answer crash( car a, car b, point v )
{
	double dis = 1e20;
	int id1 = 1,id2 = 1;
	for ( int i = 0 ; i < 8 ; ++ i )
	for ( int j = 0 ; j < 8 ; ++ j ) {
		point c = point( a.p[i].x+v.x, a.p[i].y+v.y );
		line  l = line( b.s[j].p1, b.s[j].p2 );
		if ( lcrossl( l, line( a.p[i], c ) ) ) {
			point  e = crosspoint( line( a.p[i], c ), l );
			double d = dist( a.p[i], e );
			if ( fabs(dis-d) < esp ) {
				if ( id1 > a.p[i].id ) id1 = a.p[i].id;
				if ( id2 > b.s[j].id ) id2 = b.s[j].id;
			}
			if ( dis-esp > d ) {
				dis = d;
				id1 = a.p[i].id;
				id2 = b.s[j].id;
			}
		}
	}
	return answer( id1, id2, dis );
}

int main()
{
	double x1,y1,u1,v1,w1,s1,x2,y2,u2,v2,w2,s2;
	while ( ~scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&u1,&v1,&w1,&s1) ) {
		scanf("%lf%lf%lf%lf%lf%lf",&x2,&y2,&u2,&v2,&w2,&s2);

		car A = madecar( x1, y1, u1, v1, w1 );
		car B = madecar( x2, y2, u2, v2, w2 );

		double d1 = sqrt((x1-u1)*(x1-u1)+(y1-v1)*(y1-v1));
		point  V1 = point( (u1-x1)*s1/d1, (v1-y1)*s1/d1 );
		double d2 = sqrt((x2-u2)*(x2-u2)+(y2-v2)*(y2-v2));
		point  V2 = point( (u2-x2)*s2/d2, (v2-y2)*s2/d2 );

		answer an1 = crash( A, B, point( V1.x-V2.x, V1.y-V2.y ) );
		answer an2 = crash( B, A, point( V2.x-V1.x, V2.y-V1.y ) );

		if ( fabs(an1.dis-an2.dis) < esp )
			printf("%d %d\n",min(an1.id1,an2.id2),min(an1.id2,an2.id1));
		else if ( an1.dis+esp < an2.dis )
			printf("%d %d\n",an1.id1,an1.id2);
		else printf("%d %d\n",an2.id2,an2.id1);
	}
	return 0;
}




