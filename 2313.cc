#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
#include<map>
#include<cmath>
#include<vector>
#include<set>
using namespace std;
int f_min(int x,int y){return x<y?x:y;}
int f_max(int x,int y){return x>y?x:y;}
int f_abs(int x){return x<0?-x:x;}
int N,num[105],ans[105];
void get_data(){
	int i;
	scanf("%d",&N);
	for(i=0;i<N;i++)scanf("%d",&num[i]);
}

void run(){
	int i,res=0;
	for(i=0;i<N;i++)ans[i]=num[i];
	for(i=1;i<N-1;i++){
		if(ans[i]<ans[i-1]&&num[i]<ans[i+1]){
			ans[i]=f_min(ans[i-1],ans[i+1]);
		}
		if(ans[i]>ans[i-1]&&ans[i]>ans[i+1]){
			ans[i]=f_max(ans[i-1],ans[i+1]);
		}
	}
	for(i=0;i<N;i++)res+=f_abs(ans[i]-num[i]);
	for(i=1;i<N;i++)res+=f_abs(ans[i-1]-ans[i]);
	printf("%d\n",res);
}
int main(){
	get_data();
	run();
	return 0;
}



