#include <iostream>
#include <cmath>

using namespace std;
const int Y = 1960;

int main()
{
    int year;

    double sum;
    while(cin >> year)
    {
        if(year == 0)
            break;

        int tmp = pow(2*1.0,(year - Y) / 10 + 2);
        int n = 2;
        sum = 0;
        while(sum <= tmp)
        {
            sum += log(n*1.0) / log(2*1.0);
            n++;
        }
        cout << n - 2 << endl;
    }
    return 0;
}



