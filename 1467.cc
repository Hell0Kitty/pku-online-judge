#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stack>
using namespace std;
class String
{
public:
    char s[105];
    String(){s[0]=0;}
    String(String& s1){strcpy(s,s1.s);}
    bool isnum();
};
char ans[105];
ostream& operator<<(ostream& out,String &s1)
{
    cout<<s1.s;
    return out;
}
bool String::isnum()
{
    int i=0;
    if(s[0]=='-') i++;
    for(;s[i];i++)
    {
        if(s[i]=='.'||(s[i]>='0'&&s[i]<='9')) ;
        else break;
    }
    if(!s[i]) return true;
    else return false;
}
void qiudao(String s1);
void jia(String s1,String s2)
{
    qiudao(s1);
    strcat(ans,"+");
    qiudao(s2);
}
void jian(String s1,String s2)
{
    qiudao(s1);
    strcat(ans,"-");
    qiudao(s2);
}
void cheng(String s1,String s2)
{
    strcat(ans,"(");
    qiudao(s1);
    strcat(ans,"*");
    strcat(ans,s2.s);
    strcat(ans,"+");
    strcat(ans,s1.s);
    strcat(ans,"*");
    qiudao(s2);
    strcat(ans,")");
}
void chu(String s1,String s2)
{
    strcat(ans,"(");
    qiudao(s1);
    strcat(ans,"*");
    strcat(ans,s2.s);
    strcat(ans,"-");
    strcat(ans,s1.s);
    strcat(ans,"*");
    qiudao(s2);
    strcat(ans,")/");
    strcat(ans,s2.s);
    strcat(ans,"^2");
}
void ln(String s1)
{
    strcat(ans,"(");
    qiudao(s1);
    strcat(ans,")/(");
    strcat(ans,s1.s);
    strcat(ans,")");
}
void qiudao(String s1)
{
    int i;
    if(s1.isnum()) {strcat(ans,"0");return ;}//如果字符串表示一个数字，则求导结果为 0
    if(strcmp(s1.s,"x")==0) {strcat(ans,"1");return ;}//如果字符串是一个x，则求导结果为 1
    int len=strlen(s1.s);
    //下面用于计算优先级最低的一个运算符。
    int n=-1,you=3;
    for(i=0;s1.s[i];i++)
    {
        if(i!=0&&((s1.s[i]=='+'||s1.s[i]=='-')&&you>=1)) {n=i;you=1;break;}
        if(i!=0&&((s1.s[i]=='*'||s1.s[i]=='/')&&you>=2)) {n=i;you=2;}
        if(s1.s[i]=='(')
        {
            int n=1;
            while(n)
            {
                i++;
                if(s1.s[i]=='(')n++;
                if(s1.s[i]==')')n--;
            }
        }
    }
    if(you!=3)
    {
        String ss1,ss2;
        strncpy(ss1.s,s1.s,n);
        ss1.s[n]=0;
        strncpy(ss2.s,&s1.s[n+1],len-n-1);
        ss2.s[len-n-1]=0;
        switch(s1.s[n])
        {
            case '+':jia(ss1,ss2);break;
            case '-':jian(ss1,ss2);break;
            case '*':cheng(ss1,ss2);break;
            case '/':chu(ss1,ss2);break;
        }
        return ;
    }
    if(s1.s[0]=='('&&s1.s[len-1]==')')
    {
        String s2;
        strncpy(s2.s,s1.s+1,len-2);
        s2.s[len-2]=0;
        strcat(ans,"(");
        qiudao(s2);
        strcat(ans,")");
        return ;
    }
    if(strncmp(s1.s,"ln(",3)==0&&s1.s[len-1]==')')
    {
        String ss1;
        strncpy(ss1.s,s1.s+3,len-4);
        ss1.s[len-4]=0;
        ln(ss1);
    }
}
int main()
{
    String s1;
    int i;
    while(cin>>s1.s)
    {
        ans[0]=0;
        qiudao(s1);
        for(i=0;ans[i];i++)
        {
            if(ans[i+1]=='-')
            {
                if(ans[i]=='+') {cout<<'-';i++;continue;}
                if(ans[i]=='-') {cout<<'+';i++;continue;}
            }
            cout<<ans[i];
        }
        cout<<endl;
    }
    return 0;
}



