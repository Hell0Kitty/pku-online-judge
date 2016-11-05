#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int N=2002;
struct m_point{
    int x,y;
};
int n;
m_point p[N];
bool cmp(const m_point &p1,const m_point &p2)
{
    if(p1.x < p2.x)
        return true;
    if((p1.x == p2.x) && (p1.y < p2.y))
        return true;
    return false;
}
bool find_point(m_point &t)
{
    int left=0,right=n,mid;
    while(left<=right)
    {
        mid=(left+right)>>1;
        if((p[mid].x == t.x) && (p[mid].y == t.y))
            return true;
        if(cmp(t,p[mid]))
            right=mid-1;
        else
            left=mid+1;
    }
    return false;
}

int main()
{
    int i,j,ans;
    m_point tmp,new_node;
    while(scanf("%d",&n) != EOF)
    {
        for(i=0;i<n;++i)
            scanf("%d%d",&p[i].x,&p[i].y);
        sort(p,p+n,cmp);
        ans=0;
        for(i=0;i<n;++i)
        {
            for(j=i+1;j<n;++j)
            {
                tmp.x=p[j].x-p[i].x;
                tmp.y=p[j].y-p[i].y;
                new_node.x=p[i].x+tmp.y;
                new_node.y=p[i].y-tmp.x;
                if(!find_point(new_node))
                    continue;
                new_node.x=p[j].x+tmp.y;
                new_node.y=p[j].y-tmp.x;
                if(!find_point(new_node))
                    continue;
                ++ans;
            }
        }
        printf("%d\n",ans/2);
    }
    return 0;
}


