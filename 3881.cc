#include <iostream>
using namespace std;
const int maxN=10024;
int n,m;
int a[maxN],b[maxN];
bool judge(int x,int y,int i)
{
	if(b[i]<=x||y<=a[i])
		return false;	
	return true;
}

int main()
{
	while(scanf("%d%d",&n,&m)==2&&(m+n)){
		for(int i=0;i<n;++i){
			scanf("%*d%*d%d%d",&a[i],&b[i]);			
			b[i]+=a[i];
		}
		while(m--){
			int x,y,cnt=0;	
			scanf("%d%d",&x,&y);
			y+=x;
			for(int i=0;i<n;++i)
				if(judge(x,y,i))	
					++cnt;
			printf("%d\n",cnt);
		}
	}
	return 0;	
}


