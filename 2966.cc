#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const double EP=1e-8;
const double inf=1e100;
inline double max(double x, double y){ return x>y?x:y;}
inline double min(double x, double y){ return x<y?x:y;}
int n, cnt, vis[110];
double a[110][110], d[110];
struct Point{
    double x, y;
}p[110], tp[110], t1, t2;
struct Line{
    Point a, b;
};

bool cmpx(Point p1, Point p2){
    return p1.x<p2.x;
}
bool cmpy(Point p1, Point p2){
    return p1.y<p2.y;
}

double x_mult(Point sp, Point ep, Point op){
    return (sp.x-op.x)*(ep.y-op.y)-(sp.y-op.y)*(ep.x-op.x);
}
double dist(Point p1, Point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
Point intersection(Point u1,Point u2,Point v1,Point v2){
      Point res=u1;
      double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))/
               ((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
     res.x+=(u2.x-u1.x)*t;
     res.y+=(u2.y-u1.y)*t;
     return res;
}

bool Point_In_Segment(Point a, Point b, Point t){       
    return (t.x<=max(a.x, b.x)&&
            t.x>=min(a.x, b.x)&&
            t.y<=max(a.y, b.y)&&
            t.y>=min(a.y, b.y)&&
            fabs(x_mult(t, a, b))<EP);
}

bool Point_In_Polygon(Point pt){                        
    int i, num=0;
    for(i=0; i<n; i++){
        Point p1=p[i], p2=p[(i+1)%n];
        if(Point_In_Segment(p1, p2, pt))return true;
        if(p1.y==p2.y||pt.y<min(p1.y, p2.y)||pt.y>=max(p1.y, p2.y))
        continue;
        double t=(pt.y-p1.y)*(p2.x-p1.x)/(p2.y-p1.y)+p1.x;
        if(t>pt.x)num++;
    }
    return num&1;
}
bool Linelenth_In_Polygon(Line l1){        
    int i, j;
    double ans=0;
    Point mid;
    cnt=0;
    for(i=0; i<n; i++){
        if((x_mult(p[i], l1.a, l1.b)*x_mult(p[(i+1)%n], l1.a, l1.b)<=EP)&&
        (x_mult(l1.a, p[i], p[(i+1)%n])*x_mult(l1.b, p[i], p[(i+1)%n])<=EP)){
            if(fabs(x_mult(p[i], l1.a, l1.b))<EP&&
				fabs(x_mult(p[(i+1)%n], l1.a, l1.b))<EP)  
				continue;
            tp[cnt++]=intersection(p[i], p[(i+1)%n], l1.a, l1.b);
        }
    }
	if(fabs(l1.a.x-l1.b.x)>EP)     
	sort(tp, tp+cnt, cmpx);
	else sort(tp, tp+cnt, cmpy);
    for(i=0; i<cnt-1; i++){
        mid.x=(tp[i].x+tp[i+1].x)/2;
        mid.y=(tp[i].y+tp[i+1].y)/2;
        int flag=0;
        for(j=0; j<n; j++){
            if(Point_In_Segment(p[j], p[(j+1)%n], mid))     
            flag=1;
        }
        if(flag)continue;
        if(Point_In_Polygon(mid))
        ans+=dist(tp[i], tp[i+1]);
        if(ans>EP)return true;
    }
    return false;
}
double dijkstra(int st){
    memset(vis, 0, sizeof(vis));
    int i, j;
    for(i=0; i<=n+1; i++){
        if(a[st][i]<0)d[i]=inf;
        else d[i]=a[st][i];
    }
    d[st]=0;
    vis[st]=1;
    for(i=0; i<=n; i++){
        double tmp=inf;
        int flag;
        for(j=0; j<=n+1; j++){
            if(!vis[j]&&d[j]<tmp){
                tmp=d[j];
                flag=j;
            }
        }
        if(tmp==inf)break;
        vis[flag]=1;
        for(j=0; j<=n+1; j++){
            if(a[j][flag]>=0&&!vis[j]&&d[j]>d[flag]+a[j][flag])
            d[j]=d[flag]+a[j][flag];
        }
    }
    return d[n+1];
}
void read(){
    int i, j;
    Line l1;
    scanf("%d", &n);
    for(i=0; i<n; i++)
        scanf("%lf%lf", &p[i].x, &p[i].y);
    p[n]=t1;p[n+1]=t2;
    for(i=0; i<=n; i++)
    for(j=i+1; j<=n+1; j++){
        l1.a=p[i];l1.b=p[j];
        if(Linelenth_In_Polygon(l1))a[i][j]=a[j][i]=-1;
        else a[i][j]=a[j][i]=dist(p[i], p[j]);
    }
    printf("%.4f\n", dijkstra(n));
}

int main(){
    while(scanf("%lf%lf%lf%lf", &t1.x, &t1.y, &t2.x, &t2.y)!=EOF){
        read();
    }
    return 0;
}


