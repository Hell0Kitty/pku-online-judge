#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn=1005;
const double eps=1e-8,pi=acos(-1);
double f2i[maxn];
struct RANGE{double l,r;int L,R;}range[maxn];
int cmp(double a,double b)
{
    return fabs(a-b)<eps;
}
int cmp2(double a,double b)
{
    return a<b&&fabs(a-b)>eps;
}
int cmp3(RANGE a,RANGE b)
{
    if(a.R!=b.R){
        if(a.R>=a.L&&b.R>=b.L||a.R<a.L&&b.R<b.L)  return a.R<b.R;
        return a.R>b.R;
    }
    if(a.R>=a.L&&b.R>=b.L||a.R<a.L&&b.R<b.L)  return a.L<b.L;
    return a.L>b.L;
}
int cmp4(RANGE a,RANGE b)
{
    if(a.L!=b.L)  return a.L<b.L;
    if(a.R>=a.L&&b.R>=b.L||a.R<a.L&&b.R<b.L)  return a.R<b.R;
    return a.R>b.R;
}
int seg[maxn];
#define lowbit(n)  (n&-n)
void add(int pos)
{
    while(pos<maxn)  seg[pos]++,pos+=lowbit(pos);
    return;
}
int sum(int pos)
{
    int ans=0;
    while(pos)  ans+=seg[pos],pos-=lowbit(pos);
    return ans;
}
int main()
{
    //freopen("POJ 3004.txt","r",stdin);
    int t,n,d,i,j,cnt1,cnt2,_size,flag,ans;
    scanf("%d",&t);
    while(t--){
        cnt1=cnt2=0;
        scanf("%d %d",&n,&d);
        for(i=0;i<n;i++){
            double x,y;
            scanf("%lf %lf",&x,&y);
            double deg=atan2(y,x);
            double rate=d/sqrt(x*x+y*y);
            if(rate>1||fabs(rate-1)<eps)  continue;
            double deg1=fmod(deg-asin(rate)+pi,2*pi);
            double deg2=fmod(deg+asin(rate)+pi,2*pi);
            range[cnt1++]=(RANGE){deg1,deg2};
            f2i[cnt2++]=deg1;
            f2i[cnt2++]=deg2;
        }
        sort(f2i,f2i+cnt2);
        _size=unique(f2i,f2i+cnt2,cmp)-f2i;
        for(i=0;i<cnt1;i++){
            range[i].L=lower_bound(f2i,f2i+_size,range[i].l,cmp2)-f2i;
            range[i].R=lower_bound(f2i,f2i+_size,range[i].r,cmp2)-f2i;
        }
        sort(range,range+cnt1,cmp3);
             for(i=0,ans=0x7fffffff;i<cnt1;i++){
            memset(seg,0,sizeof(seg));
            for(j=i,flag=1;j!=i||flag;j=(j+1)%cnt1){
                flag=0;
                int L=range[j].L;
                int R=range[j].R;
                int addd=sum(R+1)-sum(L);
                if(R<L)  addd+=sum(_size);
                if(addd)  continue;
                add(R+1);
            }
            ans=min(ans,sum(_size));
        }
        printf("%d\n",ans==0x7fffffff?0:ans);
    }
    return 0;
}



