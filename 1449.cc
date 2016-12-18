#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#define moo 1000000007//10^9+7
#define PI acos(-1.0)
using namespace std;
char s[10][100];
int a[10][100];
struct question
{
    int x;
    int y;
}que[5];
int cou;
int cheek()
{
    int b1[100];
    int b2[100];
    int len=strlen(s[7]);
    for(int i=0;i<len;i++)
    {
        b1[i]=a[4][a[7][i]];
        b2[i]=a[6][i];
    }
    int d[4][30];
    int e[4][30];
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<26;j++)
        {
            int t=a[i][j];
            d[i][j]=t-j;
            e[i][t]=j-t;
        }
    }
    int c[4];
    for(int i=0;i<4;i++)
        c[i]=a[5][i];
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<=3;j++)
        {
            b1[i]+=d[j][(b1[i]+c[j]+26)%26];
            b1[i]=(b1[i]+26)%26;
        }
        for(int j=2;j>=0;j--)
        {
            b1[i]+=e[j][(b1[i]+c[j]+26)%26];
            b1[i]=(b1[i]+26)%26;
        }
        for(int j=0;j<26;j++)
            if(b1[i]==a[4][j]&&b2[i]!=j)
                return 0;
        c[0]++;
        if(c[0]==a[5][0]+26)
        {
            c[0]=a[5][0];
            c[1]++;
            if(c[1]==a[5][1]+26)
            {
                c[1]=a[5][1];
                c[2]++;
                if(c[2]==a[5][2]+26)
                {
                    c[2]=a[5][2];
                    c[3]++;
                    if(c[3]==a[5][3]+26)
                        c[3]=a[5][3];
                }
            }
        }
    }
    return 1;
}
int dfs(int x)
{
    if(x==cou)
    {
        if(cheek()==1)
            return 1;
        return 0;
    }
    for(int i=0;i<26;i++)
    {
        a[que[x+1].x][que[x+1].y]=i;
        if(dfs(x+1)==1)
            return 1;
    }
    return 0;
}
void init()
{
    for(int i=0;i<8;i++)
    {
        int len=strlen(s[i]);
        for(int j=0;j<len;j++)
        {
            if(s[i][j]=='?')
            {
                cou++;
                que[cou].x=i;
                que[cou].y=j;
            }
            else
                a[i][j]=s[i][j]-'a';
        }
    }
}
int main()
{
    int T;
    cin>>T;
    int dd=T;
    while(T--)
    {
        for(int i=0;i<8;i++)
            scanf("%s",s[i]);
        cou=0;
        init();
        dfs(0);
        printf("Scenario #%d:\n",dd-T);
        int len=strlen(s[6]);
        for(int i=0;i<len;i++)
            printf("%c",a[6][i]+'a');
        printf("\n\n");
    }
    return 0;
}



