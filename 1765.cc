#include <set>
#include <map>
#include <queue>
#include <math.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

#define eps 1e-8
#define pi acos(-1.0)
#define inf 107374182
#define inf64 1152921504606846976
#define lc l,m,tr<<1
#define rc m + 1,r,tr<<1|1
#define iabs(x)  ((x) > 0 ? (x) : -(x))
#define clear1(A, X, SIZE) memset(A, X, sizeof(A[0]) * (SIZE))
#define clearall(A, X) memset(A, X, sizeof(A))
#define memcopy1(A , X, SIZE) memcpy(A , X ,sizeof(X[0])*(SIZE))
#define memcopyall(A, X) memcpy(A , X ,sizeof(X))
#define max( x, y )  ( ((x) > (y)) ? (x) : (y) )
#define min( x, y )  ( ((x) < (y)) ? (x) : (y) )

using namespace std;

struct node
{
    int x1,x2,y1,y2;
    int num,next,w,deg;
    double k;
} segment[400005];

int n,point[400000<<1],ans[400005],q[400005],a[100];

bool cmp(node a,node b)
{
    return a.x1<b.x1;
}

int main()
{
    int last=0,now,tail=0,k,cnt,u,v,pointcnt,levelcnt;
    while(scanf("%d",&n)!=EOF)
    {
        pointcnt=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d%d%d%d",&segment[i].x1,&segment[i].y1,&segment[i].x2,&segment[i].y2);
            segment[i].num=i;
            segment[i].next=-1;
            segment[i].w=0;
            segment[i].deg=0;
            segment[i].k=(1.0*segment[i].y2-segment[i].y1)/(segment[i].x2-segment[i].x1);
            point[pointcnt++]=segment[i].x1;
            point[pointcnt++]=segment[i].x2;
        }

        sort(point,point+pointcnt);
        pointcnt=unique(point,point+pointcnt)-point;

        sort(segment,segment+n,cmp);

        last=0;
        tail=0;
        levelcnt=0;

        for(int i = 0; i < pointcnt ; last=now,i++)
        {
            now=point[i];
            if(levelcnt)
            {
                segment[a[levelcnt-1]].w+=now-last;
            }
            while(segment[tail].x1==now&&tail<n)
            {
                k=-1;
                for(int j=0; j<levelcnt; j++)
                {
                    if( (segment[a[j]].y1 + segment[a[j]].k * (now - segment[a[j]].x1))<segment[tail].y1)k=j;
                }
                for(int j=levelcnt-1; j>k; j--)
                {
                    a[j+1]=a[j];
                }
                a[k+1]=tail;
                levelcnt++;
                tail++;
            }
            for(int j=1; j<levelcnt; j++)
            {
                if((segment[a[j]].x1==now&&segment[a[j]].y1<segment[a[j]].y2)||(segment[a[j]].x2==now&&segment[a[j]].y1>segment[a[j]].y2))
                {
                    segment[a[j]].next=a[j-1];
                    segment[a[j-1]].deg++;
                }
            }
            cnt=0;
            for(int j=0; j<levelcnt; j++)
            {
                if(segment[a[j]].x2!=now)a[cnt++]=a[j];
            }
            levelcnt=cnt;
        }
        queue <int >q;
        for(int i=0; i<n; i++)
        {
            if(!segment[i].deg)q.push(i);
        }
        while(!q.empty())
        {
            u=q.front();
            q.pop();
            v=segment[u].next;
            if(v==-1)continue;
            segment[v].deg--;
            segment[v].w+=segment[u].w;
            if(!segment[v].deg)q.push(v);
        }
        for(int i=0; i<n; i++)
        {
            ans[segment[i].num]=segment[i].w;
        }

        for(int i=0; i<n; i++)
        {
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}
