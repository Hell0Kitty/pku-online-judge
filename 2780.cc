#include <iostream>
using namespace std;
int main(){
int n;
while(cin>>n&&n>=2&&n<=1000){
int len=0,max=0,test=0,a[1005][2];
while(n--){
cin>>a[len][0]>>a[len][1];
len++;
} 
for(int i=0;i<=len-3;i++){
for(int j=i+1;j<=len-2;j++){
 test=0;
   for(int k=j+1;k<=len-1;k++)
     if((a[i][1]-a[j][1])*(a[j][0]-a[k][0])==(a[j][1]-a[k][1])*(a[i][0]-a[j][0]))
       test++;
     max=test>max? test:max;
}    
}
cout<<max+2<<endl;
}
return 0;
}

