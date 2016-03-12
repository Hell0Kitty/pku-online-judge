#include <iostream> 
#include <cstdlib> 
#include <stdio.h> 
using namespace std; 
int a[1010]; 
int b[1010]; 
int c[1010]; 
int n,m; 
int _count; 
void solve() 
{ 
    while(1) 
    { 
        for(int i=1;i<=n;i++) 
        { 
            b[i]=c[c[i]]; 
        } 
        _count++; 
        int j; 
        for(j=1;j<=n;j++) 
        { 
            if(b[j]!=a[j]) 
            break; 
        } 
        if(j>n) break; 
        for(int i=1;i<=n;i++) 
        c[i]=b[i]; 
    } 
} 
int main() 
{ 
    while(scanf("%d%d",&n,&m)!=EOF) 
    { 
        for(int i=1;i<=n;i++) 
        { 
            scanf("%d",&a[i]);c[i]=a[i]; 
        } 
        if(n==1) 
        { 
            printf("%d\n",a[1]); 
            continue; 
        } 
        _count=0; 
        solve(); 
        //cout<<_count<<endl; 
        m=m%_count; 
        m=_count-m; 
        int q=0; 
        while(q<m) 
        { 
            for(int i=1;i<=n;i++) 
            b[i]=a[a[i]]; 
            for(int i=1;i<=n;i++) 
            a[i]=b[i]; 
            q++; 
        } 
        for(int i=1;i<=n;i++) 
        cout<<b[i]<<endl; 
    } 
} 

