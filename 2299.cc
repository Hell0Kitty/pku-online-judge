#include <iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MAX  500010
#define LL long long
using namespace std;
int num[MAX],tree[MAX];
int n;
LL ans=0;
struct node
{
    int value,sum;
};
node arr[MAX];
int lowbit(int value)
{
    return value&(-value);
}
void build(int value)
{
  while(value<=n){
    tree[value]+=1;
    value+=lowbit(value);
  }
}
int Get_sum(int value)
{
    int result=0;
  for(int i=value;i>=1;i-=lowbit(i))
    {
        result+=tree[i];
    }
    return result;
}
bool cmp(node n1,node n2)
{
    return n1.value<n2.value;
}
int main()
{
 while(scanf("%d",&n)==1 && n)
    {
        ans=0;
        memset(tree,0,sizeof(tree));
        for(int i=1;i<=n;i++) scanf("%d",&arr[i].value),arr[i].sum=i;
        sort(arr+1,arr+n+1,cmp);
        for(int i=1;i<=n;i++)
        {
            num[arr[i].sum]=i;
        }
        for(int i=1;i<=n;i++)
        {
            build(num[i]);
            ans+=i-Get_sum(num[i]);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}



