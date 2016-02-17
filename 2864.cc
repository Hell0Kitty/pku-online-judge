#include <iostream>
#define MAXN 600
using namespace std;

int _m[MAXN][MAXN];

int main()
{
    int c;
    int r;
    int i;
    int j;
    int sum;

    while(cin>>c>>r,c||r)
    {

    for(i = 0; i < r; ++ i)
    {
        for(j = 0; j < c; ++ j)
        {
            cin>>_m[i][j];
        }
    }

    for(j = 0; j < c; ++ j)
    {
        sum = 0;
        for(i = 0; i < r; ++ i)
        {
            if(_m[i][j] == 0)
            {
                break;
            }
        }
        if(i == r)
        {
            cout<<"yes"<<endl;
            break;
        }
    }
    if(j == c)
    {
        cout<<"no"<<endl;
    }
    }

}



