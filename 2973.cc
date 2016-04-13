#include<iostream>
#include<algorithm>
using namespace std;

int comp(char &a,char &b)
{
    return a<b;
}

int main()
{
    int n;
    char dic[1005][10];
    char temp[10];
    int i,j,k;
    int match;
    int blank;
    int pos;
    int res;
    while(1)
    {
        cin>>n;
        if(n==0)
            break;
        for(i=0;i<n;i++)
        {
            cin>>temp;
            sort(temp,temp+strlen(temp),comp);
            strcpy(dic[i],temp);
        }
        cin>>temp;
        blank=0;
        sort(temp,temp+strlen(temp),comp);
        for(i=0;i<strlen(temp);i++)
        {
            if(temp[i]=='_')
                blank++;
        }
        res=0;
        for(k=0;k<n;k++)
        {
            pos=-1;
            match=0;
            for(i=0;i<strlen(dic[k]);i++)
            {
                for(j=pos+1;j<strlen(temp)-blank;j++)
                {
                    if(dic[k][i]==temp[j])
                    {
                        pos=j;
                        match++;
                        break;
                    }
                }
            }
            if(strlen(dic[k])-match<=blank)
            {
                res++;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}

