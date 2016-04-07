#include<cstdio> 
#include<iostream>
using namespace std;
int a[3000000],b[3000000],n,s[3000000],h,temp,tt=0,w=0;
int solve()
{
    int l,r,mid,len=1;
    a[1]=s[1];
    for(int i=2;i<=n;i++)
    {
           l=1,r=len;
           if(a[len]<=s[i]) 
        {
            a[++len]=s[i];
            continue;
        }
           while(l<=r)
           {
            mid=(l+r)>>1;
            if(a[mid]<=s[i]) l=mid+1;
            else r=mid-1;
           }
        a[l]=s[i];
        if(l>len) len++;
    }
    return len; 
}
 void dfs(int k){
 	if(2*k+1<n)
		dfs(2*k+1);
 	if(2*k+2<n){
		tt++;
		dfs(2*k+2);
 	}
	s[++w]=b[k]-tt;
}
 int main(){
 	scanf("%d",&h);
 	while(scanf("%d",&temp)!=EOF)
		b[n++]=temp;
	dfs(0);
	printf("%d\n",n-solve());
	return 0;
 }



