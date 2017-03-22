#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int find(char *a,char *b)
{
    int i,j,count,flag,lena,lenb;
    lena=strlen(a);
    lenb=strlen(b);
    flag=0;
    for(i=0;i<lena;i++)
    {    
       count=0;
       for(j=0;j<lenb;j++)
       {
           if(b[j]==a[i+j])
              count++;                   
       }
       if(i>0&&count==lenb&&((a[i-1]==' '||a[i-1]=='!')&&(a[i+j]==' '||a[i+j]=='!')))
           flag=1;
       else if(i==0&&count==lenb&&(a[i+j]==' '||a[i+j]=='!'))
           flag=1;
    }
    return flag;
}
void change(char *s)
{
    for(int i=0;i<strlen(s);i++)     
        if(s[i]>='A'&&s[i]<='Z')
           s[i]+='a'-'A';
}
int main()
{
    char name[6][30];
    char wish[210];
    int flag[6];
    int k;  
    char a[10]={"beautiful"};
    char b[7]={"pretty"};
    char c[7]={"lovely"};  
    int g,w,word,count;
    while(~scanf("%d%d",&g,&w))
    {
        for(int i=0;i<g;i++)
           cin>>name[i];
        getchar();      
        while(w--)
        {
           gets(wish);
           word=0;
           count=0;
           change(wish);
           memset(flag,0,sizeof(flag));
           for(int i=0;i<g;i++)
           {
               flag[i]=find(wish,name[i]);        
           }
           for(int i=0;i<strlen(wish);i++)
               if((wish[i+1]==' '||wish[i+1]=='!')&&((wish[i]>='a'&&wish[i]<='z')||(wish[i]>='A'&&wish[i]<='Z')))
                   word++;
           for(int i=0;i<g;i++)
           {
               if(flag[i]==1)
               {
                  if(count>0)
                     printf(" %s",name[i]);
                  else
                     printf("%s",name[i]);
                  count++; 
               }
            }         
           if(count==0) 
                   printf("All"); 
           printf(": ");
           if(word<=9)
               printf("oh\n");
           else if(word>=10&&(find(wish,a)||find(wish,b)||(find(wish,c))))
               printf("xixi\n");
           else if(word>=10)
               printf("hehe\n");
        }
    }  
    return 0;
}



