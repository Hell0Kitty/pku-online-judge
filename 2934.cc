# include <math.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <algorithm>
# include <iostream>
# include <string>
# include <queue>
# include <stack>
# include <map>
# include <set>
# include <vector>
# include <cstring>
# include <list>
# include <ctime>
# include <sstream>

# define For(i,a)   for((i)=0;i<(a);(i)++)
# define MAX(x,y)   ((x)>(y)? (x):(y))
# define MIN(x,y)   ((x)<(y)? (x):(y))
# define sz(a)      (sizeof(a))
# define MEM(a)     (memset((a),0,sizeof(a)))
# define MEME(a)    (memset((a),-1,sizeof(a)))
# define MEMX(a)    (memset((a),0x7f,sizeof(a)))
# define pb(a)      push_back(a)

using namespace std;

typedef long long           ll      ;
typedef unsigned long long  ull     ;
typedef unsigned int        uint    ;
typedef unsigned char       uchar   ;

template<class T> inline void checkmin(T &a,T b){if(a>b) a=b;}
template<class T> inline void checkmax(T &a,T b){if(a<b) a=b;}

const int oo=1<<30          ;
const double eps=1e-7       ;
const int N=1               ;
const int M=100007           ;
const ll P=10000000097ll    ;

struct edge
{
    ull h;
    int len,id;
    edge *next;
};

edge e[10240],*p[M];
char ans[10240][32];
int en;
int n;
int m1 = 31, m2 = 37;

ull def(char *s,int sn,int m)
{
    int i;
    ull ans = 0;
    For(i,sn)
        ans = ans*m + s[i]-'a';
    return ans;
}

void add(char *s,int sn,int id)
{
    ull p1,h;
    p1 = def(s,sn,m1)%M;
    h  = def(s,sn,m2);
    e[en].h = h;
    e[en].len = sn;
    e[en].id = id;
    e[en].next = p[p1];
    p[p1] = e + (en++);
}

void read()
{
    int i,j,k;
    int sn;
    en = 0;
    MEM(p);
    For(i,n)
    {
        scanf("%s",ans[i]);
        sn = strlen(ans[i]);
        add(ans[i],sn,i);
    }
}

int has(char *s,int sn)
{
    ull p1,h;
    p1 = def(s,sn,m1)%M;
    h  = def(s,sn,m2);
    edge *j;
    for(j=p[p1]; j; j=j->next)
        if( j->h==h && j->len==sn )
            return j->id;
    return oo;
}

void doit()
{
    char s[32];
    char st[32];
    int i,j,k;
    int sn,stn;
    int to;
    scanf("%s",s);
    sn = strlen(s);
    printf("%s ",s);
    if( oo != has(s,sn) )
    {
        puts("is correct");
        return ;
    }
    to = oo;

    /// missing
    strcpy(st,s);
    for(i=sn;i>=0;i--)
    {
        st[i+1] = s[i];
        For(j,26)
        {
            st[i] = j+'a';
            k = has(st,sn+1);
            checkmin(to, k);
        }
    }

    /// more
    strcpy(st,s);
    for(i=sn-1;i>=0;i--)
    {
        st[i] = s[i+1];
        k = has(st,sn-1);
        checkmin(to, k);
    }

    /// wrong
    strcpy(st,s);
    For(i,sn)
    {
        For(j,26)
        {
            st[i] = j+'a';
            k = has(st,sn);
            checkmin(to, k);
        }
        st[i] = s[i];
    }

    /// swap
    strcpy(st,s);
    For(i,sn-1)
    {
        swap(st[i], st[i+1]);
        k = has(st,sn);
        checkmin(to, k);
        swap(st[i], st[i+1]);
    }

    if( oo == to )
        puts("is unknown");
    else
        printf("is a misspelling of %s\n",ans[to]);

}

int main()
{
    int T,_=0;
    int q;
    while( 1==scanf("%d",&n) )
    {
        read();
        scanf("%d",&q);
        while( q-- )
            doit();
    }
    return 0;
}


