#include <cstdio>
#include <cmath>
#include <algorithm>
#define vector point
using std::sort;
using std::swap;
using std::max;
const double PI = acos(-1.00);
struct point
{
    int x,y;
    point(int xx = 0,int yy = 0)
    {
        x = xx;
        y = yy;
    }
    point operator - (point s)
    {
        return point(x - s.x, y - s.y);
    }
    double len()
    {
        return sqrt(x * x + y * y + 0.0);
    }
    int len2()
    {
        return x * x + y * y;
    }
};

point p[50010];
int n,l,hull_list[50010];

int cross_product(vector v1,vector v2)
{
    return v1.x * v2.y - v1.y * v2.x;
}

bool cmp(point& a,point& b)
{
    int cp = cross_product(vector(a - p[0]),vector(b - p[0]));
    if(cp > 0 || (cp == 0 && vector((a - p[0])).len2() < vector((b - p[0])).len2() ) )
        return true;
    else
        return false;
}

//基点取p[0]，逆时针扫描，返回凸包上的点数
int Graham_scan()
{
    int top = 1;
    sort(p + 1,p + n,cmp);
    hull_list[0] = 0;
    hull_list[1] = 1;
    for(int i = 2;i < n;i++)
    {
        while(top >= 1 && cross_product(vector(p[hull_list[top]] - p[hull_list[top - 1]]),vector(p[i] - p[hull_list[top]])) <= 0)//<=为一条边上只留两个顶点，<则为一条边上可以留多个顶点
            top--;
        hull_list[++top] = i;
    }
    return top + 1;
}

//旋转卡壳求最远点对的距离的平方，p[]的大小要比n的最大值多2,凸包点集的顺序为逆时针
int rotating_caliper(point p[],int& n)
{
    int counter = 0,dis = 0;
    p[n] = p[0];
    p[n + 1] = p[1];
    int j = 2;
    for(int i = 0;i < n;i++)
    {
        while(cross_product(p[i + 1] - p[i],p[j] - p[i]) < cross_product(p[i + 1] - p[i],p[j + 1] - p[i]))
            j = (j + 1) % n;
        dis = max(max((p[i] - p[j]).len2(),(p[i + 1] - p[j]).len2()),dis);
    }
    return dis;
}

int main()
{
    while(~scanf("%d",&n))
    {
        int lowest = 0;
        for(int i = 0;i < n;i++)
        {
            scanf("%d%d",&p[i].x,&p[i].y);
            if(p[lowest].y > p[i].y || (p[lowest].y == p[i].y && p[lowest].x > p[i].x))
                lowest = i;
        }
        swap(p[lowest],p[0]);
        l = Graham_scan();
        for(int i = 0;i < l;i++)
            p[i] = p[hull_list[i]];
        printf("%d\n",rotating_caliper(p,l));
    }
    return 0;
}



