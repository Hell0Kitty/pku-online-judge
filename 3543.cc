#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int b, w;
	int size;

	while(2 == scanf("%d %d", &b, &w))
	{
		if(b == 0 && w == 0 )
		{
			printf("Impossible\n");
		}
		else
		{
			if(w == b)
			{
				size = (int)sqrt(double(w+b)); //这边也要注意！
			}
			else 
			{
				size = (int)sqrt(double(2 * (b > w ? w : b) + 1)); 
			}
			printf("%d\n", size);
		}
	}

	return 0;
}



