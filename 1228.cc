#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<algorithm>
using namespace std;
const double eps=1e-9;
#define zero(x) (((x)>0? (x):-(x))<eps)
struct point{
    double x,y;
}a[1010];
int n,s[1010];
int top;
int cmp(point a,point b)
{
    if(a.y==b.y)
        return a.x<b.x;
    return a.y<b.y;
}
double cross(point a,point b,point c)
{
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
int dbcmp(double d)
{
    if(zero(d)) return 0;
    else return d>0?1:-1;
}
void tubao()
{
   int i,temp;
   sort(a,a+n,cmp);
   top=-1;
   s[++top]=0;
   s[++top]=1;
   for(i=2;i<n;i++)
   {
       while(top>=1&&dbcmp(cross(a[s[top-1]],a[i],a[s[top]]))>=0)
           top--;
       s[++top]=i;
   }
   temp=top;
   s[++top]=n-2;
   for(i=n-3;i>=0;i--)
   {
       while(top>=temp+1&&dbcmp(cross(a[s[top-1]],a[i],a[s[top]]))>=0)
           top--;
       s[++top]=i;
   }
}//最后一点和第一点是一样的,即重复的
bool dot_in_line(point a,point b,point c)//判断a是否在线段bc上
{
    return zero(cross(a,b,c))&&(a.x-b.x)*(a.x-c.x)<eps&&(a.y-b.y)*(a.y-c.y)<eps;
} 
bool check(int n)
{
    int i,j,count;
    if(n<=5) return false;
    if(top==1) return false;
    for(i=0;i<top;i++)
    {
        count=0;
        for(j=0;j<n;j++)
        {
            if(dot_in_line(a[j],a[s[i]],a[s[i+1]]))
            {
                count++;
            }
        }
        if(count<3) return false;
    }
    return true;
}
int main()
{
    int t,i,j,flag;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%lf%lf",&a[i].x,&a[i].y);
        tubao();
        if(check(n)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}


