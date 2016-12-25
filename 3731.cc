#include <stdio.h>
#include <string.h>
#define M 100000007
#define ens(x) while(x>=M)x-=M

typedef long long LL;
int C[2048][2048];
int main(){
        int T,n,m,x,y,i,j;
        int len,r,na,nb,nc,nd;
        C[0][0] = 1;
        for (i = 1;i <= 2000;i++){
                C[i][0] = 1;
                for (j = 1;j <= i;j++){
                        C[i][j] = C[i-1][j-1]+C[i-1][j];
                        ens(C[i][j]);
                }
        }
        scanf("%d",&T);
        while (T--){
                scanf("%d%d%d%d",&n,&m,&x,&y);
                na = m-y,nb = n-x,nc = y,nd = x-1;
                len = nb < nc?nb:nc;
                if (nd < len) len = nd;
                if (na > len) len++; else len = na;
                r = 1;
                for (i = 1;i <= len;i++){
                        r += (LL)C[na][i]*C[nb][i-1] % M*C[nc][i-1] % M*C[nd][i-1] % M;
                        r += (LL)C[na][i]*C[nb][i] % M*C[nc][i-1] % M*C[nd][i-1] % M;
                        r += (LL)C[na][i]*C[nb][i] % M*C[nc][i] % M*C[nd][i-1] % M;
                        r += (LL)C[na][i]*C[nb][i] % M*C[nc][i] % M*C[nd][i] % M;
                        ens(r);
                }
                printf("%d\n",r);
        }
}



