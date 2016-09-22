#include<stdio.h>  
#include<string.h>
#define MAX 30  
char mul1[MAX];  
char ans[2*MAX];  
void multiply(char *a,char *b,char *c)  
{  
    int i,j,ca,cb,*s;  
    ca=strlen(a);  
    cb=strlen(b);  
    s=(int *)malloc(sizeof(int)*(ca+cb));  
    for(i=0;i<ca+cb;i++) s[i]=0;  
    for(i=0;i<ca;i++)  
    {  
        for(j=0;j<cb;j++)  
        {  
            s[i+j+1]=(a[i]-'0')*(b[j]-'0');  
        }  
    }  
    for(i=ca+cb-1;i>=0;i--)  
    {  
        if(s[i]>9)  
        {  
            s[i-1]+=s[i]/10;  
            s[i]%=10;  
        }  
    }  
    i=0,j=0;  
    while(s[i]==0) i++;  
    while(i<ca+cb)  
    {  
        c[j]=s[i]+'0';  
        j++;  
        i++;  
    }  
    c[j]='\0';  
    free(s);  
}  
int main()  
{   
    int n,d,i;  
    while(scanf("%d %d",&n,&d))  
    {  
        if(n==0 && d==0) break;  
        sprintf(mul1,"%d",n);  
        sprintf(ans,"%d",n);  
        if(d==0)  
        {  
            printf("1\n");  
            continue;  
        }  
        for(i=1;i<d;i++)  
        {  
            multiply(mul1,ans,ans);  
        }  
        printf("%s\n",ans);  
    }  
    return 0;  
}



