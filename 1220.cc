#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

#define N 10000

using namespace std;

char cao[1000]={"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};

struct BIGN
{
    int a[N];
}ans;

int n,p,mod[N],hash[N],m,tt;
char s[10000];

inline void prt(BIGN &a)
{
    for(int i=a.a[0];i>=1;i--) printf("%d ",a.a[i]);
    puts("");
}

inline BIGN operator %(BIGN a,int md)
{
    BIGN c;
    memset(c.a,0,sizeof c.a);
    c.a[0]=a.a[0];
    int ys=0;
    for(int i=a.a[0];i>=1;i--)
    {
        ys=a.a[i]+ys*n;
        c.a[i]=ys/md;
        ys%=md;
    }
    mod[++p]=ys;
    while(c.a[0]>1&&c.a[c.a[0]]==0) c.a[0]--;
    return c;
}

void prev()
{
    for(int i=0;i<62;i++) hash[cao[i]]=i;
}

void change()
{
    memset(ans.a,0,sizeof ans.a);
    ans.a[0]=strlen(s+1);
    for(int i=1;i<=ans.a[0];i++) ans.a[i]=hash[s[ans.a[0]-i+1]];
}

inline bool check(BIGN &c)
{
    if(c.a[0]==1&&c.a[1]==0) return false;
    else return true;
}

void go()
{
    scanf("%d%d%s",&n,&m,s+1);
    printf("%d %s\n%d ",n,s+1,m);
    change();
    p=0;
    while(check(ans)) ans=ans%m;
    if(p) while(p) printf("%c",cao[mod[p--]]);
    else printf("0");
    puts("");
    puts("");
}

int main()
{
    prev();
    scanf("%d",&tt);
    while(tt--) go();
    return 0;
}


