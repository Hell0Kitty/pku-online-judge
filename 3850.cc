#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <cstdlib>  
const int MAXN = 2009;  
const double eps = 1e-8;  
struct point{  
    double x,y;  
    int id;  
}p[MAXN],h[MAXN];  

inline double distance(const point &p1,const point &p2){  
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));  
}//   求两点之间的距离  
inline double multiply(const point &sp,const point &ep,const point &op){  
      return ((sp.x-op.x)*(ep.y-op.y)-(ep.x-op.x)*(sp.y-op.y));  
}//判断sp,ep，op是否满足左转  
int cmp(const void *a,const void *b){//按极角排序  
    point *p1 = (point *)a;  
    point *p2 = (point *)b;  
    double t = multiply(*p2,*p1,p[0]);  
    if(t>eps) return 1;  
    else if(fabs(t)<=eps)  
    {  
    if(distance(p[0],*p1)<distance(p[0],*p2)) return 1;  
    else return -1;  
    }  
    else return -1;  
}  
int cmp1(const void *a,const void *b){//按极角排序  
    point *p1 = (point *)a;  
    point *p2 = (point *)b;  
    double t = multiply(*p2,*p1,p[0]);  
    if(t>eps) return 1;  
    else if(fabs(t)<=eps)  
    {  
    if(distance(p[0],*p1)>distance(p[0],*p2)) return 1;  
    else return -1;  
    }  
    else return -1;  
}  
void anglesort(point p[],int n){//找到最左下方的点  
    int i,k=0;  
    point temp;  
    for(i=1;i<n;i++)  
        if(p[i].x<p[k].x ||( (p[i].x==p[k].x) && (p[i].y<p[k].y)))  
            k=i;  
    temp=p[0],p[0]=p[k],p[k]=temp;  
    qsort(p+1,n-1,sizeof(point),cmp);  

    for( i=2;i<n;i++)  //找出其实边上的点，重新排序
    if(fabs(multiply(p[0],p[1],p[i]))>eps)  
    {break;}  
    qsort(p+1,i-1,sizeof(point),cmp1);  
}  
void Graham_scan(point p[],point ch[],int n,int &len){//建立凸包  
    int i,top=2;  
    anglesort(p,n);  
}  
int main(){  
    int i,j,n,len;  
    double d,ans;  
    int ca;  
    scanf("%d",&ca);  
    while(ca--)  
    {  
        scanf("%d",&n);  
        for(i=0;i<n;i++)  
        {  
        scanf("%lf %lf",&p[i].x,&p[i].y);  
        p[i].id=i;  
        }  
        Graham_scan(p,h,n,len);  
        int flag=1;  
        for(int i=0;i<n;i++)  
        {  
            if(flag)  
            {printf("%d",p[i].id);  
            flag=0;continue;}  
            printf(" %d",p[i].id);  
        }  
        puts("");  
    }  
    return 0;  
}




