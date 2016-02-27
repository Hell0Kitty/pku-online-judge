#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1000010 ;
int nxt[maxn];
char s[maxn];

void getn(char *s, int *nxt) {
	int len=strlen(s);
	nxt[0]=nxt[1]=0;
	for (int i=1;i<len;i++) {
		int j=nxt[i];
		while (j&&s[i]!=s[j]) j=nxt[j];
		nxt[i+1] = s[i]==s[j] ? j+1 : 0 ;
	}
} 

int main()
{
	while (scanf("%s",s)&&s[0]!='.') {
		int len=strlen(s);
		getn(s,nxt);
		if (len%(len-nxt[len])==0)
		printf("%d\n",len/(len-nxt[len]));
		else 
		printf("1\n");
	}
	return 0;
}



