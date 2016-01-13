#include<iostream>
using namespace std;

struct Node{
 double dis,speed,need;
};
Node nodes[1010];

int big,v;

int main(){
 while(scanf("%d%d",&big,&v)!=EOF){
  int number;
  scanf("%d",&number);
  if(number==0){
   printf("%d\n",big*v);
   continue;
  }
  int i;
  double need=100000000;
  for(i=1;i<=number;i++){
   scanf("%lf%lf",&nodes[i].dis,&nodes[i].speed);
   nodes[i].need=nodes[i].dis/nodes[i].speed;
   if(nodes[i].need<need){
    need=nodes[i].need;
   }
  }
  if(need>big){
   printf("%d\n",big*v);
  }else{
   if(need-(int)need==0){
    need=(int)(need-1);
    if(need==0){
     printf("0\n");
    }else{
     big=(big-need)/2+need;
     printf("%d\n",big*v);
    }
   }else{
    need=(int)need;
    if(need==0){
     printf("0\n");
    }else{
     big=(big-need)/2+need;
     printf("%d\n",big*v);
    }
   }
  }

 }

 return 0;
}



