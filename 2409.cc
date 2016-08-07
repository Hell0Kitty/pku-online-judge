#include<cstdio>
#include<iostream>
using namespace  std;
int ans;
int fun(int x,int n)
{
    if(n==0)
    {
        ans=1;
        return ans;
    }
    if(n==1)
    {
        ans=x;
        return ans;
    }
    fun(x,n>>1); //浜屽垎
    ans=ans*ans;
    if(n&1)
    {
        ans=ans*x;
        return ans;
    }
    return ans;
}
int euler(int n){
     int res=n,a=n;
     for(int i=2;i*i<=a;i++){
         if(a%i==0){
             res=res/i*(i-1);
             while(a%i==0) a/=i;
         }
     }
     if(a>1) res=res/a*(a-1);
     return res;
}
void solve(int n,int c)
{
    int ans = 0;
    for (int i = 1; i <= n; i++) if (n % i == 0)
        {
            ans += fun(c, i) * euler(n / i);
        }
    if (n & 1) ans += n * fun(c, n / 2 + 1);
    else ans += n / 2 * (fun(c, n / 2) + fun(c, n / 2 + 1));
    cout << ans / (2 * n) << endl;
}
int main()
{
    int n,c;
    while(~scanf("%d%d",&c,&n)&&n&&c)
    {
            solve(n,c);
    }
    return 0;
}



