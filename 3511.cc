#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[1100000] , check[1100000] , top ;
void f()
{
    top = 0 ;
    memset(check,0,sizeof(check));
    int i , j ;
    for(i = 2 ; i <= 1000000 ; i++)
    {
        if( !check[i] )
            a[top++] = i ;
        for(j = 0 ; j < top ; j++)
        {
            if( i*a[j] > 1000000 )
                break;
            check[i*a[j]] = 1 ;
            if(i%a[j]==0)
                break;
        }
    }
}
int main()
{
    int i , j , l ,r , x , y ;
    f();
    while(scanf("%d %d", &l, &r)!=EOF)
    {
        if(l == -1 && r == -1)
            break;
        x = 0 ; y = 0 ;
        for(i = 0 ; i < top ; i++)
        {
            if(a[i] > r)
            break;
            if( a[i] >= l )
            {
                x++ ;
                if( a[i] == 2 )
                    y++ ;
                else if( (a[i]-1)%4==0 )
                    y++ ;
            }
        }
        printf("%d %d %d %d\n", l , r , x , y);
    }
    return 0;
}



