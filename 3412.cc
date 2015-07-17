#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main(int argc, char *argv[])
{
	double n[105],minN;
	int k;
	double ray;
	scanf("%d",&k);
	minN = 1e100;
	for(int i=1;i<=k;i++)
	{
	    scanf("%lf",&n[i]);
	    if(n[i]<minN)
	    {
	        minN = n[i];
	    }
	}
	scanf("%lf",&ray);
	double judge = n[1] * sin(ray) / minN;
	if(judge > 1.00000000000)
	{
	    printf("NO\n");
	}
	else
	{
	    judge = asin(n[1] * sin(ray) / n[k]);
	    printf("%.3lf\n",judge);
	}
	return 0;
}



