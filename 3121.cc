#include<cstdio>
#include<cstring>
#include<ctime>
#define MAX_HASH_SIZE 100000
#define MAX_ENTRY_SIZE 5000
#define MAX_DATA 4000000
using namespace std;

struct Entry
{
    int *a,len;
}e[MAX_ENTRY_SIZE];

struct LNode
{
    int id;
    LNode *next;
};

int m,n,s[MAX_ENTRY_SIZE],pool[MAX_DATA];
LNode *hashList[MAX_HASH_SIZE];

bool Cmp(int *a,int la,int *b,int lb)
{
    int i;
    if(la!=lb)
        return 1;
    for(i=0;i<la;i++)
        if(a[i]!=b[i])
            return 1;
    return 0;
}

int ELFHash(int *a,int len)
{
    unsigned int h=0;
    for(;len--;)
    {
        h=(h<<4 + *a);
        a++;
        unsigned int g=h&0xf0000000;
        if(g)
            h^=g>>24;
        h&=~g;
    }
    return h%MAX_HASH_SIZE;    
}

int ID(int *a, int len)
{
    int i=ELFHash(a,len);
    LNode *p;
    for(p=hashList[i];p;p=p->next)
        if(Cmp(a,len,e[p->id].a,e[p->id].len)==0)
            return p->id;
    p=new LNode();
    p->next=hashList[i];
    p->id=n;
    hashList[i]=p;
    e[n].a=pool+m;
    e[n].len=len;
    for(;len--;m++,a++)
        pool[m]=*a;
    n++;
    return n-1;
}

int main()
{
    int T,m,top,*q,i,j,k,id,z[MAX_ENTRY_SIZE];
    char cmd[11],op;
    for(scanf("%d",&T);T--;)
    {
        memset(hashList,0,sizeof(hashList));
        n=top=m=0;
        for(scanf("%d",&m);m--;)
        {
            scanf("%s",cmd);
            op=cmd[0];
            if(op=='P')
                s[top++]=ID(NULL,0);
            else if(op=='D')
                s[top]=s[top-1],top++;
            else
            {
                int x=s[--top];
                int y=s[--top];
                if(op=='U')
                {
                    for(k=i=j=0;i<e[x].len&&j<e[y].len;k++)
                        if(e[x].a[i]<e[y].a[j])
                            z[k]=e[x].a[i++];
                        else if(e[x].a[i]>e[y].a[j])
                            z[k]=e[y].a[j++];
                        else
                            z[k]=e[y].a[j++],i++;
                    for(;i<e[x].len;)
                        z[k++]=e[x].a[i++];
                    for(;j<e[y].len;)
                        z[k++]=e[y].a[j++];
                }
                else if(op=='I')
                {
                    for(k=i=j=0;i<e[x].len&&j<e[y].len;)
                        if(e[x].a[i]<e[y].a[j])
                            i++;
                        else if(e[x].a[i]>e[y].a[j])
                            j++;
                        else
                            z[k++]=e[x].a[i++],j++;
                }
                else
                {            
                    for(i=0;i<e[y].len;i++)
                    {
                        z[i]=e[y].a[i];
                        if(z[i]==x)
                            x=-1;
                    }
                    k=e[y].len;
                    if(x>=0)
                    {
                        k++;
                        for(i--;i>=0&&z[i]>x;i--)
                            z[i+1]=z[i];
                        z[i+1]=x;
                    }    
                }
                s[top++]=ID(z,k);    
            }
            printf("%d\n",e[s[top-1]].len);
        }
        puts("***");
    }
    return 0;
}



