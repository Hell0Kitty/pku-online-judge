#include <cstdio>
using namespace std;
int main(){
	int nCase;
	scanf("%d",&nCase);
	while(nCase--){
		int max=0,min=200,n,a;
		scanf("%d",&n);
		while(n--){
			scanf("%d",&a);
			if(a>max)max=a;
			if(a<min)min=a;	
		}
		printf("%d\n",2*(max-min));
	}
	return 0;
}



