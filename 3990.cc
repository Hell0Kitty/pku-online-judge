#include<iostream>
#include<cstdio>
 #include<cmath>
 #include<algorithm>
 using namespace std;
 const double EP=1e-8;
 const double INF=1e8;
 struct Point{double x, y;};
 Point p[4], pt[4], c;
 double x_mult(Point sp, Point ep, Point op){
     return (sp.x-op.x)*(ep.y-op.y)-(sp.y-op.y)*(ep.x-op.x);
 }
 double dist(Point p1, Point p2){
     return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
 }
 bool cmp(const Point p1, const Point p2){
     return p1.y<p2.y ||(p1.y==p2.y&&p1.x<p2.x);
 }

 int graham(Point pp[], Point res[]){
     int i, len1, k=0, top=1;
     sort(pp,pp+4,cmp);
     res[0]=pp[0];
     res[1]=pp[1];
     res[2]=pp[2];
     for(i=2; i<4; i++){
         while(top&&x_mult(pp[i],res[top],res[top-1])> - EP)
             top--;
         res[++top]=pp[i];
     }
     len1=top; res[++top]=pp[2];
     for(i=1; i>=0; i--){
         while(top!=len1&&x_mult(pp[i],res[top],res[top-1])> - EP)
             top--;
             res[++top]=pp[i];
     }
     return top;      
 }
 Point intersect(Point u1,Point u2,Point v1,Point v2){
       Point res=u1;
       double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))/
                ((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
      res.x+=(u2.x-u1.x)*t;
      res.y+=(u2.y-u1.y)*t;
      return res;
 }

 int main(){
     while(1){
         double ans=0, s;
         int i, flag, j;
         for(i=0; i<4; i++)
         scanf("%lf%lf", &p[i].x, &p[i].y);
         if(p[0].x<0)break;
         int sum=graham(p, pt);
         if(sum==4){
             c=intersect(pt[0], pt[2], pt[1], pt[3]);
             for(i=0; i<4; i++)
             ans+=dist(p[i], c);
         }
         else {
             ans=INF;
             for(i=0; i<4; i++){
                 s=0;
                 for(j=0; j<4; j++)
                 s+=dist(p[i], p[j]);
                 if(s<ans)
                     ans=s;
             }
         }
         printf("%.4f\n", ans);
     }
     return 0;
 }


