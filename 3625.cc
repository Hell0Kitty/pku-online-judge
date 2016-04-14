#include <iostream>
#include <math.h>
#include <cstdio>
#define MAX 100000000
using namespace std;
double a[1001][1001],w[1001];
bool b[1001];
double x[1001],y[1001];
int n;
void Prim(){
 int i,j,t;
 double tmp,len=0;
 for(i=1;i<=n;i++)
 {
 w[i]=a[1][i];
 b[i]=false;
 }
 b[1]=true;
 for(i=2;i<=n;i++)
 {
 t=1;
 tmp=MAX;
 for(j=2;j<=n;j++)
 {
 if(!b[j]&&w[j]<tmp)
 {
 t=j;
 tmp=w[j];
 }
 }
 len+=tmp;
 b[t]=true;
 for(j=2;j<=n;j++)
 {
 if(!b[j]&&w[j]>a[t][j])
 w[j]=a[t][j];
 }
 }
 printf("%.2f\n",len);

}
int main()
{
 int m,i,j;
 scanf("%d%d",&n,&m);
 for(i=1;i<=n;i++)
 cin>>x[i]>>y[i];
 for(i=1;i<=n;i++)
 for(j=1;j<=i;j++)
 {
 a[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
 a[j][i]=a[i][j];
 }
 while(m--)
 {
 scanf("%d%d",&i,&j);
 a[i][j]=0;
 a[j][i]=0;
 }
 Prim();
 return 0;
}


