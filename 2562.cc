#include <cstdio>

int main(int argc, char const *argv[])
{
	long long a,b;
	while(~scanf("%I64d%I64d", &a, &b) && a!=0 || b!=0){
		if(a<b) {
			long long tmp = a;
			a = b; b = tmp;
		}
		int ans=0, tmp=0;
		while(a!=0){
			if(a%10+b%10+tmp>9){
				++ans;
				tmp=1;
			} else {
				tmp=0;
			}
			a/=10; b/=10;
		}
		switch(ans){
			case 0 : printf("No carry operation.\n"); break;
			case 1 : printf("1 carry operation.\n");  break;
			default: printf("%d carry operations.\n", ans);
		}
	}
	return 0;
}



