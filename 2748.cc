 #include <iostream>
 
 using namespace std;
 
 int first[2]={1,1};
 int trans[2][2]={{3,-1},{1,0}};
 __int64 tmp[31][2][2];
 __int64 p[31];
 int e[31];
 int a[10000000];
 
 void init()
 {
     p[0]=1;
     int i,j;
     for(i=1;i<=30;i++) p[i]=2*p[i-1];
     tmp[0][0][0]=3,tmp[0][0][1]=-1,tmp[0][1][0]=1,tmp[0][1][1]=0;
     for(i=1;i<=30;i++){
         tmp[i][0][0]=(tmp[i-1][0][0]*tmp[i-1][0][0]+tmp[i-1][0][1]*tmp[i-1][1][0])%100000;
         tmp[i][0][1]=(tmp[i-1][0][0]*tmp[i-1][0][1]+tmp[i-1][0][1]*tmp[i-1][1][1])%100000;
         tmp[i][1][0]=(tmp[i-1][1][0]*tmp[i-1][0][0]+tmp[i-1][1][1]*tmp[i-1][1][0])%100000;
         tmp[i][1][1]=(tmp[i-1][1][0]*tmp[i-1][0][1]+tmp[i-1][1][1]*tmp[i-1][1][1])%100000;
     }
     a[0]=1;
     a[1]=1;
     for(i=2;i<10000000;i++){
         a[i]=(3*a[i-1]-a[i-2]+200000)%100000;
     }
 }
 
 int solve(int n)
 {
     memset(e,0,sizeof(e));
     int nn=n;
     int i=0;
     while(nn!=0){
         int x=nn%2;
         nn/=2;
         e[i++]=x;
     }
     __int64 res[2][2]={{1,0},{0,1}},t[2][2];
 
     for(i=0;i<=30;i++){
         if(e[i]){
             t[0][0]=res[0][0]*tmp[i][0][0]+res[0][1]*tmp[i][1][0];
             t[0][1]=res[0][0]*tmp[i][0][1]+res[0][1]*tmp[i][1][1];
             t[1][0]=res[1][0]*tmp[i][0][0]+res[1][1]*tmp[i][1][0];
             t[1][1]=res[1][0]*tmp[i][0][1]+res[1][1]*tmp[i][1][1];
             res[0][0]=t[0][0]%100000,res[0][1]=t[0][1]%100000,res[1][0]=t[1][0]%100000,res[1][1]=t[1][1]%100000;
         }
     }
     
     int ans=(res[0][0]+res[0][1]+200000)%100000;
     printf("%d\n",ans);
     return ans;
 }
 
 int main()
 {
     //printf("%d\n",(-11)%10);
     init();
     int t,n;
     /*
     scanf("%d",&t);
     while(t--){
         scanf("%d",&n);
         if(n<10000000) printf("%d\n",a[n]);
         else solve(n-1);
     }
     */
     int x,y;
     for(int i=2;i<2000000000;i++){
         if(i<10000000) {x=y,y=a[i];}
         else {x=y;y=solve(i-1);}
         if(x==1 && y==1){printf("period=%d\n",i);break;}
     }
     return 1;
 }

