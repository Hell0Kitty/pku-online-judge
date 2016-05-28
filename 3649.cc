#include<iostream>
#include<cstring>
#include<cstdio>
struct Unit{
	int w;
	char m[30][600];
};
int f_max(int x,int y){
	return x>y?x:y;
}
char map[30][600];
Unit unit[30];
int N,un;
void mapcpy(char x[30][600],int s,int e){
	int i,j;
	for(i=0;i<N;i++){
		for(j=s;j<e;j++)x[i][j-s]=map[i][j];
	}
}
void mapcpy(char x[20][600],int id){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<unit[id].w;j++)unit[id].m[i][j]=x[i][j];
	}
}
void get_data(){
	int i,ti;
	for(i=0;i<N;i++){
		gets(map[i]);
	}
	for(un=0,ti=0,i=0;map[0][i];i++){
		if(map[0][i]==' '){
			unit[un].w=i-ti;
			mapcpy(unit[un++].m,ti,i);
			ti=i+1;
		}
	}
	unit[un].w=i-ti;
	mapcpy(unit[un++].m,ti,i);
}
int l[30],r[30];
void get_left(int x){
	int i,j;
	for(i=0;i<N;i++){
		for(j=unit[x].w-1;j>=0&&unit[x].m[i][j]=='.';j--);
		if(j==-1)l[i]=-1;
		else l[i]=unit[x].w-1-j;
	}
}
void get_right(int x){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<unit[x].w;j++){
			if(unit[x].m[i][j]!='.')break;
		}
		if(j<unit[x].w)r[i]=j;
		else r[i]=-1;
	}
}
int get_move(){
	int i,vmin=-1;
	for(i=0;i<N;i++){
		if(l[i]==-1||r[i]==-1)continue;
		if(vmin==-1||vmin>l[i]+r[i])vmin=l[i]+r[i];
	}
	return vmin;
}
void f_move(int mve,int go,int come){
	char temp[20][600];
	int cs,ce,gs,ge,i,j;
	if(unit[go].w+1-mve<0){
		cs=0;ce=unit[come].w-1;
		gs=mve-unit[go].w-1;
		ge=gs+unit[go].w-1;
	}else{
		gs=0;ge=unit[go].w-1;
		cs=unit[go].w+1-mve;
		ce=cs+unit[come].w-1;
	}
	unit[come].w=f_max(ge,ce)+1;//printf("move=%d unit[come].w=%d\n",mve,unit[come].w);
	for(j=0;j<unit[come].w;j++){
		if(j>=gs&&j<=ge){
			if(j>=cs&&j<=ce){
				for(i=0;i<N;i++){
					if(unit[go].m[i][j-gs]=='.')temp[i][j]=unit[come].m[i][j-cs];
					else temp[i][j]=unit[go].m[i][j-gs];
				}
			}else{
				for(i=0;i<N;i++){
					temp[i][j]=unit[go].m[i][j-gs];
				}
			}
		}else if(j>=cs&&j<=ce){
			for(i=0;i<N;i++){
				temp[i][j]=unit[come].m[i][j-cs];
			}
		}else{
			for(i=0;i<N;i++){
				temp[i][j]='.';
			}
		}
	}
	mapcpy(temp,come);
}
bool havejj(int j){
	int i;
	for(i=0;i<N;i++){
		if(unit[un-1].m[i][j]=='#')return 1;
	}
	return 0;
}
int get_rs(){
	int i;
	for(i=0;;i++){
		if(havejj(i))return i;
	}
}
int get_re(){
	int i;
	for(i=unit[un-1].w-1;;i--){
		if(havejj(i))return i;
	}
}
void print(){
	int rs,re,i,j;
	rs=get_rs();
	re=get_re();
	for(i=0;i<N;i++){
		for(j=rs;j<=re;j++){
			if(unit[un-1].m[i][j]=='#')printf("#");
			else printf(".");
		}
		printf("\n");
	}
}
void run(){
	int i,j,move;
	for(i=0;i<un-1;i++){
		for(j=i+1;j<un;j++){
			get_left(i);
			get_right(j);
			move=get_move();
			if(move==-1)continue;
			f_move(move,i,j);
			break;
		}
	}
	print();
}
int main(){
	int cnt=0;
	while(scanf("%d",&N),N){
		getchar();
		get_data();
		printf("%d\n",++cnt);
		run();
	}
	return 0;
}


