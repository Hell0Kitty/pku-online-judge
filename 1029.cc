#include<cstdio>  
#include<cstring>  
#include<iostream>  
#include<stack>  
using namespace std;  
const int maxn=1010;  
int n,m,k,a[maxn],b[maxn],cnta[maxn],cntb[maxn],cnt;  
int main()  
{  
    int T;  
    while(scanf("%d%d",&n,&m)!=EOF)  
    {  
    int k;  
    cnt=0;  
    memset(cnta,0,sizeof(cnta));  
    memset(cntb,0,sizeof(cntb));  
    for(int i=0;i<m;i++)  
    {  
       scanf("%d",&k);  
       for(int j=0;j<k;j++)  
        scanf("%d",&a[j]);  
       for(int j=0;j<k;j++)  
        scanf("%d",&b[j]);  
       char op[3];  
       scanf("%s",op);  
       if(op[0]=='=')  
       {  
           for(int j=0;j<k;j++)  
           cnta[a[j]]=cntb[a[j]]=cnta[b[j]]=cntb[b[j]]=-1;  
       }  
       else if(op[0]=='<')  
       {  
           cnt++;  
           for(int j=0;j<k;j++)  
           {  
           if(cnta[a[j]]!=-1)  
               cnta[a[j]]++;  
           if(cntb[b[j]]!=-1)  
               cntb[b[j]]++;  
           }  
       }  
       else  
       {  
           cnt++;  
           for(int j=0;j<k;j++)  
           {  
           if(cntb[a[j]]!=-1)  
               cntb[a[j]]++;  
           if(cnta[b[j]]!=-1)  
               cnta[b[j]]++;  
           }  
       }  
    }  
    int cou=0,ans=-1;  
    for(int i=1;i<=n;i++)  
    {  
        if(cnta[i]!=-1)  
        {  
        ans=i;  
        cou++;  
        }  
    }  
    if(cou==1)  
    {  
        printf("%d\n",ans);  
        continue;  
    }  
    cou=0;  
    if(cnt!=0)  
    {  
        for(int i=1;i<=n;i++)  
        if(cnta[i]==cnt||cntb[i]==cnt)  
        {  
            cou++;  
            ans=i;  
        }  
        if(cou==1)  
        {  
        printf("%d\n",ans);  
        continue;  
        }  
    }  
    printf("0\n");  
    }  
    return 0;  
}  
