#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#define N 10010
using namespace std;
string tel[N];

bool judge(int n)
{
    int i,k,len;
    for(k=0;k<n-1;k++)
    {
        len=tel[k].size();//<tel[k+1].size()?tel[k].size():tel[k+1].size();
        for(i=0;i<len;i++) 
            if(tel[k][i]!=tel[k+1][i])
                break;
        if(i==len) return true;
    }
    return false;
}

int main()
{
    int t,i,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++) cin>>tel[i];
        sort(tel,tel+n);
        if(judge(n)) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}



