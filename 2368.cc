#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    int k,i,ans,n;
    while(cin >> k)
    {
        ans = -1;
        if(k % 3 == 0)
        {
            cout<<"2"<<endl;
            continue;
        }
        if(k % 4 == 0)
        {
            cout<<"3"<<endl;
            continue;
        }
        while(k % 2 == 0)
        {
            k /= 2;
        }
        n = sqrt(k + 0.0);
        ans = k - 1;
        for(i = 4; i <= n + 1; i++)
        {
            if(k % i == 0)
            {
                ans = i - 1;
                break;
            }
        }
        cout << ans <<endl;
    }
    return 0;
}



