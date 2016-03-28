#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#include<iostream>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;
typedef long long LL;
const int N=2000;
const double eps=1e-7;

double x[N],y[N],r[N];
bool kind=false;
double lu=1000,ru=1000;
int ki[N],n;

void dfs(int v){
  double t;

  ki[v]=1;
  if(y[v]<r[v]-eps)kind=true;
  if(x[v]<r[v]-eps){
    t=sqrt(r[v]*r[v]-x[v]*x[v]);
    if(y[v]-t<lu)lu=y[v]-t;
  }
  if(1000-x[v]<r[v]-eps){
    t=1000-x[v];
    t=sqrt(r[v]*r[v]-t*t);
    if(y[v]-t<ru)ru=y[v]-t;
  }
  FOR(i,1,n){
    if(!ki[i])
    if( sqrt((x[v]-x[i])*(x[v]-x[i])+(y[v]-y[i])*(y[v]-y[i]))<r[v]+r[i]-eps )
    dfs(i);
  }
}

int main(){
  scanf("%d",&n);
  FOR(i,1,n){
    scanf("%lf%lf%lf",&x[i],&y[i],&r[i]);
  }

  FOR(i,1,n){
    if(1000-y[i]<r[i]-eps)dfs(i);
  }
  if(!kind)printf("Bill enters at (0.00, %.2f) and leaves at (1000.00, %.2f).\n",lu,ru);
  else printf("Bill will be bitten.\n");

}



