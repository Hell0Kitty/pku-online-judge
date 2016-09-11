#include<stdio.h>
#include<string.h>
char m[1000007],z[1000007];
    int m1[1000007],z1[1000007];
int main()
{

    int count=1;
    while(scanf("%s",m)!=EOF)
    {
        if(strcmp(m,"0")==0)break;
        int len=strlen(m);
        int flag,flag1;
        z[0]=m[len-1];
        int b=1;
        for(int c=0;c<len;c++)
        {
            m1[c]=m[c]-'0';
        z1[c]=z[c]-'0';
        }

       for(int a=len-2;a>=0;a--)
       {
           if(m1[a]<z1[b-1])
           {z1[b++]=10+m1[a]-z1[b-1];m1[a-1]--;}
           else z1[b++]=m1[a]-z1[b-1];
       }
       printf("%d. ",count++);
       if(z1[len-1]==0)printf("IMPOSSIBLE\n");
       else{for(int b=len-1;b>=0;b--)
       printf("%d",z1[b]);
       printf("\n");
       }

    }
    return 0;
}



