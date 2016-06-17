#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
#define eps 10e-8

struct point
{
    double x, y;
};

int num, n;
vector<int>v[27];

 //以下是汝的黑书求两线段模板 （极少部分名称被我修改过）
double crossdet(double x1, double y1, double x2, double y2)
{
    return x1 * y2 - x2 * y1;
}
double cross(point o, point a, point b)
{
    return crossdet(a.x - o.x, a.y - o.y, b.x - o.x, b.y - o.y);
}
double dotdet(double x1, double y1, double x2, double y2)
{
    return x1 * x2 + y1 * y2;
}
double dot(point o, point a, point b)
{
    return dotdet(a.x - o.x, a.y - o.y, b.x - o.x, b.y - o.y);
}
int dblcmp(double d)
{
    if( fabs(d) < eps)return 0;
    return d > 0 ? 1 : -1;
}
int between(point a, point b, point c)
{
    return dblcmp( dot(a, b, c));
}
int seg_cross(point a, point b, point c, point d)
{
    double s1, s2, s3, s4;
    int d1, d2, d3, d4;
    d1 = dblcmp (s1 = cross(a, b, c));
    d2 = dblcmp (s2 = cross(a, b, d));
    d3 = dblcmp (s3 = cross(c, d, a));
    d4 = dblcmp (s4 = cross(c, d, b));
    if( (d1 ^ d2) == -2 && (d3 ^ d4) == -2)return 1;
    if( d1 == 0 && between(c, a, b) <= 0
     || d2 == 0 && between(d, a, b) <= 0
     || d3 == 0 && between(a, c, d) <= 0
     || d4 == 0 && between(b, c, d) <= 0)return 1;
    return 0;
}

struct node
{
    char no[4], kind[15], cnt;
    point p[22];
}a[27];

bool cmp(node a, node b)
{
    return a.no[0] < b.no[0];
}

void input()
{
    char c;
    int i, j;
    scanf("%s",a[num].kind);
    c = a[num].kind[0];
    if(c == 'p')
    {
        scanf("%d", &n);
        a[num].cnt = n + 1;
        for(i = 1; i <= n; i++)
            scanf(" (%lf,%lf)", &a[num].p[i].x, &a[num].p[i].y);
        a[num].p[n + 1].x = a[num].p[1].x;
        a[num].p[n + 1].y = a[num].p[1].y;
    }
    else if(c == 'l')
    {
        a[num].cnt = 2;
        for(i = 1; i <= 2; i++)
            scanf(" (%lf,%lf)", &a[num].p[i].x, &a[num].p[i].y);
    }
    else if(c == 't')
    {
        a[num].cnt = 4;
        for(i = 1; i <= 3; i++)
            scanf(" (%lf,%lf)", &a[num].p[i].x, &a[num].p[i].y);
        a[num].p[4].x = a[num].p[1].x;
        a[num].p[4].y = a[num].p[1].y;
    }
    else if(c == 's')
    {
        a[num].cnt = 5;
        for(i = 1; i <= 3; i += 2)
            scanf(" (%lf,%lf)", &a[num].p[i].x, &a[num].p[i].y);
        a[num].p[2].x = ( a[num].p[1].x + a[num].p[3].x + a[num].p[3].y - a[num].p[1].y) / 2.0;
        a[num].p[4].x = ( a[num].p[1].x + a[num].p[3].x - a[num].p[3].y + a[num].p[1].y) / 2.0;
        a[num].p[2].y = ( a[num].p[1].x - a[num].p[3].x + a[num].p[1].y + a[num].p[3].y) / 2.0;
        a[num].p[4].y = ( a[num].p[3].x - a[num].p[1].x + a[num].p[1].y + a[num].p[3].y) / 2.0;
        a[num].p[5].x = a[num].p[1].x;
        a[num].p[5].y = a[num].p[1].y;
    }
    else if(c == 'r')
    {
        a[num].cnt = 5;
        for(i = 1; i <= 3; i++)
            scanf(" (%lf,%lf)", &a[num].p[i].x, &a[num].p[i].y);
        a[num].p[4].x = a[num].p[1].x + a[num].p[3].x - a[num].p[2].x;
        a[num].p[4].y = a[num].p[1].y + a[num].p[3].y - a[num].p[2].y;
        a[num].p[5].x = a[num].p[1].x;
        a[num].p[5].y = a[num].p[1].y;
    }
    num++;
}

int main()
{
    int i, j, k, x;
    num = 0;
    while( scanf("%s", a[num].no ) != EOF )
    {
        if(a[num].no[0] == '.')break;
        input();
        while( scanf("%s", a[num].no ) != EOF && a[num].no[0] != '-')
        {
            input();
        }
        sort(a, a+num,cmp);
        for(i = 0; i <= 26; i++)
            v[i].clear();
        bool flag = 0;
        for(i = 0; i < num; i++)
            for(j = i + 1; j < num; j++)
            {
                for(x = 1; x < a[i].cnt; x++)
                {
                    for(k = 1; k < a[j].cnt; k++)
                    {
                        if(seg_cross(a[i].p[x], a[i].p[x+1], a[j].p[k], a[j].p[k+1]))
                        {
                            flag = 1;v[i].push_back(j);v[j].push_back(i);break;
                        }
                    }
                    if( k != a[j].cnt)break;
                }
            }    
        for(i = 0; i < num; i++)
        {
            printf("%c ",a[i].no[0]);
            int len = v[i].size();
            if(len == 0)printf("has no intersections\n");
            else if(len == 1)printf("intersects with %c\n", a[ v[i][0] ].no[0]);
            else if(len == 2)printf("intersects with %c and %c\n", a[ v[i][0] ].no[0], a[ v[i][1] ].no[0]);
            else
            {
                printf("intersects with ");
                for(j = 0; j < len - 1; j++)
                    printf("%c, ", a[ v[i][j] ].no[0]);
                printf("and %c\n",a[ v[i][len - 1] ].no[0]);
            }
        }
        puts("");
        num = 0;
    }
    return 0;
}



