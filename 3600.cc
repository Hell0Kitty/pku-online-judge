#include <cstdio>
#include <cstring>

int b[20][20];
bool choose[20];
int a[20];
int bb[20];
int r,c,R,C;

bool check() {
	int i,j;
	for (i=0;i<R;i++) {
		int o=0;
		for (j=0;j<C;j++) {
			if (choose[j])
				o=(o<<1)+b[i][j];
		}
		bb[i]=o;
	}
	i=j=0;
	while (i<r&&j<R) {
		if (a[i]==bb[j]) i++;
		j++;
	}
	if (i==r) return true;
	return false;
}
bool haveAns(int i,int res,int hav) {
	if (hav==c)
		if (check()) return true;
		else return false;
	for (;i+res<=C;i++) {
		choose[i]=true;
		if (haveAns(i+1,res-1,hav+1)) return true;
		choose[i]=false;
	}
	return false;
}

int main() {
	int i,j;
	scanf("%d%d",&r,&c);
	for (i=0;i<r;i++) {
		int o=0;
		for (j=0;j<c;j++) {
			char x;
			scanf(" %c",&x);
			o=(o<<1)+(x-'0');
		}
		a[i]=o;
	}
	memset(choose,0,sizeof(choose));
	scanf("%d%d",&R,&C);
	for (i=0;i<R;i++) {
		for (j=0;j<C;j++) {
			char x;
			scanf(" %c",&x);
			b[i][j]=x-'0';
		}
	}
	if (haveAns(0,c,0)) printf("Yes\n");
	else printf("No\n");
	return 0;
}



