#include <iostream>
using namespace std;

int main()
{
    int a[105][105],b[105],c[105],i,j,n,sum;

    while(cin >> n,n)
    {
        for(i = 0; i<n; i++)
        {
            for(j = 0; j<n; j++)
            {
                cin >> a[i][j];
            }
        }
        int cnt = 0;
        for(i = 0; i<n; i++)
        {
            b[i] = 0;
            for(j = 0; j<n; j++)
            {
                b[i]+=a[i][j];
            }
        }
        for(i = 0; i<n; i++)
        {
            c[i] = 0;
            for(j = 0; j<n; j++)
            {
                c[i]+=a[j][i];
            }
        }
        int sum1=0,sum2 = 0,flag1,flag2;
        for(i = 0; i<n; i++)
        {
            if(b[i]%2)
            {
                sum1++;
                flag1 = i;
            }
        }
        for(i = 0; i<n; i++)
        {
            if(c[i]%2)
            {
                sum2++;
                flag2 = i;
            }
        }
        if(sum1 > 1 || sum2>1)
            cout << "Corrupt" << endl;
        else if(!sum1 && !sum2)
            cout << "OK" << endl;
        else
            cout << "Change bit (" << flag1+1 << "," << flag2+1 << ")" << endl;
    }

    return 0;
}


