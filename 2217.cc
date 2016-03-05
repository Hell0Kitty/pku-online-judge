nclude <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <vector>

#define MAXN 10010
#define INF 0x80000000

using namespace std;

int n,k;

int Rank[MAXN];
int tmp[MAXN];

bool cmpSa(int i, int j)
{
    if(Rank[i] != Rank[j])return Rank[i] < Rank[j];
    else
    { 
        int ri = i+k <=n? Rank[i+k]:-1;
        int rj = j+k <= n ? Rank[j+k]:-1;
        return ri <rj;
    }
}

void con_sa(char *s, int *sa)
{
    for(int i=0;i<=n;i++){
        sa[i]=i;Rank[i] = i < n?s[i]:-1;
    }

    for(k=1;k<=n;k*=2)
    {
        sort(sa,sa+n+1,cmpSa);
        tmp[sa[0]] = 0; 
        for(int i=1;i<=n;i++){
            tmp[sa[i]] = tmp[sa[i-1]] +(cmpSa(sa[i-1],sa[i])?1:0);

        }
        for(int i=0;i<=n;i++){
            Rank[i] = tmp[i];
        }
    }
}

void construct_lcp(char *s,int *sa,int *lcp)
{
    for(int i=0; i<=n; i++)Rank[sa[i]]=i;

    int h=0;
    lcp[0]=0;
    for(int i=0;i<n;i++)
    {
        int j=sa[Rank[i]-1];

        if(h>0)h--;
        for(; j+h<n && i+h<n; h++)
        {
            if(s[j+h]!=s[i+h])break;
        }
        lcp[Rank[i]-1]=h;
    }
}

int main()
{
    int sa[MAXN],lcp[MAXN];
    char s[MAXN],t[MAXN];
    char c;
    int ncase,mmax,len,leng;

    while(scanf("%d",&ncase)!=EOF)
    {
        while(ncase--)
        {
            mmax =0;
            while((c=getchar())==' '|| c=='\n');
            s[0]=c;
            int tt=1;
            while((c=getchar()) != '\n')
            {
                s[tt++]=c;

            }

            s[tt]='\0';
            while((c=getchar())==' '|| c=='\n');
            t[0]=c;
            tt=1;
            while((c=getchar()) != '\n')
            {
                 t[tt++]=c;

            }
            t[tt]='\0';
            len=strlen(s);
            leng =len+1+strlen(t);
            strcpy(s+len+1,t);
            n=leng;
            con_sa(s,sa);
            construct_lcp(s,sa,lcp);

           for(int i=0;i<leng;i++)
            {
              if((sa[i]<len) != (sa[i+1]<len))
                  mmax=max(mmax,lcp[i]);
            }
            printf("Nejdelsi spolecny retezec ma delku %d.\n",mmax);
        }
    }

    return 0;
}



