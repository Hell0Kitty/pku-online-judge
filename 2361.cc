#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int T;
    for(scanf("%d",&T);T;T--)
    {
        char s[12];
        for(int i=0;i<9;i+=3)
            scanf(" %s",s+i);
        int c1=0,c2=0;
        bool flag=true;
        for(int i=0;i<9;i++)
            if(s[i]=='X')
                c1++;
            else if(s[i]=='O')
                c2++;
        if(c1-c2>1||c1<c2)
            flag=false;
        if(!flag)
        {
            puts("no");
            continue;
        }
        for(int i=0;i<9;i+=3)
            if(s[i]==s[i+1]&&s[i+1]==s[i+2]&&s[i]!='.')
            {
                if(s[i]=='X'&&c1!=c2+1)
                    flag=false;
                else if(s[i]=='O'&&c1!=c2)
                    flag=false;
            }
        for(int i=0;i<3;i++)
            if(s[i]==s[i+3]&&s[i+3]==s[i+6]&&s[i]!='.')
            {
                if(s[i]=='X'&&c1!=c2+1)
                    flag=false;
                else if(s[i]=='O'&&c1!=c2)
                    flag=false;
            }
        if(s[0]==s[4]&&s[4]==s[8]&&s[0]!='.')
        {

            if(s[0]=='X'&&c1!=c2+1)
                    flag=false;
            else if(s[0]=='O'&&c1!=c2)
                    flag=false;
        }
        if(s[2]==s[4]&&s[4]==s[6]&&s[0]!='.')
        {
            if(s[2]=='X'&&c1!=c2+1)
                    flag=false;
            else if(s[2]=='O'&&c1!=c2)
                    flag=false;
        }
        if(flag)
            puts("yes");
        else
            puts("no");
    }
    return 0;
}




