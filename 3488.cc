#include <iostream>
#include <cstring>
using namespace std;
int main(){
	int l;
	while(scanf("%d",&l)!=EOF){
		char ch[1001][1001];
		char res[1001];
		for(int i=0;i<1001;i++){
			res[i]='\0';
		}
		for(int i=0;i<l;i++){
			scanf("%s",ch[i]);
		} 
		int len=strlen(ch[0]);
		int pos=0;
		for(int i=len-1;i>=0;i--){
			for(int j=l-1;j>=0;j--){
				if(ch[j][i]=='_')res[pos++]=' ';
				else if(ch[j][i]=='\\')res[pos++]='\n';
				else res[pos++]=ch[j][i];
			}
		}
		for(int i=pos-1;res[i]==' ';i--){
			res[i]='\0';
		}
		printf("%s\n\n",res);
	}
	return 0;
}


