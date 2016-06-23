#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n,a[50],i,j,sum,t;
    while(~scanf("%d",&n),n)
    {
        sum = 0;
        for(i = 1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        t = 0;
        for(i = 1;i<=n;i++)
        {
            t+=a[i];
            if(2*t==sum)
            break;
        }
        if(i<=n)
        printf("Sam stops at position %d and Ella stops at position %d.\n",i,i+1);
        else
        printf("No equal partitioning.\n");
    }

    return 0;
}



