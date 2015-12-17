#include<stdio.h>
int a[15];
int main()
{
    int k;
    while(scanf("%d",&k)&&k!=0)
    {
        int i,j,m = k,s;
        if(a[k])
        {
            printf("%d\n",a[k]);
            continue;
        }
        for(;;m++)
        {
            for(i=0;i<k;i++)
            {
                s = (m-1)%(2*k - i);
                for(j=2*k-i;j<2*k;j++)
                {
                    s = (s+m)%(j+1);
                }
                if(s<k) break;
            }
            if(i==k)
            {
                break;
            }
        }
        printf("%d\n",m);
        a[k] = m;
    }
    return 0;
}
