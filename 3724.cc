#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
#define MAX 25
#define M 3000
double x[MAX];
double y[MAX];
int n;
int s;
double l[M];
int path[M][5];
int a[10];
int id[M];
bool ans;
void dfs1(int i,double k){
 if(i>=5){
  int j;
  for(j=0;j<5;j++){
   path[s][j]=a[j];
  }
  l[s++]=k;
  return;
 }
 int j;
 if(i==0)j=1;
 else j=a[i-1];
 for(;j<11;j++){
  a[i]=j;
  dfs1(i+1,k+exp(j*x[0]));
 }
}
bool equal(double t1,double t2){
 int k1=(int)(t1*1000+0.5);
 int k2=(int)(t2*1000+0.5);
 return k1==k2;
}
int find(double k){
 int bottom=0,top=s-1;
 int r=-1;
 while(bottom<=top){
  int mid=(bottom+top)>>1;
  if(equal(l[id[mid]],k)){
   r=mid;
   break;
  }
  if(l[id[mid]]<k)bottom=mid+1;
  else top=mid-1;
 }
 if(r==-1)return -1;
 int j=r;
 while(j>0&&equal(l[id[j]],l[id[j-1]]))j--;
 return j;
}
void dfs2(int i,double k){
 if(ans)return;
 if(i>9){
  int j;
  int pos=find(k);
  if(pos==-1)return;
  int p;
  for(j=pos;equal(l[id[j]],k);j++){
   if(path[id[j]][4]<=a[5]){
    for(p=1;p<n;p++){
     int p1;
     double temp=0;
     for(p1=0;p1<5;p1++)temp=temp+exp(path[id[j]][p1]*x[p]);
     for(p1=5;p1<10;p1++)temp=temp+exp(a[p1]*x[p]);
     if(!equal(temp,y[p]))break;
    }
    if(p>=n){
     ans=true;
     int p1;
     for(p1=0;p1<5;p1++)cout<<path[id[j]][p1]<<endl;
     for(p1=5;p1<10;p1++)cout<<a[p1]<<endl;
     return ;
    }
   }
  }
  return;
 }
 int j;
 if(i==5)j=0;
 else j=a[i-1];
 for(;j<11;j++){
  a[i]=j;
  dfs2(i+1,k-exp(a[i]*x[0]));
 }
}
bool cmp(int i,int j){
 return l[i]<l[j];
}
void solve(){
 s=0;
 dfs1(0,0);
 int i;
 for(i=0;i<s;i++)id[i]=i;
 sort(id,id+s,cmp);
 ans=false;
 dfs2(5,y[0]);
}
int main(){
 cin>>n;
 int i;
 for(i=0;i<n;i++)cin>>x[i]>>y[i];
 solve();
 return 0;
}



