#include <cmath>
#include <iostream>
using namespace std;

#define eps 0.00000005
#define PI acos(-1.0)  // PI用反三角函数比较准确

int main()
{
	double s;
	while ( scanf("%lf",&s) != EOF )
	{
		double v = 0.0;
		double low = 0, high = sqrt ( s / PI );
		while ( high - low > eps )
		{
			double mid1 = low + ( high - low ) / 3;
			double mid2 = high - ( high - low ) / 3;
			double v1 = PI * mid1 * mid1 * sqrt ( pow((s-PI*mid1*mid1)/(PI*mid1),2) - mid1*mid1 ) / 3;
			double v2 = PI * mid2 * mid2 * sqrt ( pow((s-PI*mid2*mid2)/(PI*mid2),2) - mid2*mid2 ) / 3;
			if ( v1 > v2 )
			{
				v = v1;
				high = mid2;
			}
			else
			{
				v = v2;
				low = mid1;
			}
		}
		double r = high;
		double h = sqrt ( pow((s-PI*r*r)/(PI*r),2) - r*r );
		printf("%.2lf\n%.2lf\n%.2lf\n", v, h, r);
	}
	return 0;
}



