#include <iostream>
#include <stdio.h>
#include <stack>
#include <string>
using namespace std;

const int n=53;
struct node
{
    node *next[n];
    node()
    {
        int i;
        for(i=0;i<n;i++)
            next[i]=NULL;
    }
};
node *root,*p;
int res;

int hash(string s)   //传说中的hash
{
    int temp=0;
    if(s[1]=='0')
    {
        if(s[2]=='C') temp+=13*0;
        else if(s[2]=='D') temp+=13*1;
        else if(s[2]=='H') temp+=13*2;
        else temp+=13*3;
        return temp+=10;
    }

    if(s[1]=='C') temp+=13*0;
    else if(s[1]=='D') temp+=13*1;
    else if(s[1]=='H') temp+=13*2;
    else temp+=13*3;

    switch(s[0])
    {
        case 'A': temp+=1;break;
        case 'J': temp+=11;break;
        case 'Q': temp+=12;break;
        case 'K': temp+=13;break;
        default :temp+=s[0]-'0';break;
    }
    return temp;
}

void Insert(int num)
{
    if(p->next[num]==NULL)
    {
        p->next[num]=new node();
        res++;
    }
    p=p->next[num];
}

void Delete(node *t)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(t->next[i]!=NULL)
            Delete(t->next[i]);
        t->next[i]=NULL;
    }
    delete t;
}

int main()
{
    int num,m,i,j;
    string str;
    stack<string> s;
    while(scanf("%d",&num) && num!=0)
    {
        res=0;
        root=new node();
        for(i=0;i<num;i++)
        {
            scanf("%d",&m);
            for(j=0;j<m;j++)
            {
                cin>>str;
                s.push(str);
            }

            p=root;
            while(!s.empty())
            {
                int value=hash(s.top());
                s.pop();
                Insert(value);
            }
        }
        printf("%d\n",res);
        Delete(root);
    }
    return 0;
}



