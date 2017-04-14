#include <iostream>
#include <cmath>
using namespace std;

int        h, u, d, f,time1;
double    now, speed;

void work()
{
    while (1)
    {
        now += speed;
        if (now > h)
        {
            cout << "success on day " << time1 << endl;
            break;
        }
        now -= d;
        if (now < 0)
        {
            cout << "failure on day " << time1 << endl;
            break;
        }
        time1++;
        speed -= u * f / 100.0;
        if (speed < 0)
            speed = 0;
    }
}

int main()
{
    while (cin >> h >> u >> d >> f && h != 0)
    {
        now = 0;
        time1 = 1;
        speed = u;
        work();
    }
    return 0;
}


