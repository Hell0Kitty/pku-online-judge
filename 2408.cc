#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define N 30005
struct Node{
	char a[100];
	char b[100];
}	p[N];

bool operator < (const Node &x,const Node &y){
	int tmp=strcmp(x.a,y.a);
	if(tmp==0) return strcmp(x.b,y.b)<0;
	else return tmp<0; 
}
struct Ans{
	int pos;
	int num;
}	q[N];
bool operator < (const Ans &x,const Ans &y){
	return x.num>y.num||x.num==y.num&&strcmp(p[x.pos].b,p[y.pos].b)<0;
}
int main(){
	int n,m;
	int i,j;
	n=m=0;
	while(gets(p[n].a)){
		strcpy(p[n].b,p[n].a);
		int len=strlen(p[n].a);
		sort(p[n].a,p[n].a+len);
		n++;
	}	
	sort(p,p+n);
	for(i=0;i<n;){
		q[m].pos=i;
		q[m].num=1;
		while(i+q[m].num<n&&strcmp(p[i].a,p[i+q[m].num].a)==0) 
			q[m].num++;
		i+=q[m].num;
		m++;
	}
	sort(q,q+m);
	int cnt=0;
	for(i=0;i<m;i++){
		printf("Group of size %d: ",q[i].num);
		for(j=0;j<q[i].num;++j)
			if(strcmp(p[q[i].pos+j].b,p[q[i].pos+j-1].b)!=0)
				printf("%s ",p[q[i].pos+j].b);
		printf(".\n");
		if(++cnt==5) break;
	}
	return 0;
}



