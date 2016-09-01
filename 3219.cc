#include<stdio.h>
int main()
{
	int a, b;
	while (scanf("%d%d", &a, &b) == 2) {
		printf("%d\n", (a - b) & b ? 0 : 1);
		continue;
		int c = a - b;
		int x = 0, y = 0, z = 0;
		while (a = a >> 1) {
			x += a;
		}
		while (b = b >> 1) {
			y += b;
		}
		while (c = c >> 1) {
			z += c;
		}
		if (x - y > z) printf("0\n");
		else printf("1\n");
	}
    return 0;
}



