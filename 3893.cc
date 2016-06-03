#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char  str[10100];
int v[10100]={0,1,2,3};
int main()
{
    int i,strnum,end,start;
    while(scanf("%d%s%d",&end,str,&start)!=EOF)
    {
       strnum=strlen(str);
       start=v[start];
       for(i=strnum-1;i>=0;i--)
       {
           if(str[i]=='f')
           {
               if(start&1)//判断奇偶
               {
                 start++;
               }
               else
               {
                   start=start+3;
               }
           }
           else if(str[i]=='k')
           {
              printf("%d\n",start);
           }
           else if(str[i]=='b')
           {
               start=start-2;
           }
           else if(str[i]=='<')
           {
               v[end]=start;
           }
           else if(str[i]=='=')
           {
               if(v[end]==start)
               {
                   printf("=\n");
               }
               else
               printf("#\n");
           }
       }
    }

    return 0;
}


