#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 7e4+10;
int table[4][4]={6,2,4,8,//注意%4结果与数组下标一一对应
                 1,3,9,7,//3
                 1,7,9,3,//5
                 1,9,1,9,};//9
int n,m;
int getpow(int n,int p)//返回n!中质因子p的幂
{
    int q=p,res=0;
    while(n>=q){res+=n/q;q*=p;}
    return res;
}
int g(int n,int x)//小于等于n的奇数序列中x的幂（或x出现的次数）,递归实现（美妙）
{
    if(n==0) return 0;
    return n/10+(n%10>=x?1:0)+g(n/5,x);//例如g(27,3),取十位数表明之前x循环出现2次，个位7>=3表示x又出现一次
}

int f(int n,int x)//小于等于n序列中x的幂（或x出现的次数），递归实现（美妙）
{
    if(n==0) return 0;
    return f(n/2,x)+g(n,x);//偶数序列等价于f(n/2,x)奇数序列等价于g(n,x);
}
int solve()
{
   int ans=1;
   /*****先处理2^i,5^k************/
   int pow_2=getpow(n,2)-getpow(n-m,2)-getpow(m,2);
   int pow_5=getpow(n,5)-getpow(n-m,5)-getpow(m,5);
   if(pow_2<pow_5) return 5;          //如果是n!,i>k，这里是组合数不一定，要判断
   else if(pow_2==pow_5) ans=1;
   else ans*=table[0][(pow_2-pow_5)%4];
 // cout<<getpow(n,5)<<endl;
 // cout<<getpow(n-m,5)<<endl;
 //   cout<<ans<<endl;
   /*****再处理末尾3,5,9************///n!个位数除完所有2、5后末尾只可能是1,3,7,9
   int pow_3=f(n,3)-f(n-m,3)-f(m,3);pow_3=(pow_3%4+4)%4;
   int pow_7=f(n,7)-f(n-m,7)-f(m,7);
   int pow_9=f(n,9)-f(n-m,9)-f(m,9);
   ans=(ans*table[1][pow_3%4])%10;
   ans=(ans*table[2][pow_7%4])%10;
   ans=(ans*table[3][pow_9%4])%10;
   return ans;
}
int main()
{
 //  freopen("input.txt","r",stdin);
   while(cin>>n>>m){
    cout<<solve()<<endl;
   }
   return 0;
}
