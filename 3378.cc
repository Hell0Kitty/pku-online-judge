#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define SIZE 10

using namespace std;

struct BIGN 
{
    int a[SIZE];
};

inline BIGN operator +(BIGN a,BIGN b)
{
    BIGN c;
    memset(&c,0,sizeof c);
    c.a[0]=max(b.a[0],a.a[0]);
    int jin=0;
    for(int i=1;i<=c.a[0];i++)
    {
        jin+=a.a[i]+b.a[i];
        c.a[i]=jin%10000;
        jin/=10000;
    }
    if(jin) c.a[++c.a[0]]=jin;
    return c;
}

inline void give(char s[],BIGN &a)
{
    memset(&a,0,sizeof a);
    int len=strlen(s);
    int p[4]={1,10,100,1000};
    for(int i=len-1,j=0;i>=0;i--,j=(j+1)&3)
    {
        if(!j) a.a[0]++;
        a.a[a.a[0]]=a.a[a.a[0]]+(s[i]-'0')*p[j];
    }
}

inline void prt(BIGN a)
{
    printf("%d",a.a[a.a[0]]);
    for(int i=a.a[0]-1;i>=1;i--) printf("%04d",a.a[i]);
    puts("");
}

BIGN c[6][50010],ans;
int n,bh;

struct BZ
{
    int x,h,id;
}bz[50010];

void read()
{
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&bz[i].x);
        bz[i].id=i;
    }    
}

inline bool cmp_x(const BZ &a,const BZ &b)
{
    return a.x<b.x;
}

inline bool cmp_id(const BZ &a,const BZ &b)
{
    return a.id<b.id;
}

inline int lowbit(int x)
{
    return x&-x;
}

void lsh()
{
    sort(bz+1,bz+1+n,cmp_x);
    bz[1].h=2; bh=2;
    for(int i=2;i<=n;i++)
    {
        if(bz[i].x!=bz[i-1].x) bz[i].h=++bh;
        else bz[i].h=bh;
    }
    sort(bz+1,bz+1+n,cmp_id);
}

inline BIGN getsum(int p,int num)
{
    BIGN rt;
    give("0",rt);
    while(num)
    {
        rt=rt+c[p][num];
        num-=lowbit(num);
    }
    return rt;
} 

inline void updata(int p,int q,BIGN sy)
{
    while(q<=bh)
    {
        c[p][q]=c[p][q]+sy;
        q+=lowbit(q);
    }
}

void go()
{
    BIGN one,tmp; give("1",one); give("0",ans);
    for(int i=0;i<=bh;i++)
        for(int j=1;j<=5;j++)
            give("0",c[j][i]);
    for(int i=1;i<=n;i++) 
    {
        updata(1,bz[i].h,one);
        for(int j=2;j<=5;j++)
        {
            tmp=getsum(j-1,bz[i].h-1);
            updata(j,bz[i].h,tmp);
        }
    }
    ans=getsum(5,bh);
    prt(ans);
}

int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        read();
        lsh();
        go();
    }
    return 0;
}


