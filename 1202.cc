#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
#define MAX 450
struct node
{
    int p1,p2;
    bool s1;
}ss[305];
char map[305][305][450];

int Compare(const char *a, const char *b);
void IntAddition(char *augend, char *addend, char *sum);

void FloatAddition(char *augend, char *addend, char *sum);
void FloatDivision(char *dividend, char *divisor, char *quotient, int precision);

int subcompare(char *str1,char *str2)
{
    int len1=strlen(str1);
    int len2=strlen(str2);
    int tmp1=0;
    int tmp2=0;
    int pos1=0;
    int pos2=0;
    int i,j;
    for(i=0;i<len1;i++)
    {
        if(str1[i]=='.')break;
        tmp1=tmp1*10+str1[i]-'0';
    }
    pos1=i;
    for(i=0;i<len2;i++)
    {
        if(str2[i]=='.')break;
        tmp2=tmp2*10+str2[i]-'0';
    }
    pos2=i;
    if(tmp1>tmp2)return 1;
    else if(tmp2>tmp1)return -1;
    else
    {
        for(i=pos1+1,j=pos2+1;i<len1,j<len2;i++,j++)
        {
            if(str1[i]<str2[j])return -1;
            else if(str1[i]>str2[j])return 1;
        }
        if(i==len1)return -1;
        else 
            return 1;
    }
}

void dfs(int n,int p,int q)
{
    int i;
    if(p==q)
        map[p][q][0]='1',map[p][q][1]='0',map[p][q][2]='0',map[p][q][3]='.',map[p][q][4]='0',map[p][q][5]='\0';
    else if(ss[p].s1==false && ss[q].s1==false)
        map[p][q][0]='0',map[p][q][1]='.',map[p][q][2]='0',map[p][q][3]='\0';
    if(map[p][q][0]!='\0')
        return;

    char two[5];
    memset(two,'\0',sizeof(two));
    two[0]='2';two[1]='\0';
    char ans1[450]={0};
    char ans2[450]={0};
    if(ss[p].s1)
    {
        int p_1=ss[p].p1;
        int p_2=ss[p].p2;
        if(map[p_1][q][0]=='\0')
            dfs(n,p_1,q);
        if(map[p_2][q][0]=='\0')
            dfs(n,p_2,q);

        FloatAddition(map[p_1][q],map[p_2][q],ans1);

        FloatDivision(ans1,two,ans2,300);

        int n_1=strlen(ans2);
        //for(i=0;i<n_1;i++)
        strcpy(map[p][q],ans2);
        //return;
    }
    if(ss[q].s1)
    {
        int q_1=ss[q].p1;
        int q_2=ss[q].p2;
        if(map[p][q_1][0]=='\0')
            dfs(n,p,q_1);
        if(map[p][q_2][0]=='\0')
            dfs(n,p,q_2);

        FloatAddition(map[p][q_1],map[p][q_2],ans1);

        FloatDivision(ans1,two,ans2,300);

        int n_1=strlen(ans2);

        if(subcompare(ans2,map[p][q])>0)
        {
            strcpy(map[p][q],ans2);
        }
        //return;
    }
    return;

}
int main()
{
    int n,k;
    int i,j,a,b,c,p,q;
    char sss[450];
    scanf("%d %d",&n,&k);

        for(i=0;i<=n;i++)
            ss[i].s1=false;
        for(i=1;i<=k;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            ss[a].p1=b;
            ss[a].p2=c;
            ss[a].s1=true;
        }
        for(i=0;i<305;i++)
            for(j=0;j<305;j++)
                map[i][j][0]='\0';
        scanf("%d",&k);
        while(k--)
        {
            scanf("%d %d",&p,&q);
            dfs(n,p,q);
            int n1=strlen(map[p][q]);
            strcpy(sss,map[p][q]);
            bool f1=0;
            for(i=0;i<n1;i++)
            {
                 if(map[p][q][i]=='.')
                 {
                      f1=1;
                      break;                     
                 }                 
            }
            if(f1)
            {
                for(i=n1-1;i>=0;i--)
                {
                     if(map[p][q][i]!='0')
                     {
                          if(map[p][q][i]=='.')
                          map[p][q][i]='\0';
                          else
                          map[p][q][i+1]='\0';
                          break;
                     }                    
                }
            }
            if(strlen(map[p][q])==0)printf("0%%\n",map[p][q]);
            else
                printf("%s%%\n",map[p][q]);
            strcpy(map[p][q],sss);
        }
    return 0;
}

void FloatDivision(char *dividend, char *divisor, char *quotient, int precision)
{
    char ans[MAX];
    int n1=strlen(dividend);
    int i,j;
    bool f1=false;
    for(i=0;i<n1;i++)
    {
        if(dividend[i]=='.')
        {
            ans[i]='.';
            continue;
        }
        j=dividend[i]-'0';
        if(f1)
            j+=10;
        ans[i]=j/2+'0';
        if((dividend[i]-'0')%2==1)
            f1=true;
        else
        f1=false;
    }
    if(f1)
        ans[i++]='5';
    ans[i]='\0';
    n1=strlen(ans);
    j=0;
    for(i=0;i<n1;i++)
    {
        if(ans[i]!='0')
        {
            if(ans[i]=='.')
                i--;
            break;
        }
    }
    for(;i<=n1;i++)
    {
        quotient[j++]=ans[i];
    }
}

