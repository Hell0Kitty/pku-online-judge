#include<stdio.h>
int main()
{
        int n;
        while(scanf("%d",&n)!=EOF)
        {
                int i,j;
                int count=0;
                int sum;
                for(i=1;i<=n;i++)
                {
                        sum=0;
                        for(j=i;j<=n;j++)
                        {
                                sum+=j;
                                if(sum==n)
                                        count++;
                                else if(sum>n)
                                        break;
                        }
                }
                printf("%d\n",count);
        }
        return 0;
}


