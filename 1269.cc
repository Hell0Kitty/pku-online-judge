#include <iostream>
#include <cstdio>
using namespace std;

struct Point
{
    double    x,y;
};

class Line
{
public:
    Point    pointa,pointb,pointk;
    void    makeline(Point pointa,Point pointb);
};

void Line::makeline(Point a,Point b)
{
    pointa=a;
    pointb=b;
    pointk.x=pointa.x-pointb.x;
    pointk.y=pointa.y-pointb.y;
    if (pointk.x<0)
    {
        pointk.x=-pointk.x;
        pointk.y=-pointk.y;
    }
}

int        T;
Line    line1,line2;

void init()
{
    Point    a,b;

    cin>>a.x>>a.y>>b.x>>b.y;
    line1.makeline(a,b);
    cin>>a.x>>a.y>>b.x>>b.y;
    line2.makeline(a,b);
}

int    cross(Line line1,Line line2)
{
    if (!(line1.pointk.x*line2.pointk.y==line1.pointk.y*line2.pointk.x))
        return 0;                                                                                            //相交
    if (line1.pointk.y*(line2.pointb.x-line1.pointb.x)==(line2.pointb.y-line1.pointb.y)*line1.pointk.x)
        return 1;                                                                                            //重合
    return 2;                                                                                                //平行
}

double xmulti(Point p0, Point p1, Point p2)
{
    return ((p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y));
}

Point crosspoint(Line line1,Line line2)
{
    double s1 = xmulti(line1.pointa, line1.pointb, line2.pointa);
    double s2 = xmulti(line1.pointa, line1.pointb, line2.pointb);
    Point ret;
    ret.x = (s1 * line2.pointb.x - s2 * line2.pointa.x) / (s1 - s2);
    ret.y = (s1 * line2.pointb.y - s2 * line2.pointa.y) / (s1 - s2);
    return ret;
}

void work()
{
    int        ans;
    Point    pointans;

    ans=cross(line1,line2);
    switch (ans)
    {
    case    0    :
        pointans=crosspoint(line1,line2);
        printf("POINT %.2f %.2f\n",pointans.x,pointans.y);
        break;
    case    1    :
        cout<<"LINE\n";
        break;
    case    2    :
        cout<<"NONE\n";
        break;
    }
}

int main()
{
    cin>>T;
    cout<<"INTERSECTING LINES OUTPUT\n";
    while (T--)
    {
        init();
        work();
    }
    cout<<"END OF OUTPUT\n";
    return 0;
}


