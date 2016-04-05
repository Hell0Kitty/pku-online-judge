#include<stdio.h>
int f[1005];
int main()
{
    int n,m,i,j;
    f[0]=1;
    f[1]=1;
    for(j=2; j<=1000; j++)
    {
        f[j]=0;
        for(i=0; i<=j/2; i++) f[j]+=f[i];
    }
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%d",&m);
        printf("%d %d\n",i,f[m]);
    }
    return 0;
}




