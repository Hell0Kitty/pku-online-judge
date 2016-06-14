#include <iostream>
using namespace std;

int fugai(int a[4],int b[4])
{
 if(a[0]>=b[0] && a[1]<=b[1] && a[2]>=b[2] && a[3]<=b[3]) return 1;
 else return 0; 
} 

int main()
{
  int a[5001][4];
  int i,j,n,s;
  while(cin>>n&&n!=0)
 {
  s=0;
  for(i=0;i<n;i++)
    for(j=0;j<4;j++)
     cin>>a[i][j];//为什么scanf("%d%d%d%d",a[i][j])不合法？ 
     for(i=0;i<n;i++)
       for(j=0;j<n;j++)
       {
        if(i==j) continue;//该行不与该行比较； 
        if( fugai(a[i],a[j])){s++;break;}//询问该行有没有被覆盖，有即加一跳出； 
       }
      cout<<s<<endl;
 }
  return 0;
}