void FloatAddition(char *augend, char *addend, char *sum)
{
    int len1=strlen(augend);
    int len2=strlen(addend);
    int i,j,cf;
    int tpos1,tpos2;
    int respos;
    int pos1,pos2;
    for(i=0;i<450;i++)
    {
        sum[i]='0';
    }
    for(i=0;i<len1;i++)
    {
        if(augend[i]=='.')break;
    }
    if(i==len1-1)
    {
        augend[i+1]='0';
        len1++;

    }
    if(i==len1)
    {
        augend[i]='.';
        i++;
        len1++;
        len1++;
        augend[i+1]='0';
    }
    pos1=i;
    for(i=0;i<len2;i++)
    {
        if(addend[i]=='.')break;
    }
    if(i==len2-1)
    {
        addend[i+1]='0';
        len2++;

    }
    if(i==len2)
    {
        addend[i]='.';
        i++;
        addend[i+1]='0';
        len2++;
        len2++;
    }
    pos2=i;
    respos=449;
    if(len1-pos1<len2-pos2)
    {

        tpos2=len2-1;
        tpos1=len1-1;

        while(len1-pos1<=tpos2-pos2)
        {
            sum[respos--]=addend[tpos2];
            tpos2--;
        }
        if(addend[tpos2]=='.')tpos2--;

        cf=0;
        while(tpos1>pos1)
        {
            sum[respos--]=(addend[tpos2]+augend[tpos1]+cf-'0'-'0')%10+'0';
            cf=(addend[tpos2]+augend[tpos1]+cf-'0'-'0')/10;
            tpos2--;
            tpos1--;
        }

        tpos1--;
        tpos2--;
        sum[respos--]='.';
        while(tpos1>=0 && tpos2>=0)
        {
            sum[respos--]=(addend[tpos2]+augend[tpos1]+cf-'0'-'0')%10+'0';
            cf=(addend[tpos2]+augend[tpos1]+cf-'0'-'0')/10;
            tpos2--;
            tpos1--;
        }

        if(tpos2>=0)
        {
            while(tpos2>=0)
            {
                sum[respos--]=(addend[tpos2]+cf-'0')%10+'0';
                cf=(addend[tpos2]+cf-'0')/10;
                tpos2--;
            }
        }
        else if(tpos1>=0)
        {
            while(tpos1>=0)
            {
                sum[respos--]=(augend[tpos1]+cf-'0')%10+'0';
                cf=(augend[tpos1]+cf-'0')/10;
                tpos1--;
            }            
        }
        if(cf!=0)
        {
            sum[respos--]=cf+'0';
        }
    }
    else
    {

        tpos2=len2-1;
        tpos1=len1-1;

        while(len2-pos2<=tpos1-pos1)
        {
            sum[respos--]=augend[tpos1];
            tpos1--;
        }
        if(augend[tpos1]=='.')tpos1--;

        cf=0;
        while(tpos1>pos1)
        {
            sum[respos--]=(addend[tpos2]+augend[tpos1]+cf-'0'-'0')%10+'0';
            cf=(addend[tpos2]+augend[tpos1]+cf-'0'-'0')/10;
            tpos2--;
            tpos1--;
        }

        tpos1--;
        tpos2--;
        sum[respos--]='.';
        while(tpos1>=0 && tpos2>=0)
        {
            sum[respos--]=(addend[tpos2]+augend[tpos1]+cf-'0'-'0')%10+'0';
            cf=(addend[tpos2]+augend[tpos1]+cf-'0'-'0')/10;
            tpos2--;
            tpos1--;
        }
        if(tpos2>=0)
        {
            while(tpos2>=0)
            {
                sum[respos--]=(addend[tpos2]+cf-'0')%10+'0';
                cf=(addend[tpos2]+cf-'0')/10;
                tpos2--;
            }
        }
        else if(tpos1>=0)
        {
            while(tpos1>=0)
            {
                sum[respos--]=(augend[tpos1]+cf-'0')%10+'0';
                cf=(augend[tpos1]+cf-'0')/10;
                tpos1--;
            }            
        }
        if(cf!=0)
        {
            sum[respos--]=cf+'0';
        }

    }

    for(i=0;;i++)
    {
        if(sum[i]!='0')break;
    }
    if(sum[i]=='.')i--;
    for(j=i;j<450;j++)
    {
        sum[j-i]=sum[j];
    }
    sum[j-i]='\0';
    if(sum[strlen(sum)-1]=='.')
    {
        int xx=strlen(sum);
        sum[xx]='0';
        sum[xx+1]='\0';
    }
}


