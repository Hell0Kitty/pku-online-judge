#include <stdio.h>  
#include <string.h>  
#include <math.h>  
#define inf 1e9;  
int n,t,l,b;  
int map[110];  
double dps[110][110];  
double min(double a,double b){  
    return a>b?b:a;  
}  
void dp(){  
    int i,j,k;  
    memset(dps,0,sizeof(dps));  
    dps[0][0]=1;  
    for(i=1;i<=n;i++)  
        dps[0][i]=0;  
    for(i=1;i<=t;i++){  
        for(j=n-1;j>=0;j--){  
            if(!dps[i-1][j])  
                continue;  
            if(map[j]==1){  
                for(k=1;k<=6;k++){  
                    if(j+k>n)  
                        dps[i+1][2*n-j-k]+=dps[i-1][j]/6;  
                    else  
                        dps[i+1][j+k]+=dps[i-1][j]/6;  
                }  
                continue;  
            }  
            if(map[j]==2){  
                dps[i-1][0]+=dps[i-1][j];  
                continue;  
            }  
            for(k=1;k<=6;k++){  
                if(j+k>n)  
                    dps[i][2*n-j-k]+=dps[i-1][j]/6;  
                else  
                    dps[i][j+k]+=dps[i-1][j]/6;  
            }  
        }  
    }  
    double ans=0;  
    for(i=1;i<=t;i++)  
        ans+=dps[i][n];  
    printf("%.6f\n",ans);  
}  
int main(){  
    int i,j,k;  
    while(scanf("%d %d %d %d",&n,&t,&l,&b) && !(n==0 && t==0 && l==0 && b==0)){  
        memset(map,0,sizeof(map));  
        for(i=1;i<=l;i++){  
            scanf("%d",&k);  
            map[k]=1;  
        }  
        for(i=1;i<=b;i++){  
            scanf("%d",&k);  
            map[k]=2;  
        }  
        dp();  
    }  
}



