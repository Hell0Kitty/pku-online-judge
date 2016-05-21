#include<stdio.h>
int main()
{
    int m,n=1,i,j,k,a[10001]={0};
    for(i=0; i<10; i++)
    {
        scanf("%d",&m);
        for(j=2; m!=1; j++)
        {
            while(m%j==0)
            {
                a[j]++;
                m=m/j;
            }
        }
    }
    for(i=0; i<10001; i++)
    {
        if(a[i]!=0)
        {
            n*=(a[i]+1);
        }
    }
    printf("%d\n",n%10);
    return 0;
}



