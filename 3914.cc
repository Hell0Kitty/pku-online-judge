#include <stdio.h>  
#include <string.h>

int n,p,s;  
int dulls[21],programs[10];  
int exist[21]; 
char need[10][22];  
int main()  
{  
    int i,j,sum,tran,max;  
    while(1)  
    {  
        sum=0,max=-1;  
        for(i=0;i<21;i++) exist[i]=0;  
        scanf("%d",&n);  
        if(n==0) break;  
        scanf("%d %d",&p,&s);  
        for(i=0;i<n;i++) scanf("%d",&dulls[i]);  
        for(i=0;i<p;i++) scanf("%d %s",&programs[i],need[i]);  
        for(i=0;i<s;i++)  
        {  
            scanf("%d",&tran);  
            if(tran>0)  
            {  
                tran--;  

                sum+=programs[tran];  
                max=max>sum?max:sum;  
                for(j=0;j<strlen(need[tran]);j++)  
                {  
                    if(exist[need[tran][j]-'A']==0)  
                    {  
                        sum+=dulls[need[tran][j]-'A'];  
                        max=max>sum?max:sum;  
                    }  
                    exist[need[tran][j]-'A']++;  
                }  
            }  
            else  
            {  
                tran=-1-tran;  
                sum-=programs[tran];  
                max=max>sum?max:sum;  
                for(j=0;j<strlen(need[tran]);j++)  
                {  
                    exist[need[tran][j]-'A']--;

                    if(exist[need[tran][j]-'A']==0)  
                    {  
                        sum-=dulls[need[tran][j]-'A'];  
                        max=max>sum?max:sum;  
                    }  
                }  
            }  
        }  
        printf("%d\n",max);  
    }  
}



