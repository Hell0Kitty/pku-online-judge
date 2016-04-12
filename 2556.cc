#include<cstdio>
#include<cstring>
using namespace std;
int dr[][2]={10,0,0,-10,-10,0,0,10};
int main()
{
    char s[250];
    while(gets(s))
    {
        int x=310,y=420,d=0;
        printf("300 420 moveto\n310 420 lineto\n");
        for(int i=0;s[i]!='\0';i++)
        {
            if(s[i]=='A')
                d=(d+1)%4;
            else
                d=(d+3)%4;
            x+=dr[d][0];
            y+=dr[d][1];
            printf("%d %d lineto\n",x,y);
        }
        printf("stroke\nshowpage\n");
    }
    return 0;
}




