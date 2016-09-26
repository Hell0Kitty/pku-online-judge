#include<stdio.h>
#include<math.h>
struct node
{
	double x;
	double y;
}p[105];
const double PI = acos(-1.0);
double dis(int a,int b)
{
	double c = p[a].x - p[b].x,d = p[a].y - p[b].y;
	return sqrt(c*c+d*d);
} 
int main()
{
	int i,n;
	double r,result;
	while(~scanf("%d%lf",&n,&r))
	{
		result = 0.0;
		for(i = 1;i <= n;i ++)
		  scanf("%lf%lf",&p[i].x,&p[i].y);
		for(i = 2;i <= n;i ++)
		  result += dis(i-1,i);
		result += dis(1,n);
		result += 2*PI*r; 
	    printf("%.2f\n",result);
	}
	return 0;
}



