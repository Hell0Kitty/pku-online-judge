#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
struct node
{
    int x,y,num;
    bool operator<(const node &pos) const
    {
        return x<pos.x;
    }
}data[20005];
int d,n;
map<int,int> refer;
void calbest(int nx,int &best,int &x,int &y)
{
    map<int,int>::iterator s=refer.begin(),e=refer.begin();
    int total=0,last=e->first;
    while(e!=refer.end())
    {
        while(e!=refer.end()&&e->first<=s->first+2*d)
        {
            total+=e->second;
            last=e->first;
            e++;
        }
        if(total>best||total==best&&nx-d<x||total==best&&nx-d==x&&last-d<y)
            best=total,x=nx-d,y=last-d;
        total-=s->second;
        s++;
    }
}
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d%d",&d,&n);
        for(int i=0;i<n;i++)
            scanf("%d%d%d",&data[i].x,&data[i].y,&data[i].num);
        sort(data,data+n);
        int s=0,e=0;
        refer.clear();
        int best=-1,y,x;
        while(e<n)
        {
            int tmp;
            while(true)
            {
                if(e>=n||data[e].x-data[s].x>2*d) break;
                tmp=data[e].x;
                while(e<n&&data[e].x==tmp) 
                    {
                        refer[data[e].y]+=data[e].num;
                        e++;
                    }
                calbest(data[e-1].x,best,x,y);
            }
            tmp=data[s].x;
            while(data[s].x==tmp&&s<n)
            {
                refer[data[s].y]-=data[s].num;
                if(refer[data[s].y]==0) refer.erase(data[s].y);
                s++;
            }
        }
        printf("%d %d %d\n",x>=0?x:0,y>=0?y:0,best);

    }
    return 0;
}



