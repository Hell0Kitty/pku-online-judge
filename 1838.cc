#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;

#define MAXN 20000
struct Node{
    int x,y;
    int num;
}node[MAXN];
bool cmp(const Node& a, const Node& b)
{
    if(a.x == b.x) return a.y<b.y;
    return a.x<b.x;
}
bool cmp1(const Node& a,const Node& b)
{
    if(a.y == b.y) return a.x<b.x;
    return a.y < b.y;
}
bool cmp2(const int& a,const int& b)
{
    return a<b;
}
int pre[MAXN];
int find_set( int x)
{
    int root = x;
    int tmp;
    while(pre[root]>=0)
        root = pre[root];
    while(x!=root)
    {
        tmp = pre[x];
        pre[x] = root;
        x = tmp;
    }
    return root;
}
void union_set(const int& root1,const int& root2)
{
    int a = pre[root1];
    int b = pre[root2];
    if(a > b)
    {
        pre[root1] = root2;
        pre[root2] = a+b;
    }else
    {
        pre[root2] = root1;
        pre[root1] = a+b;
    }
}
int main()
{
    int n,m,i,j,k;
    int root1,root2;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        memset(pre,-1,sizeof(pre));
        for(i = 0;i < n; ++i)
        {
            scanf("%d%d",&node[i].x,&node[i].y);
            node[i].num = i;
        }
        sort(node,node+n,cmp);
        for(i = 0;i < n-1; ++i)
            if(node[i].x == node[i+1].x && node[i+1].y-node[i].y==1)
            {
                root1 = find_set(node[i].num);
                root2 = find_set(node[i+1].num);
                if(root1 != root2)
                    union_set(root1,root2);
            }
        sort(node,node+n,cmp1);
        for(i = 0;i < n-1; ++i)
            if(node[i].y == node[i+1].y && node[i+1].x-node[i].x==1)
            {
                root1 = find_set(node[i].num);
                root2 = find_set(node[i+1].num);
                if(root1 != root2)
                    union_set(root1,root2);
            }
        sort(pre,pre+n,cmp2);
        int ans = 0;
        for(i = 0; i < k;++i)
            ans -= pre[i];
        printf("%d\n",ans);
    }
    return 0;
}



