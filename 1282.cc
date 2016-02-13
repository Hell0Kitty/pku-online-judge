#include<stdio.h>
#include<iostream>
using namespace std;
#define maxn 210
int a[maxn][maxn],b[maxn][maxn],c[maxn][maxn];//c表示Thead的逆即Tdeah
int d1[maxn],d2[maxn];
int n,p;
bool find(int w1[],int w2,int k,int &y,int &x)
{
    int t=k;y=-1; 

if(t==w2)y=0;
    t=w1[k];x=1;
    while(t!=k)
    {
        if(t==w2)y=x;
        t=w1[t];
        x++;
    }
    if(y==-1)return false;
    return true;
}
int extend_gcd(int a,int b,int &x,int &y)
{
    if(b==0){x=1;y=0;return a;}
    int t=extend_gcd(b,a%b,y,x);
    y-=a/b*x;
    return t;
}
int solve(int r[],int a[],int n)//扩展欧几里德两两合并
{
    int rr=r[0],aa=a[0],x,y;
    for(int i=1;i<n;i++)
    {
        int tmp=r[i]-rr;
        int gcd=extend_gcd(aa,a[i],x,y);
        if(tmp%gcd!=0)return -1;
        int temp=a[i]/gcd;
        x=((tmp/gcd*x)%temp+temp)%temp;
        rr=rr+aa*x;
        aa=aa*a[i]/gcd;
    }
    return rr;
}
int main()
{
    int i,j;
    scanf("%d%d",&n,&p);
    for(i=0;i<n;i++)
    {
        for(j=0;j<p;j++)
        {
            scanf("%d",&a[j][i]);
            a[j][i]--;
        }
    }
    for(i=0;i<n;i++)
    {b[0][i]=a[0][i];}
    for(i=1;i<p;i++)//求出TStep 即T1*t2*···*Tp;
    {
        for(j=0;j<n;j++)
            b[i][j]=a[i][b[i-1][j]];
    }
    for(i=0;i<p;i++)
    {
        for(j=0;j<n;j++)
            c[i][b[i][j]]=j;
    }
    int ans=1000000000;
    for(i=0;i<p;i++)//枚举y mod p=k;
    {
        bool flag=true;
        for(j=0;j<n;j++)
        {
            flag=find(b[p-1],c[i][j],j,d1[j],d2[j]);
            if(!flag)break;
        }
        if(!flag)continue;
        int tt=solve(d1,d2,n);
        if(tt!=-1&&tt*p+i+1<ans)
            ans=tt*p+i+1;
    }
    if(ans!=1000000000)printf("%d\n",ans);
    else printf("No one knows.\n");

}


