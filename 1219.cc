#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
bool illegal(char *str)
{
    if(strlen(str)>5) return true;
    for(int i=0;i<5;i++)
      if(str[i]<'A'||str[i]>'Z')
         return true;
    return false;
}
int main()
{

    char ori[10];
    while(gets(ori))
    {
        if(!strlen(ori))  continue;
        if(!strcmp(ori,"LINGO")) break;
        puts("");
        int used[26];
        memset(used,0,sizeof(used));
        for(int i=0;i<5;i++) used[ori[i]-65]++;
        char last[10];
        strcpy(last,ori);
        for(int i=1;i<5;i++) last[i]='.';
        puts(last);
        bool find=false;
        int count=0;
        while(true)
        {
           char res[10],str[128];
           res[5]='\0';
           gets(str);
           if(!strlen(str)) break;
           if(!find&&count<5)
           {
               if(illegal(str)) puts(last);
               else
               {
                   int c[26];
                   memcpy(c,used,sizeof(used));
                   for(int i=0;i<5;i++)
                     if(str[i]==ori[i])
                       c[str[i]-65]--,res[i]=str[i];
                   for(int i=0;i<5;i++)
                     if(str[i]!=ori[i]&&c[str[i]-65]>0)
                        c[str[i]-65]--,res[i]=str[i]+32;
                     else if(str[i]!=ori[i])
                        res[i]='.';
                   strcpy(last,res);
                   puts(res);
                   if(!strcmp(str,ori)) find=true;
               }
               count++;
           }
        }
        if(!find) 
        {
           for(int i=0;i<5;i++) ori[i]+=32;
           puts(ori);
        }
    }
    return 0;
}


