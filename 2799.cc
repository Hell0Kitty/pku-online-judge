#include <cstdio>
#define MAX	1005

int main()
{
	unsigned n, i, a, b, c, d, ip, net;
	int len;
	while(scanf("%u", &n) == 1){
		scanf("%u.%u.%u.%u", &a, &b, &c, &d);
		net = a << 24 | b << 16 | c << 8 | d;
		len = 32;
		for(i = 1; i < n; ++i){
			scanf("%u.%u.%u.%u", &a, &b, &c, &d);
			ip = a << 24 | b << 16 | c << 8 | d;
			int b = 31;
			for(; b >= 32-len; --b){
				if((net & (1u << b)) ^ (ip & (1u << b))) break;
			}
			len = 31 - b;
		}
		unsigned mask = 0;
		for(int b = 31; b >= 32-len; --b) mask |= 1 << b;
		net &= mask;
		printf("%u.%u.%u.%u\n", net >> 24 & 255, net >> 16 & 255, net >> 8 & 255, net & 255);
		printf("%u.%u.%u.%u\n", mask >> 24 & 255, mask >> 16 & 255, mask >> 8 & 255, mask & 255);
	}
	return 0;
}



