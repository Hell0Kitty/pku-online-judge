#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct
{
    long x,y;
    long L;
}point;

point zero = {0, 0};
point p[1005];

int cross( point p0, point p1 , point p2)
{
    int t = ( p1.x -p0.x ) * ( p2.y -p0.y ) -( p2.x -p0.x ) * ( p1.y -p0.y);
    if ( t > 0 )
        return 1;
    if ( t < 0 )
        return -1 ;
    return 0 ;
}
bool cmp(point a , point b )
{
    return cross( zero , a, b ) < 0;//按斜率降序排列
}
int main()
{
    long n , i , j , count;
    point tmp1 , tmp2;
    scanf("%ld", &n) ;
    for ( i = 0 ; i < n; i ++)
    {
        scanf("%ld %ld %ld" , &p[i].x, &p[i].y , &p[i].L);
        p[i].y += p[i].L;
    }
    sort(p, p + n, cmp);
    count = 0 ;
    for ( i = 0 ; i < n; i ++)
    {
        tmp1 = p[i] ;
        for ( j = 0 ; j < n; j ++)
        {
            if ( p[i].x + p[i].y <= p[j].x + p[j].y )
                continue;

            tmp2.x = p[j].x + p[j].L ;
            tmp2.y = p[j].y -p[j].L;
            int t1 = cross(zero, p[j] , tmp1 ) ;
            int t2 = cross(zero, tmp2, tmp1 ) ;
            if ( t1 != t2 )//不等的情况必然有覆盖
                tmp1 = tmp2;
            else if(t1 > 0)
                break;//由于按斜率降序排序，第j的点斜率都小于tmp1，那么后面的必然小于
        }
        tmp2.x = p[i].x + p[i].L ;
        tmp2.y = p[i].y - p[i].L ;
        if ( cross(zero, tmp2, tmp1 )> 0 )
            count ++;
    }
    printf("%ld\n", count) ;

    return 0;
}



