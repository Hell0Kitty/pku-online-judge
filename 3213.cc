#include <iostream>
#include <cstdio>
using namespace std;
#define N 1001
int a[N][N],b[N][N],c[N][N];
int c_col[N],b_col[N];
int main()
{
    int n,m,p,i,j,k;

    while(scanf("%d%d%d",&n,&m,&p)!=EOF){
            for( i=0;i<n;i++){
                for( j=0;j<m;j++){
                        scanf("%d",&a[i][j]);

                }
            }
            for( i=0;i<m;i++){
                for( j=0;j<p;j++){
                    scanf("%d",&b[i][j]);
                }
            }
            for( i=0;i<n;i++){
                for( j=0;j<p;j++){
                    scanf("%d",&c[i][j]);
                }
            }
            for(i=0;i<m;i++){
                b_col[i]=0;
                for(j=0;j<p;j++){
                    b_col[i]+=b[i][j];
                }
            }
            for(i=0;i<n;i++){
                c_col[i]=0;
                for(j=0;j<p;j++){
                    c_col[i]+=c[i][j];
                }
            }
            for(i=0;i<n;i++){
                    int tmp=0;
                for(j=0;j<m;j++){
                    tmp+=a[i][j]*b_col[j];
                }
                if(tmp!=c_col[i]){
                    break;
                }
            }
            if(i==n){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
                for(j=0;j<p;j++){
                   int res=0;
                   for(k=0;k<m;k++){
                        res+=a[i][k]*b[k][j];
                   }
                   if(res!=c[i][j]){
                       cout<<i+1<<" "<<j+1<<endl;
                       cout<<res<<endl;
                       break;
                   }
                }

            }

    }
    return 0;
}



