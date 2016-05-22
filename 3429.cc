#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define SZ(v) ((int)(v).size())

typedef long long lint;
const int maxn = 300;

lint gcd(lint a,lint b){
 if(!b) return a;
 return gcd(b,a%b);
}

struct frac{
 lint a,b;
 frac(){}
 frac(lint _a,lint _b):a(_a),b(_b){};
 frac operator + (const frac &A) const{
 lint ra = A.b*a + b*A.a;
 lint rb = b*A.b;
 lint g = gcd(ra,rb);
 return frac(ra/g,rb/g);
 }
 frac operator - (const frac &A) const{
 lint ra = A.b*a - b*A.a;
 lint rb = b*A.b;
 lint g = gcd(ra,rb);
 return frac(ra/g,rb/g);
 } 
 frac operator * (const frac &A) const{
 lint ra = a*A.a;
 lint rb = b*A.b;
 lint g = gcd(ra,rb);
 return frac(ra/g,rb/g);
 }
 frac operator / (const frac &A) const{
 lint ra = a*A.b;
 lint rb = b*A.a;
 lint g = gcd(ra,rb);
 return frac(ra/g,rb/g);
 }
};

struct point {
 frac x, y;
 point(){}
 point(frac _x,frac _y):x(_x),y(_y){}
};

point operator+(const point& p1, const point& p2) {
 return point(p1.x + p2.x, p1.y + p2.y);
}
point operator-(const point& p1, const point& p2) {
 return point(p1.x - p2.x, p1.y - p2.y);
}
frac operator*(const point& p1, const point& p2) {
 return p1.x * p2.y - p1.y * p2.x;
}
point operator/(const point& p, frac r) {
 return point(p.x / r, p.y / r);
}

void get_intersection(const point& p1, const point& p2, const point& p3, const point& p4, point& c) {
 frac d1 = (p2 - p1) * (p3 - p1), d2 = (p2 - p1) * (p4 - p1);
 frac d3 = (p4 - p3) * (p1 - p3), d4 = (p4 - p3) * (p2 - p3);
 c = point((p3.x * d2 - p4.x * d1) / (d2 - d1), (p3.y * d2 - p4.y * d1) / (d2 - d1));
}

int n,m;
point p[maxn+5];

int main() {
 while(scanf("%d",&n)==1){
 for(int i=1;i<=n;i++){
 int a,b;
 scanf("%d%d",&a,&b);
 p[i] = point(frac(a,1),frac(b,1));
 }
 int ls,lt,rs,rt,ans=0;
 scanf("%d",&m);
 for(int i=1;i<=m;i++){
 scanf("%d%d%d%d",&ls,&lt,&rs,&rt);
 get_intersection(p[ls],p[lt],p[rs],p[rt],p[n+i]);
 if(!p[n+i].x.a && !p[n+i].y.a){
 if(!ans) ans=i;
 }
 }
 printf("%d\n",ans);
 } 
 return 0;
}


