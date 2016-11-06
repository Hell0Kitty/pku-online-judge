#include<iostream>
using namespace std;

#define inf 987654321
#define MAXN 25
int MOD,N,K;
int a[MAXN][MAXN];
int b[MAXN]; 
int ans;
int x[MAXN],fr[MAXN];

inline int tomod( int a){
return (a%MOD+MOD)%MOD;
}

void search(int row,int col,int xsum){
if( xsum>=ans ) return ;
int i;
if( row==-1 ) {
   ans=xsum;
   return ;
}
if( fr[col]==-1 ){
   for( x[col]=0;x[col]<N;++x[col] ){
    search(row,col-1,xsum+x[col]);
   }
}else {
   int sum;
   for( sum=0,i=col+1;i<K;++i ) sum=tomod(sum+a[row][i]*x[i]);
   for( x[col]=0;x[col]<N;++x[col] ){
    if( tomod( x[col]*a[row][col] + sum ) == tomod(b[row]) )
    search( row-1,col-1,xsum+x[col]);
   }
}
} 

int gauss(int a[][MAXN],int *b,int m,int n){
int i,j,k,col,t,r;
for( k=col=0;k<m && col<n;++k,++col){
   if( !a[k][col] ){
    for( r=k,i=k+1;i<m;++i){
     if( a[i][col]!=0 ){
      r=i;
      break;
     }
    }
    if( r != k ){
     for( i=col;i<n;++i ){
      t=a[r][i],a[r][i]=a[k][i],a[k][i]=t;
     }
     t=b[r],b[r]=b[k],b[k]=t;
    }
    if( !a[k][col] ) {fr[col]=-1;k--;continue;}
   }
   for( i=k+1;i<m;++i ){
    for( ;a[i][col]!=0; ){
     if( a[k][col]>a[i][col] ) {
      for( j=col;j<n;++j ){
       a[k][j]-=a[i][j];
       a[k][j]=tomod(a[k][j]);
      }
      b[k]-=b[i];
      b[k]=tomod(b[k]);
     }
     else {
      for( j=col;j<n;++j ){
       a[i][j]-=a[k][j];
       a[i][j]=tomod(a[i][j]);
      }
      b[i]-=b[k];
      b[i]=tomod(b[i]);
     }
    }
   }
}
for( i=k;i<m;++i ){
   if( b[i] ) return -1;
}
ans=inf;
search(k-1,col-1,0);
return 0;
}

int main(){
   while( scanf("%d%d",&K,&N)==2 && K ){
   memset(fr,0,sizeof(fr));
   memset(a,0,sizeof(a));
   MOD=N;
   int i,j;
   for( i=0;i<K;++i ){
    scanf("%d",&b[i]);
    b[i]=tomod(1-b[i]);
   }
   for( i=0;i<K;++i ){
    int tn;
    scanf("%d",&tn);
    for( j=0;j<tn;++j ){
     int tc,tr;
     scanf("%d%d",&tc,&tr);
     a[tc-1][i]=tr;
    }
   }
   int flag=gauss(a,b,K,K);
   if( flag==-1 || ans ==inf ) printf("No solution\n");
   else {
    printf("%d\n",ans);
   }
   }
   return 0;
}


