#include <stdio.h>
#include <string.h>
#include <math.h>
#define INF 1000000000
#define maxn 5001    
int min(int a,int b)
{
    return a<b?a:b;
}
int max(int a,int b)
{
    return a>b?a:b;
}
int c[10],f[maxn+10];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int i,j,k;
        while(n--)
        {
            for(i=0;i<6;i++)
                scanf("%d",&c[i]);
            for(i=0;i<=maxn;i++)
                f[i]=INF;
            f[0]=0;
            for(i=0;i<6;i++)
                for(j=c[i];j<=maxn;j++)
                    f[j]=min(f[j],f[j-c[i]]+1);
            for(i=0;i<6;i++)
            for(j=maxn-c[i];j>=0;j--)
                f[j]=min(f[j],f[j+c[i]]+1);
            int m=-1;
            double s=0;
            for(i=0;i<=100;i++)
            {
                s+=f[i];
                m=max(m,f[i]);
            }
            printf("%.2f %d\n",s/100,m);//注意用%f,我用%lf就错了。。
        }
    }
    return 0;
}


