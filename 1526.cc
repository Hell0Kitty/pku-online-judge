#include<iostream>
#include<stdio.h>

#define FOR(i,l,r) for (i=l;i<=r;i++)
#define MAXN 10100
#define MAXM 100100

using namespace std;
int ca,sa,n;

struct Link_Cut_Tree {
	int ki[MAXN][2],fa[MAXN];
	int pp[MAXN],cir[MAXN];
	void clear() {
		#define M(a) memset(a,0,sizeof(a))
		M(ki);M(fa);M(pp);M(cir);
	}
	int find_root(int now) {
		while (fa[now]) now=fa[now];
		return now;
	}
	void rotate(int now,bool kin) {
		int fp=fa[now],kp=ki[now][kin],kkp=ki[ki[now][kin]][kin^1];
		fa[now]=kp ;ki[kp ][kin^1         ]=now;
		fa[kp ]=fp ;ki[fp ][ki[fp][1]==now]=kp ;
		fa[kkp]=now;ki[now][kin           ]=kkp;
	}
	void up(int now) {
		int root=find_root(now),i1,i2;
		if (root==now) return ;
		pp[now]=pp[root];pp[root]=0;
		while (fa[now]) {
			if (!fa[fa[now]]) {
				rotate(fa[now],ki[fa[now]][1]==now);return ;
			}
			i1=(ki[fa[now]    ][1]==now    );
			i2=(ki[fa[fa[now]]][1]==fa[now]);
			if (i1^i2) {
				rotate(fa[now]    ,i1);rotate(fa[now],i2);
			} else {
				rotate(fa[fa[now]],i2);rotate(fa[now],i1);
			}
		}
		fa[0]=pp[0]=cir[0]=0;
	}		 
	void access(int now) {
		for (int pre=0;now;) {
			up(now);
			fa[ki[now][1]]=0;
			pp[ki[now][1]]=now;
			ki[now][1]=pre;
			fa[pre]=now;
			pp[pre]=0;
			pre=now;now=pp[now];
		}
		fa[0]=pp[0]=cir[0]=0;
	}
	void del(int now) {
		int i,j,k;
		access(now);up(now);
		for (i=now;ki[i][0];i=ki[i][0]) ;
		if (cir[i]) {
			if (now==i) {
				cir[i]=0;return ;
			}
			access(cir[i]);up(now);
			for (j=cir[i];fa[j] && fa[fa[j]];j=fa[j]) ;
			if (cir[i]==now || (fa[j]==now && ki[now][1]==j)) {
				pp[ki[now][0]]=cir[i];cir[i]=0;
			} else {
				access(now);up(now);
			}
		}
		fa[ki[now][0]]=0;ki[now][0]=0;
	}
	void ins(int now,int nex) {
		int i,j,k;
		access(nex);up(nex);
		for (i=now;fa[i] && fa[fa[i]];i=fa[i]) ;
		if (now==nex || (fa[i]==nex && ki[nex][0]==i)) {
			cir[now]=nex;return ;
		}
		pp[find_root(now)]=nex;
	}
	int ring(int now) {
		int i,j,k;
		access(now);up(now);
		for (i=now;ki[i][0];i=ki[i][0]) ;
		return cir[i]?9999:i;
	}
} LCT;

struct Event {
	int t,o,d;
	Event(int i1=0,int i2=0,int i3=0):
		 t(i1),o(i2),d(i3)          {}
	void update() {
		if (d==0) LCT.del(o);
			else  LCT.ins(o,d);
	}
	friend bool operator < (Event e1,Event e2) {
		return e1.t<e2.t || (e1.t==e2.t && e1.d<e2.d);
	}
} ev[MAXM];

void init() {
	LCT.clear();n=0;
}

void qsort(int l,int r) {
	int i=l,j=r;Event k=ev[(l+r)>>1];
	while (i<=j) {
		for (;k<ev[i];i++) ;
		for (;ev[j]<k;j--) ;
		if (i<=j) swap(ev[i++],ev[j--]);
	}
	if (i<r) qsort(i,r); if (j>l) qsort(l,j);
}

int main() {
	int i,j,k,S,L;
	printf("CALL FORWARDING OUTPUT\n");
	for (scanf("%d",&ca);init(),ca;ca--) {
		printf("SYSTEM %d\n",++sa);
		while (scanf("%d",&i)!=EOF && i) {
			scanf("%d%d%d",&S,&L,&j);
			ev[++n]=Event(S    ,i,j);
			ev[++n]=Event(S+L+1,i,0);
		}
		qsort(1,n);
		while (scanf("%d",&i)!=EOF && i!=9000) {
			scanf("%d",&j);
			while (n && ev[n].t<=i) 
				ev[n--].update();
			printf("AT %04d CALL TO %04d RINGS %04d\n",i,j,LCT.ring(j));
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}


