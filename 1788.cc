#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct data
{
    int x,y;
}po[101000];
bool compx(data a,data b)
{
    return (a.x!=b.x)?a.x<b.x:a.y<b.y;
}
bool compy(data a,data b)
{
    return (a.y!=b.y)?a.y<b.y:a.x<b.x;
}
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        for(int i=0;i<n;i++)
            scanf("%d%d",&po[i].x,&po[i].y);
        int ans=0;
        sort(po,po+n,compx);
        for(int i=0;i<n-1;i+=2)
            ans+=po[i+1].y-po[i].y;
        sort(po,po+n,compy);
        for(int i=0;i<n-1;i+=2)
            ans+=po[i+1].x-po[i].x;
        printf("The length of the fence will be %d units.\n",ans);
    }
    return 0;
}



