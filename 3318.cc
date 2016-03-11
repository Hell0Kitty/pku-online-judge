#include <set>
#include <map>
#include <queue>
#include <math.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

#define eps 1e-8
#define pi acos(-1.0)
#define inf 107374182
#define inf64 1152921504606846976
#define lc l,m,tr<<1
#define rc m + 1,r,tr<<1|1
#define iabs(x)  ((x) > 0 ? (x) : -(x))
#define clear1(A, X, SIZE) memset(A, X, sizeof(A[0]) * (SIZE))
#define clearall(A, X) memset(A, X, sizeof(A))
#define memcopy1(A , X, SIZE) memcpy(A , X ,sizeof(X[0])*(SIZE))
#define memcopyall(A, X) memcpy(A , X ,sizeof(X))
#define max( x, y )  ( ((x) > (y)) ? (x) : (y) )
#define min( x, y )  ( ((x) < (y)) ? (x) : (y) )

using namespace std;

int a[505][505],b[505][505],c[505][505];

int read()
{
    int d=0;
    char c,t=0;
    while((c=getchar())==' '||c=='\n');
    if(c=='-')
        t=1;
    else
        d=c-'0';
    while((c=getchar())>='0'&&c<='9')
        d=d*10+c-'0';
    if(t)
        return -d;
    else
        return d;
}

int main()
{
    int n,t;
    while(scanf("%d",&n)!=EOF)
    {
        bool flat=true;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                a[i][j]=read();
                //printf("%d ",a[i][j]);
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                b[i][j]=read();
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                c[i][j]=read();
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                t=0;
                for(int k=0; k<n; k++)
                {
                    t+=a[i][k]*b[k][j];
                }
                if(t!=c[i][j])
                {
                    flat=false;
                    break;
                }
            }
        }
        if(flat)puts("YES");
        else puts("NO");
    }
    return 0;
}
