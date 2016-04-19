#include<cstdio>
#define MAXN 1010
using namespace std;

struct ops
{
    int l,r,pr;
    char op;
};

ops o[MAXN];
char s[MAXN];
int k,p;
int expr();

int createOps(int l,int r,char op,int pr)
{
    k++;
    o[k].l=l;
    o[k].r=r;
    o[k].pr=pr;
    o[k].op=op;
    return k;
}

int factor()
{
    int ret;
    if(s[p]>='a'&&s[p]<='z')
        ret=createOps(0,0,s[p++],3);
    else
    {
        p++;
        ret=expr();
        p++;
    }
    return ret;
}

int term()
{
    int l,r,ret;
    char op;
    l=factor();
    while(s[p]=='*'||s[p]=='/')
    {
        op=s[p++];
        r=factor();
        l=createOps(l,r,op,2);
    }
    return l;
}

int expr()
{
    int l,r;
    char op;
    l=term();
    while(s[p]=='+'||s[p]=='-')
    {
        op=s[p++];
        r=term(); 
        l=createOps(l,r,op,1);
    }
    return l;
}

void Print(int n,bool inverse)
{
    int l,r;
    if(o[n].op>='a'&&o[n].op<='z')
    {
        putchar(o[n].op);
        return;
    }
    l=o[n].l;
    r=o[n].r;
    if(o[l].pr>o[n].pr)
        Print(l,false);
    else if(o[l].pr<o[n].pr)
    {
        putchar('(');
        Print(l,false);
        putchar(')');
    }
    else
        Print(l,inverse);

    if(!inverse)
        putchar(o[n].op);
    else if(o[n].op=='+')
        putchar('-');
    else if(o[n].op=='-')
        putchar('+');
    else if(o[n].op=='*')
        putchar('/');
    else
        putchar('*');

    if(o[r].pr>o[n].pr)
        Print(r,false);
    else if(o[r].pr<o[n].pr)
    {
        putchar('(');
        Print(r,false);
        putchar(')');
    }
    else
    {
        if(o[n].op=='-'||o[n].op=='/')
            inverse=!inverse;
        Print(r,inverse);
    }
}

int main()
{
    gets(s);
    k=p=0;
    int n=expr();
    Print(n,false);
    return 0;    
}



