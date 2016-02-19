#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<queue>

using namespace std;

#define INF 0x3f3f3f3f
const double eps=1e-8;

struct edges
{
    int v,next;
}edge[110*110*110];
int head[110],en,n,cnts[110],dis[110];
double w;
bool in[110];
double g[110][110];
double sd[110],ed[110];

void add(int u,int v)
{
    edge[en].v=v;
    edge[en].next=head[u];
    head[u]=en++;

    edge[en].v=u;
    edge[en].next=head[v];
    head[v]=en++;
}

inline double sqr(double x)
{
    return x*x;
}

int sig(double x)
{
    if(fabs(x)<eps) return 0;
    if(x>0) return 1;
    return -1;
}

struct point
{
    double x,y;
    point(){};
    point(double a,double b):x(a),y(b){}
    void input()
    {
        scanf("%lf%lf",&x,&y);
    }
    friend point operator + (const point &a,const point &b)
    {
        return point(a.x+b.x,a.y+b.y);
    }
    friend point operator - (const point &a,const point &b)
    {
        return point(a.x-b.x,a.y-b.y);
    }
    friend bool operator == (const point &a,const point &b)
    {
        return sig(a.x-b.x)==0 && sig(a.y-b.y)==0;
    }
    friend point operator * (const point &a,const double &b)
    {
        return point(a.x*b,a.y*b);
    }
    friend point operator * (const double &a,const point &b)
    {
        return point(a*b.x,a*b.y);
    }
    friend point operator / (const point &a,const double &b)
    {
        return point(a.x/b,a.y/b);
    }
    double norm()
    {
        return sqrt(sqr(x)+sqr(y));
    }
}p[110][12];

double det(const point &a,const point &b)
{
    return a.x*b.y-a.y*b.x;
}

double dot(const point &a,const point &b)
{
    return a.x*b.x+a.y*b.y;
}

double dist(const point &a,const point &b)
{
    return (a-b).norm();
}

struct line
{
    point a,b;
    line() {}
    line(point x,point y):a(x),b(y){}
};

line point_make_line(const point a,const point b)
{
    return line(a,b);
}

double dis_point_segment(const point p,const point s,const point t)
{
    if(sig(dot(p-s,t-s))<0) return (p-s).norm();
    if(sig(dot(p-t,s-t))<0) return (p-t).norm();
    return fabs(det(s-p,t-p)/dist(s,t));
}

bool PointOnSegment(point p,point s,point t)
{
    return sig(det(p-s,t-s))==0 && sig(dot(p-s,p-t))<=0;
}

double det1(double x1, double y1, double x2, double y2)
{
    return x1 * y2 - x2 * y1;
}

double xmult1(point p0,point p1,point p2)
{
    return det1(p1.x-p0.x,p1.y-p0.y,p2.x-p0.x,p2.y-p0.y);
}

double dotdet1(double x1,double y1,double x2,double y2)
{
    return x1*x2+y1*y2;
}

double dot1(point p0, point p1, point p2)
{
    return dotdet1(p1.x-p0.x,p1.y-p0.y,p2.x-p0.x,p2.y-p0.y);
}

int between1(point p0,point p1, point p2)
{
    return sig(dot1(p0,p1,p2));
}

int intersect1(point a, point b, point c, point d)
{
    double s1, s2, s3, s4;
    int d1 = sig(s1 = xmult1(a, b, c));
    int d2 = sig(s2 = xmult1(a, b, d));
    int d3 = sig(s3 = xmult1(c, d, a));
    int d4 = sig(s4 = xmult1(c, d, b));
    if ((d1^d2) == -2 && (d3^d4) == -2)
   	{
      return 1;
    }
    if (d1 == 0 && between1(c, a, b) <= 0) return 2;
    if (d2 == 0 && between1(d, a, b) <= 0) return 2;
    if (d3 == 0 && between1(a, c, d) <= 0) return 2;
    if (d4 == 0 && between1(b, c, d) <= 0) return 2;
    return 0;
}

double getdis(int a,int b)
{
    double dis=0x3f3f3f3f;
    for(int i=0;i<cnts[a];i++)
        for(int j=0;j<cnts[b];j++)
            if(intersect1(p[a][i],p[a][(i+1)%cnts[a]],p[b][j],p[b][(j+1)%cnts[b]])) return 0;
    for(int i=0;i<cnts[a];i++)
        for(int j=0;j<cnts[b];j++)
            dis=min(dis,dist(p[a][i],p[b][j]));
    for(int i=0;i<cnts[a];i++)
        for(int j=0;j<cnts[b];j++)
            dis=min(dis,dis_point_segment(p[a][i],p[b][j],p[b][(j+1)%cnts[b]]));
    for(int i=0;i<cnts[b];i++)
        for(int j=0;j<cnts[a];j++)
            dis=min(dis,dis_point_segment(p[b][i],p[a][j],p[a][(j+1)%cnts[a]]));
    return dis;
}

void initDis()
{
    point s,e;
    double st=w/2;
    double end=-w/2;
    sd[0]=w/2;sd[n+1]=w/2;
    s.x=0,s.y=0;
    for(int i=1;i<=n;i++)
    {
        double diss1=0x3f3f3f3f;
        for(int j=0;j<cnts[i];j++)

        {
            diss1=min(diss1,dist(s,p[i][j]));
            diss1=min(diss1,dis_point_segment(s,p[i][j],p[i][(j+1)%cnts[i]]));
        }
        sd[i]=diss1;
    }
    for(int i=1;i<=n;i++)
    {
        double disS=0x3f3f3f3f,disE=0x3f3f3f3f;
        for(int j=0;j<cnts[i];j++)
        {
            disS=min(disS,st-p[i][j].y);
            disE=min(disE,p[i][j].y-end);
        }
        g[0][i]=g[i][0]=disS;
        g[i][n+1]=g[n+1][i]=disE;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            double len=getdis(i,j);
            g[i][j]=g[j][i]=len;
        }
    }
    g[0][n+1]=w;
    g[n+1][0]=w;
}

bool build(double r)
{
    memset(head,-1,sizeof(head));en=0;
    for(int i=0;i<=n+1;i++)
        if(sig(sd[i]-r)<=0) return false;
    for(int i=0;i<=n+1;i++)
        for(int j=i+1;j<=n+1;j++)
        {
            if(sig(g[i][j]-2*r)<0)
                add(i,j);
        }
    return true;
}

void spfa(int s)
{
	queue<int> q;
	for(int i=0;i<=n+1;i++)
	{
		dis[i]=INF;
		in[i]=false;
	}
	dis[s]=0;
	in[s]=true;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		in[u]=false;
		q.pop();
		for(int i=head[u];i!=-1;i=edge[i].next)
		{
			int v=edge[i].v;
			if(dis[u]+1<dis[v])
			{
				dis[v]=dis[u]+1;
				if(!in[v])
				{
					q.push(v);
					in[v]=true;
				}

			}
		}
	}
}

int main()
{
    while(cin>>w>>n)
    {
        if(w==0&&n==0) break;
        for(int i=1;i<=n;i++)
        {
            cin>>cnts[i];
            for(int j=0;j<cnts[i];j++) cin>>p[i][j].x>>p[i][j].y;
        }
        initDis();
        double l=0,r=w,m;
        while(l+eps<r)
        {
            m=(l+r)/2;
            bool fg=build(m);
            if(fg)spfa(0);
            if(fg&&dis[n+1]==INF)
                l=m;
            else
                r=m;
        }
        if(l!=0)
            cout<<setprecision(2)<<setiosflags(ios::fixed)<<l<<endl;

        else
            printf("impossible\n");
    }
    return 0;
}



