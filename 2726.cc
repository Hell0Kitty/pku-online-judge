#include<map>
#include<set>
#include<list>
#include<cmath>
#include<ctime>
#include<queue>
#include<stack>
#include<cctype>
#include<cstdio>
#include<string>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	int d,c;
}a[10005];
bool cmp(node a,node b){
	if(a.d!=b.d)
		return a.d<b.d;
	else return a.c<b.c;
}
int main(){
	int n;
	while(cin>>n && n){
		for(int i=0;i<n;i++)
			scanf("%d%d",&a[i].d,&a[i].c);
		sort(a,a+n,cmp);
		int cnt=0,min=999999;
		for(int i=0;i<n;i++){
			if(a[i].c<min){
				min=a[i].c;
				cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}



