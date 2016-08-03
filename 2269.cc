#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
char s[100008];
int id;
struct point{
    int c[26];
    point(){ memset(c,0,sizeof(c)); }
    point operator + (const point &p1)
    {
        point temp;
        for(int i=0;i<26;i++) temp.c[i]=c[i]|p1.c[i];
        return temp;
    }
    point operator - (const point &p1)
    {
        point temp;
        for(int i=0;i<26;i++) temp.c[i]=c[i]&(!p1.c[i]);
        return temp;
    }
    point operator * (const point &p1)
    {
        point temp;
        for(int i=0;i<26;i++) temp.c[i]=c[i]&p1.c[i];
        return temp;
    }
    void print()
    {
        printf("{");
        for(int i=0;i<26;i++) if(c[i]) printf("%c",'A'+i);
        printf("}\n");
    }
}res;
point get()
{
    point temp;
    for(id++;s[id]!='}';id++) temp.c[s[id]-'A']=1;
    return temp;
}
int getp(char ch)
{
    if(ch=='*') return 2;
    return 1;
}
point cal(point p1,char ch,point p2)
{
    if(ch=='+') return p1+p2;
    else if(ch=='-') return p1-p2;
    return p1*p2;
}
point solve()
{
    point temp,temp2,now;
    stack<char>op;
    stack<point>q;

    if(s[id]=='('){ id++; now=solve(); }
    else now=get();
    q.push(now);
    for(id++;s[id]!='\0'&&s[id]!=')';id++)
    {
        char ch=s[id++];
        if(s[id]=='('){ id++; now=solve(); }
        else now=get();
        if(op.empty()){ op.push(ch); q.push(now); }
        else
        {
            char ch2=op.top();
            op.pop();
            if(getp(ch2)>=getp(ch))
            {
                temp=q.top(); q.pop();
                temp2=q.top();  q.pop();
                temp=cal(temp2,ch2,temp);
                q.push(temp);
                q.push(now);
                op.push(ch);
            }
            else
            {
                temp=q.top(); q.pop();
                now=cal(temp,ch,now);
                q.push(now);
                op.push(ch2);
            }
        }
    }
    if(!op.empty())
    {
        char ch=op.top();
        now=q.top();  q.pop();
        temp=q.top();  q.pop();
        now=cal(temp,ch,now);
    }
    else now=q.top();

    return now;
}
int main()
{
    while(scanf("%s",s)>0)
    {
        id=0;
        res=solve();
        res.print();
    }
    return 0;
}



