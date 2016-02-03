#include"stdio.h"
#include"algorithm"
#include"string.h"
#include"iostream"
#include"queue"
#include"map"
#include"vector"
#include"string"
using namespace std;
#define RN 9*9*9+5
#define CN 4*9*9+5
#define N 9*9*9*4+5
char fuck[9*9+5];
struct DLX
{
    int n,m,C;
    int U[N],D[N],L[N],R[N],Row[N],Col[N];
    int H[RN],S[CN],cnt,ans[RN];
    void init(int _n,int _m)
    {
        n=_n;
        m=_m;
        for(int i=0; i<=m; i++)
        {
            U[i]=D[i]=i;
            L[i]=(i==0?m:i-1);
            R[i]=(i==m?0:i+1);
            S[i]=0;
        }
        C=m;
        for(int i=1; i<=n; i++) H[i]=-1;
    }
    void link(int x,int y)
    {
        C++;
        Row[C]=x;
        Col[C]=y;
        S[y]++;
        U[C]=U[y];
        D[C]=y;
        D[U[y]]=C;
        U[y]=C;
        if(H[x]==-1) H[x]=L[C]=R[C]=C;
        else
        {
            L[C]=L[H[x]];
            R[C]=H[x];
            R[L[H[x]]]=C;
            L[H[x]]=C;
        }
    }
    void del(int x)
    {
        R[L[x]]=R[x];
        L[R[x]]=L[x];
        for(int i=D[x]; i!=x; i=D[i])
        {
            for(int j=R[i]; j!=i; j=R[j])
            {
                U[D[j]]=U[j];
                D[U[j]]=D[j];
                S[Col[j]]--;
            }
        }
    }
    void rec(int x)
    {
        for(int i=U[x]; i!=x; i=U[i])
        {
            for(int j=L[i]; j!=i; j=L[j])
            {
                U[D[j]]=j;
                D[U[j]]=j;
                S[Col[j]]++;
            }
        }
        R[L[x]]=x;
        L[R[x]]=x;
    }
    int dance(int x)
    {
        if(R[0]==0)
        {
            cnt=x;
            for(int i=0;i<cnt;i++)
            {
                int tep=ans[i]-1;
                int a=tep/81,b=(tep%81)/9;
                fuck[a*9+b+1]=tep%9+1+'0';
            }
            puts(fuck+1);
            return 1;
        }
        int now=R[0];
        for(int i=R[0]; i!=0; i=R[i])
        {
            if(S[i]<S[now]) now=i;
        }
        del(now);
        for(int i=D[now]; i!=now; i=D[i])
        {
            ans[x]=Row[i];
            for(int j=R[i]; j!=i; j=R[j]) del(Col[j]);
            if(dance(x+1)) return 1;
            for(int j=L[i]; j!=i; j=L[j]) rec(Col[j]);
        }
        rec(now);
        return 0;
    }
} dlx;
void getplace(int i,int j,int k,int &x,int &a,int &b,int &c)
{
    x=(i-1)*81+(j-1)*9+k;
    a=81+(i-1)*9+k;
    b=81*2+(j-1)*9+k;
    c=81*3+((i-1)/3*3+(j-1)/3)*9+k;
}
int main()
{
    while(scanf("%s",fuck+1),strcmp("end",fuck+1))
    {
        dlx.init(9*9*9,4*9*9);
        for(int i=1; i<=9; i++)
        {
            for(int j=1; j<=9; j++)
            {
                int tep=(i-1)*9+j;
                int x,a,b,c;
                if(fuck[tep]=='.')
                {
                    for(int k=1; k<=9; k++)
                    {
                        getplace(i,j,k,x,a,b,c);

                        dlx.link(x,tep);
                        dlx.link(x,a);
                        dlx.link(x,b);
                        dlx.link(x,c);
                    }
                }
                else
                {
                    getplace(i,j,fuck[tep]-'0',x,a,b,c);
                    dlx.link(x,tep);
                    dlx.link(x,a);
                    dlx.link(x,b);
                    dlx.link(x,c);
                }
            }
        }
        dlx.dance(0);
    }
    return 0;
}




