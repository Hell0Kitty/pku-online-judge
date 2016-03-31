#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<queue>
using namespace std; 
char s[150];
int t,l,p1,p2;     
void test()
{
      if (!p1 && s[0]=='a' && s[1]=='n' && s[2]=='t' && s[3]=='i')
      {
             p1=1;
             strcpy(s,s+4);
             test();
             return;
      }
      if (!p1 && s[0]=='p' && s[1]=='o' && s[2]=='s' && s[3]=='t')
      { 
             p1=2;
             strcpy(s,s+4);
             test();
             return;
      }
      if (!p1 && s[0]=='p' && s[1]=='r' && s[2]=='e')
      {
             p1=3;
             strcpy(s,s+3);
             test();
             return;
      }   
      if (!p1 && s[0]=='r' && s[1]=='e')
      {
             p1=4;
             strcpy(s,s+2);
             test(); 
             return;
      }
      if (!p1 && s[0]=='u' && s[1]=='n')
      {
             p1=5;
             strcpy(s,s+2);
             test();
             return;
      }
      l=strlen(s);
      if (!p2 && l>=2 && s[l-1]=='r' && s[l-2]=='e')
      {
             p2=1;
             s[l-2]='\0';
             test();
             return;
      }
      if (!p2 && l>=3 && s[l-1]=='g' && s[l-2]=='n' && s[l-3]=='i')
      { 
             p2=2;
             s[l-3]='\0';
             test(); 
             return;
      }
      if (!p2 && l>=3 && s[l-1]=='e' && s[l-2]=='z' && s[l-3]=='i')
      { 
             p2=3;
             s[l-3]='\0';
             test(); 
             return;
      }
      if (!p2 && l>=1 && s[l-1]=='s')
      { 
             p2=4;
             s[l-1]='\0';  
             test();
             return;
      }
      if (!p2 && l>=4 && s[l-1]=='n' && s[l-2]=='o' && s[l-3]=='i' && s[l-4]=='t')
      {
             p2=5;
             s[l-4]='\0'; 
             test();
             return;
      }
      return;
}                                                                                                                            
int main()
{   
      scanf("%d",&t);
      while (t--)
      {
             scanf("%s",s);
             p1=p2=0;
             test();
             if (p1==1) printf("against "); else
             if (p1==2) printf("after "); else
             if (p1==3) printf("before "); else
             if (p1==5) printf("not "); 
             if (p2==1) printf("one who "); else
             if (p2==2) printf("to actively "); else
             if (p2==3) printf("change into "); else
             if (p2==4) printf("multiple instances of "); else
             if (p2==5) printf("the process of ");
             printf("%s",s);
             if (p2==1) printf("s"); 
             if (p2==5) printf("ing");
             if (p1==4) printf(" again");
             printf("\n");

      }
      return 0;
}



