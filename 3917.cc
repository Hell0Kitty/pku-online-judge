#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,p1,p0;
    char c[2][3000];
    while(scanf("%s%s",c[0],c[1])!=EOF&&c[0][0]!='E')
    {
        n=strlen(c[0]);
        p0=p1=0;
        for(i=0;i<n;i++)
        {
            if(c[0][i]=='R')
            {
                if(c[1][i]=='R')continue;
                else if(c[1][i]=='P')p1++;
                else p0++;
            }
            else if(c[0][i]=='P')
            {
                if(c[1][i]=='R')p0++;
                else if(c[1][i]=='P')continue;
                else p1++;
            }
            else
            {
                if(c[1][i]=='R')p1++;
                else if(c[1][i]=='P')p0++;
                else continue;
            }
        }
        printf("P1: %d\nP2: %d\n",p0,p1);
    }
    return 0;
}


