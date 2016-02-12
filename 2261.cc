#include<cstdio>
#include<cstring>
double dp[6][17];
char s[17][30];
double g[17][30];
int main(){
	memset(dp,0,sizeof(dp));
	for(int i=0;i<16;i++){
		scanf("%s",s[i]);
	}
	for(int i=0;i<16;i++){
		for(int j=0;j<16;j++){
			scanf("%lf",&g[i][j]);
			g[i][j]/=100.0;
		}
	}
	for(int i=0;i<16;i++) dp[0][i]=1.0;
	for(int i=1,t=1;i<=4;i++,t=t*2){
		for(int j=0;j<16;j++){
			int k=j/t;
			if(k&1)
				k=(j/t-1)*t;
			else
			    k=(j/t+1)*t;
			for(int m=k;m<k+t;m++){
				dp[i][j]+=dp[i-1][j]*dp[i-1][m]*g[j][m];
			}
		}
	}
	for(int i=0;i<16;i++){
		printf("%-10s p=%.2lf%%\n",s[i],dp[4][i]*100.0);
	}
	return 0;
}



