// Source
// 
// Problem Id:1036  User Id:daofeng 
// Memory:24K  Time:600MS 
// Language:C++  Result:Accepted
// 
// Source 
#include <iostream> 
using namespace std;
int main() 
{ 
    int n,k,time,i,j,max,ii,temp; 
    int t[100],p[100],s[100],a[2][101]; 
    cin>>n>>k>>time; 
    for(i=0;i<n;i++) 
        cin>>t[i]; 
    for(i=0;i<n;i++) 
        cin>>p[i]; 
    for(i=0;i<n;i++) 
        cin>>s[i]; 
    for(j=0;j<=k;j++) 
    { 
        a[0][j]=0; 
    } 
    for(i=0;i<n-1;i++) 
        for(j=i+1;j<n;j++) 
            if (t[i]>t[j]) 
            { 
                temp=t[i]; 
                t[i]=t[j]; 
                t[j]=temp; 
                temp=s[i]; 
                s[i]=s[j]; 
                s[j]=temp; 
                temp=p[i]; 
                p[i]=p[j]; 
                p[j]=temp; 
            } 
    ii=1;temp=0; 
    while (t[temp]==0) 
        temp++; 
    for(i=1;i<=time&&temp<n;i++) 
    { 
        for(j=0;j<=k;j++) 
        { 
            a[ii][j]=0; 
            if (j>0&&a[1-ii][j-1]>a[ii][j]) a[ii][j]=a[1-ii][j-1]; 
            if (a[1-ii][j]>a[ii][j]) a[ii][j]=a[1-ii][j]; 
            if (j<k&&a[1-ii][j+1]>a[ii][j]) a[ii][j]=a[1-ii][j+1]; 
        } 
        while (temp<n&&t[temp]==i) 
        { 
            if(s[temp]<=i) 
                a[ii][s[temp]]+=p[temp]; 
            temp++; 
        } 
        ii=1-ii; 
    } 
    max=0; 
    for(i=0;i<=k;i++) 
        if(max<a[1-ii][i]) max=a[1-ii][i]; 
    cout<<max<<endl; 

    return 0;
} 

