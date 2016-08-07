#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mr=40000;
bool notp[mr];
int pr[mr];
int pn;
void getpri()//筛素数
{
    pn=0;
    memset(notp,0,sizeof(notp));
    for(int i=2; i<mr; i++)
    {
        if(!notp[i])
        {
            pr[pn++]=i;
        }
        for(int j=0; j<pn && i*pr[j]<mr; j++)
        {
            int k=i*pr[j];
            notp[k]=1;
            if(i%pr[j]==0)
            {
                break;
            }
        }
    }
}
int power(int a,int n)
{
    if(n==0)
        return 1;
    else if(n==1)
        return a;
    else if(n&1)
        return a*power(a*a,n>>1);
    else
        return power(a*a,n>>1);
}
char s[100000];
int main()
{
    getpri();
    while(gets(s))
    {
        if(s[0]=='0')
            break;
        int a,b,sum=1,i=0;
        while(s[i]!='\0')
        {
            a=0,b=0;
            while(s[i]!=' '&&s[i]!='\0')
            {
                a=a*10+(s[i]-'0');
                i++;
            }
            i++;
            while(s[i]!=' '&&s[i]!='\0')
            {
                b=b*10+(s[i]-'0');
                i++;
            }
            sum*=power(a,b);
            if(s[i]=='\0')
                break;
            i++;
        }
        sum--;
        int stk[40000][2],top=0;
        for(int i=0;i<pn&&pr[i]<=sum;i++)
        {
            if(sum%pr[i]==0)
            {
                b=0;
                a=pr[i];
                while(sum%a==0)
                {
                    sum/=a;
                    b++;
                }
                stk[top][0]=a;
                stk[top][1]=b;
                top++;
            }
        }
        --top;
        printf("%d %d",stk[top][0],stk[top][1]);
        for(--top;top>=0;top--)
        {
            printf(" %d %d",stk[top][0],stk[top][1]);
        }
        printf("\n");
    }
    return 0;
}


