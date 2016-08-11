#include<iostream>
#include<stdio.h>

#define FOR(i,l,r) for (i=l;i<=r;i++)
#define CUT(i,j) (((i)>>(j))&1)

using namespace std;

int ca,sa;
char ch[10][50];
int bit[10][10],a[10],d[10];
bool q[10];

bool init() {
	#define M(a) memset(a,0,sizeof(a))
	int i,j,k,sum=0;
	FOR(i,0,5) FOR(j,0,41) 
		sum+=(ch[i][j]=='X');
	if (sum!=6*6*6-4*4*4) return 0;
	M(bit);M(q);
	FOR(i,0,5) FOR(j,0,5) {
 		bit[i][0]|=(ch[0  ][i*7+j  ]=='X')<<j;
		bit[i][1]|=(ch[j  ][i*7+5  ]=='X')<<j;
		bit[i][2]|=(ch[5  ][i*7+5-j]=='X')<<j;
		bit[i][3]|=(ch[5-j][i*7    ]=='X')<<j;
	}
	FOR(i,0,5) FOR(j,0,5) {
		bit[i][4]|=CUT(bit[i][0],5-j)<<j;
		bit[i][5]|=CUT(bit[i][3],5-j)<<j;
		bit[i][6]|=CUT(bit[i][2],5-j)<<j;
		bit[i][7]|=CUT(bit[i][1],5-j)<<j;
	}
	return 1;
}

int chobit(int k1,int k2) {
	int ans=0,i;
	FOR(i,0,5) ans|=(CUT(k1,0+i)&&CUT(k2,5-i))<<i;
	return ans;
}

bool bor_check(int pos) {
	if (!pos) return 1;pos%=4;
	int o1=(pos+3)%4,o2=(pos+4)%4;
	int k1=(d[o1]+1)%4+d[o1]/4*4;
	int k2=(d[o2]+3)%4+d[o2]/4*4;
	k1=bit[a[o1]][k1];
	k2=bit[a[o2]][k2];
	return !chobit(k1,k2);
}

bool top_check() {
	int i,j,k,k1,k2;
	if (!bor_check(4)) return 0;
	FOR(i,1,5) if (!q[i]) {
		FOR(j,0,7) {
			FOR(k,0,3) {
				k1=(j+k   )%4+j   /4*4;
				k2=(d[k]+2)%4+d[k]/4*4;
				k1=bit[i   ][k1];
				k2=bit[a[k]][k2];
				if (chobit(k1,k2)) break;
			}
			if (k>3) return 1;
		}
		return 0;
	}
	return 0;
}

bool bot_check(int pos) {
	if (pos>=4) return top_check();
	FOR(a[pos],1,5) if (!q[a[pos]]) {
		q[a[pos]]=1;
		FOR(d[pos],0,7)
			if (!(bit[a[pos]][d[pos]]&bit[0][pos]) && bor_check(pos))
				if (bot_check(pos+1)) return 1;
		q[a[pos]]=0;
	} 
	return 0;
}

int main() {
	int i,j,k;
	for (scanf("%d",&ca);ca;ca--) {
		FOR(i,0,5) {
			getchar();
			FOR(j,0,41) scanf("%c",&ch[i][j]);
		}
		getchar();
		printf("Scenario #%d:\n",++sa);
		if (init() && bot_check(0)) printf("Yes\n\n");
			else                printf("No\n\n");
	}
	return 0;
}


